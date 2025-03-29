#pragma once
#include <string>
#include <vector>
#include <utility> // for std::pair

class WeatherData {
public:
    // Struct to store historical temperature data
    struct HistoricalTemp {
        std::string date;
        float min;
        float max;
        float avg;
    };
    
    // Default constructor
    WeatherData() : temperature(0.0f), humidity(0.0f), feelsLike(0.0f), windSpeed(0.0f) {}
    
    // Constructor with parameters
    WeatherData(float temperature, float humidity, const std::string& description,
                float feelsLike = 0.0f, float windSpeed = 0.0f);
    
    // Getters
    float getTemperature() const;
    float getHumidity() const;
    std::string getDescription() const;
    float getFeelsLike() const;
    float getWindSpeed() const;
    const std::vector<HistoricalTemp>& getHistoricalTemps() const;
    
    // Setters
    void setTemperature(float temp);
    void setHumidity(float hum);
    void setDescription(const std::string& desc);
    void setFeelsLike(float feels);
    void setWindSpeed(float speed);
    void addHistoricalTemp(const HistoricalTemp& histTemp);
    
private:
    float temperature;
    float humidity;
    std::string description;
    float feelsLike;
    float windSpeed;
    std::vector<HistoricalTemp> historicalTemps;
};