# Weather API C++ Project

This project is a C++ application that consumes a weather API to fetch and display weather data. It is structured to separate concerns into different modules, making it easier to maintain and extend.

## Project Structure

```
weather-api-cpp
├── src
│   ├── main.cpp               # Entry point of the application
│   ├── api
│   │   ├── weather_api.cpp    # Implementation of the WeatherAPI class
│   │   └── weather_api.h      # Declaration of the WeatherAPI class
│   ├── models
│   │   ├── weather_data.cpp    # Implementation of the WeatherData class
│   │   └── weather_data.h      # Declaration of the WeatherData class
│   └── utils
│       ├── http_client.cpp     # Implementation of the HttpClient class
│       └── http_client.h       # Declaration of the HttpClient class
├── include
│   └── external
│       ├── json.hpp           # JSON parsing library
│       └── curl               # cURL library headers
├── tests
│   ├── api_tests.cpp          # Unit tests for the WeatherAPI class
│   └── model_tests.cpp        # Unit tests for the WeatherData class
├── .vscode
│   ├── launch.json            # Debugging configuration
│   └── tasks.json             # Build and run tasks
├── CMakeLists.txt             # CMake configuration file
└── README.md                  # Project documentation
```

## Setup Instructions

1. **Clone the Repository**
   Clone this repository to your local machine using:
   ```
   git clone <repository-url>
   ```

2. **Install Dependencies**
   Ensure you have the following dependencies installed:
   - CMake
   - cURL
   - A C++ compiler (e.g., g++, clang++)

3. **Build the Project**
   Navigate to the project directory and create a build directory:
   ```
   cd weather-api-cpp
   mkdir build
   cd build
   ```
   Run CMake to configure the project:
   ```
   cmake ..
   ```
   Build the project:
   ```
   make
   ```

4. **Run the Application**
   After building, you can run the application:
   ```
   ./main
   ```

## Usage

The application fetches weather data from a specified weather API. You can modify the API endpoint and parameters in the `weather_api.cpp` file to customize the data you want to retrieve.

## API Details

Refer to the documentation of the specific weather API you are using for details on the available endpoints, request parameters, and response formats.# c--openweather-api
