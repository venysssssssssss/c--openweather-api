#include "weather_api.h"
#include "../utils/http_client.h"
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

WeatherAPI::WeatherAPI(const std::string& apiKey) : apiKey(apiKey) {}

WeatherData WeatherAPI::fetchWeather(const std::string& location) {
    HttpClient client;
    
    // This is the OpenWeatherMap API URL format
    std::string encodedLocation = location;
    // Replace spaces with %20 for URL encoding
    size_t pos = 0;
    while ((pos = encodedLocation.find(" ", pos)) != std::string::npos) {
        encodedLocation.replace(pos, 1, "%20");
        pos += 3;
    }
    
    std::string url = "https://api.openweathermap.org/data/2.5/weather?q=" + encodedLocation + 
                      "&appid=" + apiKey + "&units=metric";
    
    std::cout << "Fetching weather data from: " << url << std::endl;
    std::string response = client.get(url);
    return parseResponse(response);
}

WeatherData WeatherAPI::parseResponse(const std::string& response) {
    auto jsonResponse = json::parse(response);
    
    // OpenWeatherMap API structure
    float temp = jsonResponse["main"]["temp"];
    float humidity = jsonResponse["main"]["humidity"];
    std::string description = jsonResponse["weather"][0]["description"];
    
    return WeatherData(temp, humidity, description);
}