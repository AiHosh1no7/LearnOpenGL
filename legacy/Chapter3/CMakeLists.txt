cmake_minimum_required(VERSION 3.25)
project(LearnOpenGL_Ch3)

set(CMAKE_CXX_STANDARD 17)

find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)
find_package(glad REQUIRED)
find_package(assimp REQUIRED)

add_executable(LearnOpenGL_Ch3 main.cpp glad.c shader_m.h camera.h stb_image.cpp)

target_link_libraries(LearnOpenGL_Ch3 PRIVATE glfw)
target_link_libraries(LearnOpenGL_Ch3 PRIVATE assimp::assimp)