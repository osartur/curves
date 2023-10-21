add_subdirectory(andronaut)

cmake_minimum_required(VERSION 3.6.0)
project(ChaikinMethod)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Release)

include_directories(
    "${PROJECT_SOURCE_DIR}/src/"
    "${PROJECT_SOURCE_DIR}/andronaut/include/"
)

file(GLOB SRC_FILES "${PROJECT_SOURCE_DIR}/src/*.cpp")

#Cxxdroid-binary: curves.bin
add_executable(curves.bin ${SRC_FILES})
target_link_libraries(curves.bin "${PROJECT_SOURCE_DIR}/andronaut/libandronaut.a")
find_package(SDL2 REQUIRED)
target_link_libraries(curves.bin ${SDL2_LIBRARIES})