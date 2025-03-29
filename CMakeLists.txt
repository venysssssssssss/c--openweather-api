cmake_minimum_required(VERSION 3.10)
project(weather_api_cpp)

set(CMAKE_CXX_STANDARD 17)

# Find CURL package
find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIRS})

# Find nlohmann_json package
find_package(nlohmann_json 3.2.0 REQUIRED)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Source files
file(GLOB_RECURSE SOURCES
     "src/*.cpp"
     "src/api/*.cpp"
     "src/models/*.cpp"
     "src/utils/*.cpp")

# Create executable
add_executable(weather_app ${SOURCES})

# Link libraries
target_link_libraries(weather_app ${CURL_LIBRARIES} nlohmann_json::nlohmann_json)