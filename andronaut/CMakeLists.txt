cmake_minimum_required(VERSION 3.6.0)
project(andronaut)

include_directories("${PROJECT_SOURCE_DIR}/include/")

file(GLOB SRC_FILES
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/graphics/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/math/*.cpp"
)

add_library(andronaut STATIC ${SRC_FILES})

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
target_link_libraries(andronaut ${SDL2_LIBRARIES} ${SDL2_TTF_LIBRARIES})