cmake_minimum_required(VERSION 4.0.2)
project(SpaceGame VERSION 0.1.0 LANGUAGES C CXX)

file(GLOB SOURCES "src/*")

file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/resources" DESTINATION ".")

add_subdirectory(include/raylib)

add_executable("${CMAKE_PROJECT_NAME}" ${SOURCES})

target_link_libraries("${CMAKE_PROJECT_NAME}" PRIVATE raylib)