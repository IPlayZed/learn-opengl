#include "../include/app.h"

int main() {
    float vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f, 0.5f, 0.0f
    };
    int app_state = App::start_application(vertices);
    return app_state;
}
