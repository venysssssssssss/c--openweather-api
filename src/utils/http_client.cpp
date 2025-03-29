#include "http_client.h"
#include <iostream>
#include <stdexcept>

HttpClient::HttpClient() {
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (!curl) {
        throw std::runtime_error("Failed to initialize CURL");
    }
}

HttpClient::~HttpClient() {
    if (curl) {
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}

size_t HttpClient::WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp) {
    userp->append(static_cast<char*>(contents), size * nmemb);
    return size * nmemb;
}

std::string HttpClient::get(const std::string& url) {
    std::string response;
    
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        
        CURLcode res = curl_easy_perform(curl);
        
        if (res != CURLE_OK) {
            std::string errorMsg = "curl_easy_perform() failed: ";
            errorMsg += curl_easy_strerror(res);
            throw std::runtime_error(errorMsg);
        }
        
        long httpCode = 0;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
        if (httpCode != 200) {
            std::string errorMsg = "HTTP error: " + std::to_string(httpCode) + "\nResponse: " + response;
            throw std::runtime_error(errorMsg);
        }
    } else {
        throw std::runtime_error("CURL not initialized");
    }
    
    return response;
}