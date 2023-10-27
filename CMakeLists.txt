cmake_minimum_required(VERSION 3.5)

project(ping_pong VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)


file(GLOB CPPS "src/*.cpp")
include_directories("${PROJECT_SOURCE_DIR}/include")
add_executable(${PROJECT_NAME} ${CPPS})



#target_link_libraries(ping_pong nlohmann_json::nlohmann_json )





