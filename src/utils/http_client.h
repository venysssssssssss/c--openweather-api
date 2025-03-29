#pragma once

#include <string>
#include <curl/curl.h>  // Include curl header

class HttpClient {
public:
    HttpClient();
    ~HttpClient();
    std::string get(const std::string& url);

private:
    CURL* curl;  // Add curl as a member variable
    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp);
};