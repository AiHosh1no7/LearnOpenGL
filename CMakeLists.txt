cmake_minimum_required(VERSION 3.25)
project(LearnOpenGL)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/include)

find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)
find_package(glad REQUIRED)
find_package(assimp REQUIRED)

add_executable(Cubemaps
        ${PROJECT_SOURCE_DIR}/src/Cubemaps/main.cpp
        ${PROJECT_SOURCE_DIR}/src/glad.c)
target_link_libraries(Cubemaps PRIVATE glfw)
target_link_libraries(Cubemaps PRIVATE assimp::assimp)

add_executable(Advanced_GLSL
        ${PROJECT_SOURCE_DIR}/src/Advanced_GLSL/main.cpp
        ${PROJECT_SOURCE_DIR}/src/glad.c)
target_link_libraries(Advanced_GLSL PRIVATE glfw)
target_link_libraries(Advanced_GLSL PRIVATE assimp::assimp)

add_executable(Geometry_Shader_1
        ${PROJECT_SOURCE_DIR}/src/Geometry_Shader/main_houses.cpp
        ${PROJECT_SOURCE_DIR}/src/glad.c)
target_link_libraries(Geometry_Shader_1 PRIVATE glfw)
target_link_libraries(Geometry_Shader_1 PRIVATE assimp::assimp)

add_executable(Geometry_Shader_2
        ${PROJECT_SOURCE_DIR}/src/Geometry_Shader/main_explode.cpp
        ${PROJECT_SOURCE_DIR}/src/glad.c)
target_link_libraries(Geometry_Shader_2 PRIVATE glfw)
target_link_libraries(Geometry_Shader_2 PRIVATE assimp::assimp)

add_executable(InstancingForms
        ${PROJECT_SOURCE_DIR}/src/Instancing/main_form.cpp
        ${PROJECT_SOURCE_DIR}/src/glad.c)
target_link_libraries(InstancingForms PRIVATE glfw)
target_link_libraries(InstancingForms PRIVATE assimp::assimp)

add_executable(InstancingPlanet
        ${PROJECT_SOURCE_DIR}/src/Instancing/main_planet.cpp
        ${PROJECT_SOURCE_DIR}/src/glad.c)
target_link_libraries(InstancingPlanet PRIVATE glfw)
target_link_libraries(InstancingPlanet PRIVATE assimp::assimp)