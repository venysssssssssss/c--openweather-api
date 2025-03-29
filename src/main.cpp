#include <iostream>
#include <string>
#include "api/weather_api.h"
#include <iomanip>

int main() {
    std::string apiKey;
    std::cout << "Digite sua chave de API do OpenWeatherMap: ";
    std::getline(std::cin, apiKey);
    
    // If no API key provided, inform user
    if (apiKey.empty()) {
        std::cerr << "Erro: Uma chave de API é necessária para usar este aplicativo." << std::endl;
        std::cerr << "Por favor, obtenha uma chave de API gratuita em https://openweathermap.org/api" << std::endl;
        return 1;
    }
    
    WeatherAPI weatherApi(apiKey);
    std::string location;
    bool continueRunning = true;
    
    while (continueRunning) {
        std::cout << "\nDigite uma localização (nome da cidade ou cidade,código do país): ";
        std::cout << "\n(ou digite 'sair' para encerrar o programa): ";
        std::getline(std::cin, location);
        
        // Check if user wants to exit
        if (location == "sair" || location == "Sair" || location == "SAIR") {
            continueRunning = false;
            std::cout << "Encerrando o programa. Obrigado por usar!" << std::endl;
            break;
        }
        
        try {
            WeatherData weatherData = weatherApi.fetchWeather(location);
            
            std::cout << "\n=== Clima atual para " << location << " ===\n";
            std::cout << "Temperatura: " << weatherData.getTemperature() << "°C\n";
            std::cout << "Sensação térmica: " << weatherData.getFeelsLike() << "°C\n";
            std::cout << "Umidade: " << weatherData.getHumidity() << "%\n";
            std::cout << "Velocidade do vento: " << weatherData.getWindSpeed() << " m/s\n";
            std::cout << "Condições: " << weatherData.getDescription() << std::endl;
            
            // Display historical data if available
            const auto& historicalTemps = weatherData.getHistoricalTemps();
            if (!historicalTemps.empty()) {
                std::cout << "\n=== Histórico de temperatura dos últimos 5 dias ===\n";
                std::cout << "Data       | Min (°C) | Max (°C) | Média (°C)\n";
                std::cout << "-----------------------------------------------\n";
                
                for (const auto& hist : historicalTemps) {
                    std::cout << hist.date << " | " 
                              << std::fixed << std::setprecision(1) << hist.min << "     | " 
                              << hist.max << "     | " 
                              << hist.avg << std::endl;
                }
            }
            
            // Ask if user wants to check another location
            std::cout << "\nDeseja verificar o clima de outra localização? (s/n): ";
            std::string response;
            std::getline(std::cin, response);
            
            if (response != "s" && response != "S" && response != "sim" && response != "Sim") {
                continueRunning = false;
                std::cout << "Encerrando o programa. Obrigado por usar!" << std::endl;
            }
            
        } catch (std::exception& e) {
            std::cerr << "Erro: " << e.what() << std::endl;
            std::cout << "Deseja tentar novamente? (s/n): ";
            std::string response;
            std::getline(std::cin, response);
            
            if (response != "s" && response != "S" && response != "sim" && response != "Sim") {
                continueRunning = false;
                std::cout << "Encerrando o programa. Obrigado por usar!" << std::endl;
            }
        }
    }
    
    return 0;
}