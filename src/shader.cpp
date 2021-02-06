//
// Created by minef on 2/6/21.
//
#include <iostream>
#include <fstream>
#include "../include/shader.h"

std::string read_shader(const char *filename) {
    std::ifstream input;
    input.open(filename);
    if (!input.good()) {
        std::cerr << "Shader " + std::string(filename) + " failed to load!";
        exit(-4);
    }
    std::string str;
    while (std::getline(input, str)) {
        std::cout << str;
    }
    std::string returnable = std::string(std::istreambuf_iterator<char>(input), std::istreambuf_iterator<char>());
    input.close();
    return returnable;
}