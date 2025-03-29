#include "weather_data.h"
#include <string>

WeatherData::WeatherData(float temperature, float humidity, const std::string& description,
                         float feelsLike, float windSpeed)
    : temperature(temperature), humidity(humidity), description(description),
      feelsLike(feelsLike), windSpeed(windSpeed) {}

float WeatherData::getTemperature() const {
    return temperature;
}

float WeatherData::getHumidity() const {
    return humidity;
}

std::string WeatherData::getDescription() const {
    return description;
}

float WeatherData::getFeelsLike() const {
    return feelsLike;
}

float WeatherData::getWindSpeed() const {
    return windSpeed;
}

const std::vector<WeatherData::HistoricalTemp>& WeatherData::getHistoricalTemps() const {
    return historicalTemps;
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

void WeatherData::setFeelsLike(float feels) {
    feelsLike = feels;
}

void WeatherData::setWindSpeed(float speed) {
    windSpeed = speed;
}

void WeatherData::addHistoricalTemp(const HistoricalTemp& histTemp) {
    historicalTemps.push_back(histTemp);
}