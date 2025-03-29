#include "weather_data.h"
#include <string>  // Add string include here too

WeatherData::WeatherData(float temperature, float humidity, const std::string& description)
    : temperature(temperature), humidity(humidity), description(description) {}

float WeatherData::getTemperature() const {
    return temperature;
}

float WeatherData::getHumidity() const {
    return humidity;
}

std::string WeatherData::getDescription() const {
    return description;
}

void WeatherData::setTemperature(float temp) {
    temperature = temp;
}

void WeatherData::setHumidity(float hum) {
    humidity = hum;
}

void WeatherData::setDescription(const std::string& desc) {
    description = desc;
}