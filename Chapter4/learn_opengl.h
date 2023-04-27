//
// Created by h1tor on 2023/4/18.
//

#ifndef LEARNOPENGL_LEARN_OPENGL_H
#define LEARNOPENGL_LEARN_OPENGL_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow *window);
unsigned int loadTexture(char const * path);
unsigned int loadCubemap(vector<std::string> faces);

#endif //LEARNOPENGL_LEARN_OPENGL_H
