#define GLFW_INCLUDE_NONE

#include <iostream>
#include "deps/src/glad/include/glad/glad.h"
#include "deps/src/glfw/glfw-3.3.2/include/GLFW/glfw3.h"

void error_callback(int err, const char *desc) {
    fprintf(stderr, "Error: %s\n", desc);
}

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    return 0;
}
