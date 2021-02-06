//
// Created by minef on 2/6/21.
//

#include <iostream>
#include "../deps/glad/include/glad/glad.h"
#include "../include/app.h"
#include "../include/render.h"

namespace Render {
    void gen_VBOs(int VBO_num, App::GLUIPTR buffer) {
        glGenBuffers(VBO_num, buffer);
    }

    App::GLUIPTR gen_VBO_buffer(int VBO_num) {
        return new GLuint[VBO_num];
    }
}

