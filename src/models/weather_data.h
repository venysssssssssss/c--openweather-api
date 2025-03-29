#pragma once
#include <string>  // Add this line to fix the errors

class WeatherData {
public:
    // Default constructor
    WeatherData() : temperature(0.0f), humidity(0.0f) {}
    
    // Constructor with parameters
    WeatherData(float temperature, float humidity, const std::string& description);
    
    // Getters
    float getTemperature() const;
    float getHumidity() const;
    std::string getDescription() const;
    
    // Setters
    void setTemperature(float temp);
    void setHumidity(float hum);
    void setDescription(const std::string& desc);
    
private:
    float temperature;
    float humidity;
    std::string description;
};