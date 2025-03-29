#pragma once

#include <string>
#include "../models/weather_data.h"

class WeatherAPI {
public:
    WeatherAPI(const std::string& apiKey);
    WeatherData fetchWeather(const std::string& location);

private:
    std::string apiKey;
    WeatherData parseResponse(const std::string& response);
};