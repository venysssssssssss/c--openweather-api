#include <gtest/gtest.h>
#include "../src/api/weather_api.h"

class WeatherApiTest : public ::testing::Test {
protected:
    WeatherAPI* weatherApi;

    void SetUp() override {
        weatherApi = new WeatherAPI();
    }

    void TearDown() override {
        delete weatherApi;
    }
};

TEST_F(WeatherApiTest, FetchWeather_ValidCity_ReturnsWeatherData) {
    std::string city = "London";
    WeatherData weatherData = weatherApi->fetchWeather(city);
    EXPECT_FALSE(weatherData.getTemperature().empty());
    EXPECT_FALSE(weatherData.getHumidity().empty());
    EXPECT_FALSE(weatherData.getDescription().empty());
}

TEST_F(WeatherApiTest, FetchWeather_InvalidCity_ReturnsEmptyData) {
    std::string city = "InvalidCity123";
    WeatherData weatherData = weatherApi->fetchWeather(city);
    EXPECT_TRUE(weatherData.getTemperature().empty());
    EXPECT_TRUE(weatherData.getHumidity().empty());
    EXPECT_TRUE(weatherData.getDescription().empty());
}