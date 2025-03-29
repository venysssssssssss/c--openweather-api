#include <gtest/gtest.h>
#include "../src/models/weather_data.h"

TEST(WeatherDataTest, DefaultConstructor) {
    WeatherData data;
    EXPECT_EQ(data.getTemperature(), 0);
    EXPECT_EQ(data.getHumidity(), 0);
    EXPECT_EQ(data.getDescription(), "");
}

TEST(WeatherDataTest, ParameterizedConstructor) {
    WeatherData data(25.0, 60, "Clear");
    EXPECT_EQ(data.getTemperature(), 25.0);
    EXPECT_EQ(data.getHumidity(), 60);
    EXPECT_EQ(data.getDescription(), "Clear");
}

TEST(WeatherDataTest, SettersAndGetters) {
    WeatherData data;
    data.setTemperature(30.0);
    data.setHumidity(70);
    data.setDescription("Sunny");

    EXPECT_EQ(data.getTemperature(), 30.0);
    EXPECT_EQ(data.getHumidity(), 70);
    EXPECT_EQ(data.getDescription(), "Sunny");
}