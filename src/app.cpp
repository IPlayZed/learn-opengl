//
// Created by minef on 2/6/21.
//
#define GLFW_INCLUDE_NONE

#include <iostream>
#include "../deps/glad/include/glad/glad.h"
#include "GLFW/glfw3.h"
#include "../include/app.h"
#include "../include/render.h"
#include "../include/shader.h"

namespace App {
    void error_callback(int err, const char *desc) {
        fprintf(stderr, "Error: %s\n", desc);
    }

    void framebuffer_size_callback(GLFWwindow *, int width, int height) {
        glViewport(0, 0, width, height);
    }

    void process_input(GLFWwindow *glfWwindow) {
        if (glfwGetKey(glfWwindow, GLFW_KEY_ESCAPE) == GLFW_PRESS or glfwGetKey(glfWwindow, GLFW_KEY_E) == GLFW_PRESS) {
            glfwSetWindowShouldClose(glfWwindow, true);
        }
    }

    int start_application(float *vertices) {

        glfwSetErrorCallback(App::error_callback);
        if (!glfwInit()) {
            return -1;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        GLFWwindow *glfWwindow = glfwCreateWindow(960, 540, "Probe", nullptr, nullptr);
        if (glfWwindow == nullptr) {
            std::cerr << "GLFW window failed to initialize!\n";
            glfwTerminate();
            return -2;
        }

        glfwMakeContextCurrent(glfWwindow);

        if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
            std::cerr << "GLAD failed to initialize\n";
            return -3;
        }

        /*
         * This function provides the data for OpenGL to make the transformation from normalized device coordinates to window coordinates.
         * 1. and 2. parameters are between -1 and 1. These are the normalized device coordinates. (x and y.)
         * The 1. and 2. params are translated to window coordinates, in pixels, or so to say to the viewport.
         * The 3. and 4. parameters are the maximum width and height of the viewport in pixels, naturally.
         * This implicates that we do not have to have the same size of the window for the viewport and we could also render outside of it.
         * The mapping if width is 960px and height is 540px maps (-1,1) to (0,960) and (-1,1) to (0,540).
         */
        glViewport(0, 0, 960, 540);

        /*
         * Ensure that viewport in set to window size when GLFW window is resized.
         */
        glfwSetWindowSizeCallback(glfWwindow, App::framebuffer_size_callback);

        /*
         * Render loop.
         */
        int buffer_num = 1;
        auto *VBO = Render::gen_VBO_buffer(buffer_num);
        std::string vertex_shader = read_shader("./shaders/vertex_shader.glsl");
        while (!glfwWindowShouldClose(glfWwindow)) {
            //We first process the inputs.
            App::process_input(glfWwindow);

            //Do the rendering.
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            Render::gen_VBOs(buffer_num, VBO);
            glBindBuffer(GL_ARRAY_BUFFER, *VBO);
            glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

            //Swap the back and front render buffers.
            glfwSwapBuffers(glfWwindow);
            //Process events and call the callback function for those which it should.
            glfwPollEvents();
        }
        delete[] VBO;
        VBO = nullptr;

        return 0;
    }
}