cmake_minimum_required(VERSION 3.17)
project(learnopengl)

find_package(OpenGL REQUIRED)

set(CMAKE_CXX_STANDARD 20)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

#This is the source directory to GLFW source
add_subdirectory(./deps/src/glfw/glfw-3.3.2 ./deps/src/glad) #glad cmake project should be facilitated here
add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} glfw OpenGL::GL)