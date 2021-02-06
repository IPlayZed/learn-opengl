//
// Created by minef on 2/6/21.
//

#pragma once //LEARNOPENGL_APP_H

#include "../deps/glad/include/glad/glad.h"
#include "GLFW/glfw3.h"

namespace App {
    typedef GLuint *GLUIPTR;

    void error_callback(int err, const char *desc);

    void framebuffer_size_callback(GLFWwindow *, int width, int height);

    void process_input(GLFWwindow *glfWwindow);

    int start_application(float *vertices);
}