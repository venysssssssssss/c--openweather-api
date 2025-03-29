#include "weather_api.h"
#include "../utils/http_client.h"
#include <iostream>
#include <nlohmann/json.hpp>
#include <ctime>
#include <iomanip>
#include <sstream>

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
    
    std::cout << "Buscando dados meteorológicos atuais..." << std::endl;
    std::string response = client.get(url);
    
    // Parse the current weather data
    WeatherData weatherData = parseCurrentWeather(response);
    
    // From the current weather data, extract lat/lon for historical data
    auto jsonResponse = json::parse(response);
    double lat = jsonResponse["coord"]["lat"];
    double lon = jsonResponse["coord"]["lon"];
    
    // Fetch historical data
    std::cout << "Buscando dados históricos de temperatura..." << std::endl;
    fetchHistoricalData(weatherData, lat, lon);
    
    return weatherData;
}

WeatherData WeatherAPI::parseCurrentWeather(const std::string& response) {
    auto jsonResponse = json::parse(response);
    
    // OpenWeatherMap API structure
    float temp = jsonResponse["main"]["temp"];
    float humidity = jsonResponse["main"]["humidity"];
    float feelsLike = jsonResponse["main"]["feels_like"];
    float windSpeed = jsonResponse["wind"]["speed"];
    std::string description = jsonResponse["weather"][0]["description"];
    
    return WeatherData(temp, humidity, description, feelsLike, windSpeed);
}

void WeatherAPI::fetchHistoricalData(WeatherData& weatherData, double lat, double lon) {
    HttpClient client;
    
    // Usar a API de previsão de 5 dias (disponível no plano gratuito)
    std::string url = "https://api.openweathermap.org/data/2.5/forecast?lat=" + 
                       std::to_string(lat) + "&lon=" + std::to_string(lon) + 
                       "&appid=" + apiKey + "&units=metric";
    
    try {
        std::cout << "Buscando previsão para os próximos 5 dias..." << std::endl;
        std::string response = client.get(url);
        auto jsonResponse = json::parse(response);
        
        // Agrupar por dia (a API retorna dados em intervalos de 3 horas)
        std::map<std::string, WeatherData::HistoricalTemp> dailyData;
        
        for (const auto& item : jsonResponse["list"]) {
            // Obter a data do campo dt_txt (formato: "2023-03-29 12:00:00")
            std::string dtTxt = item["dt_txt"];
            std::string dateStr = dtTxt.substr(0, 10);
            
            float temp = item["main"]["temp"];
            
            if (dailyData.find(dateStr) == dailyData.end()) {
                WeatherData::HistoricalTemp newData;
                newData.date = dateStr;
                newData.min = temp;
                newData.max = temp;
                newData.avg = temp;
                dailyData[dateStr] = newData;
            } else {
                auto& entry = dailyData[dateStr];
                entry.min = std::min(entry.min, temp);
                entry.max = std::max(entry.max, temp);
                // Atualizar a média (simplificado)
                entry.avg = (entry.avg + temp) / 2.0f;
            }
        }
        
        // Adicionar os dados diários ao objeto WeatherData
        for (const auto& [date, tempData] : dailyData) {
            weatherData.addHistoricalTemp(tempData);
        }
    } catch (const std::exception& e) {
        std::cerr << "Aviso: Não foi possível obter dados de previsão: " << e.what() << std::endl;
    }
}

std::string WeatherAPI::formatDate(const std::time_t& timestamp) {
    std::tm* timeinfo = std::localtime(&timestamp);
    std::ostringstream oss;
    oss << std::put_time(timeinfo, "%d/%m/%Y");
    return oss.str();
}