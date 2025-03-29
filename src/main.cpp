#include <iostream>
#include <string>
#include "api/weather_api.h"

int main() {
    std::string apiKey;
    std::cout << "Enter your OpenWeatherMap API key: ";
    std::getline(std::cin, apiKey);
    
    // If no API key provided, inform user
    if (apiKey.empty()) {
        std::cerr << "Error: An API key is required to use this application." << std::endl;
        std::cerr << "Please get a free API key from https://openweathermap.org/api" << std::endl;
        return 1;
    }
    
    WeatherAPI weatherApi(apiKey);
    
    std::string location;
    std::cout << "Enter a location (city name or city,country code): ";
    std::getline(std::cin, location);
    
    try {
        WeatherData weatherData = weatherApi.fetchWeather(location);
        
        std::cout << "\nWeather for " << location << ":\n";
        std::cout << "Temperature: " << weatherData.getTemperature() << "°C\n";
        std::cout << "Humidity: " << weatherData.getHumidity() << "%\n";
        std::cout << "Conditions: " << weatherData.getDescription() << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}