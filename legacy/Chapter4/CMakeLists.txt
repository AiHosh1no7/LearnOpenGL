cmake_minimum_required(VERSION 3.25)
project(LearnOpenGL_Ch4)

set(CMAKE_CXX_STANDARD 17)

find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)
find_package(glad REQUIRED)
find_package(assimp REQUIRED)

add_executable(LearnOpenGL_Ch4 main.cpp glad.c shader_m.h camera.h stb_image.cpp Data.h learn_opengl.h main.cpp)

target_link_libraries(LearnOpenGL_Ch4 PRIVATE glfw)
target_link_libraries(LearnOpenGL_Ch4 PRIVATE assimp::assimp)