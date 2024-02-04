CMAKE_MINIMUM_REQUIRED(VERSION 3.19)
SET(PROJECT_NAME 3DCurves)
PROJECT(${PROJECT_NAME})
SET(CMAKE_CXX_STANDARD 17)

add_subdirectory(model)

add_executable(${PROJECT_NAME} main.cc)

target_include_directories(${PROJECT_NAME} PUBLIC model)
target_link_libraries(${PROJECT_NAME} PUBLIC curves)
