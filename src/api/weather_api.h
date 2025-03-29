#pragma once

#include <string>
#include <ctime>
#include "../models/weather_data.h"

class WeatherAPI {
public:
    WeatherAPI(const std::string& apiKey);
    WeatherData fetchWeather(const std::string& location);

private:
    std::string apiKey;
    WeatherData parseCurrentWeather(const std::string& response);
    void fetchHistoricalData(WeatherData& weatherData, double lat, double lon);
    std::string formatDate(const std::time_t& timestamp);
};