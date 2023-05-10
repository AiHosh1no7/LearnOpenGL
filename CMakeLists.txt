cmake_minimum_required(VERSION 3.25)
project(LearnOpenGL)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/include)

find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)
find_package(glad REQUIRED)
find_package(assimp REQUIRED)

add_executable(Cubemaps ${PROJECT_SOURCE_DIR}/src/Cubemaps/main.cpp ${PROJECT_SOURCE_DIR}/src/glad.c)
target_link_libraries(Cubemaps PRIVATE glfw)
target_link_libraries(Cubemaps PRIVATE assimp::assimp)

add_executable(Advanced_GLSL ${PROJECT_SOURCE_DIR}/src/Advanced_GLSL/main.cpp ${PROJECT_SOURCE_DIR}/src/glad.c)
target_link_libraries(Advanced_GLSL PRIVATE glfw)
target_link_libraries(Advanced_GLSL PRIVATE assimp::assimp)