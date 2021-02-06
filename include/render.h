//
// Created by minef on 2/6/21.
//

#pragma once //LEARNOPENGL_RENDER_H

#include "../deps/glad/include/glad/glad.h"
#include "GLFW/glfw3.h"
#include "app.h"

namespace Render {
    /***
    * Generates vertex buffer objects into the given buffer.
    * @param num_of_buffers Number of buffer objects to be created.
    * @param buffer Buffer to hold the to-be generated VBOs. Must point to an array with enough space allocated.
    */
    void gen_VBOs(int VBO_num, App::GLUIPTR buffer);

    /***
    * Creates and returns a buffer to facilitate VBOs in it.
    * @param VBO_num Size of the buffer, must be at least as big as the number of VBOs to be generated into the buffer.
    * @return Pointer to the dynamically generated buffer.
    */
    App::GLUIPTR gen_VBO_buffer(int VBO_num);
}

