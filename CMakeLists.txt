cmake_minimum_required(VERSION 3.25)
project(sierpinski_triangle_generator)

set(CMAKE_CXX_STANDARD 20)

add_executable(sierpinski_triangle_generator main.cpp linear_interpolation.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS audio graphics network system window REQUIRED)

include_directories(C:/SFML/include)
target_link_libraries(sierpinski_triangle_generator sfml-audio sfml-graphics sfml-network sfml-system sfml-window)
