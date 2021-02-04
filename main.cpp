#define GLFW_INCLUDE_NONE

#include <iostream>
#include "deps/src/glad/include/glad/glad.h"
#include "deps/src/glfw/glfw-3.3.2/include/GLFW/glfw3.h"

void error_callback(int err, const char *desc) {
    fprintf(stderr, "Error: %s\n", desc);
}

int main() {
    //TODO: restructure project so glad can be added as a CMake subdir (probably clone source?)
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cerr << "GLAD failed to initialize\n";
        return -1;
    }

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *glfWwindow = glfwCreateWindow(960, 540, "Probe", NULL, NULL);
    if (glfWwindow == NULL) {
        std::cerr << "GLFW window failed to initialize!\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(glfWwindow);

    return 0;
}
