#pragma once

//GLEW provides the function pointers we need to access the latest features in openGL.
#include <GL/glew.h>    //Must be included before gl.h and glfw.h.

//GLFW provides window creation and input control.
#include <glfw3.h>

//GLM provides openGL mathematics.
#include <glm/glm.hpp>

// for matrix
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//Standard Headers…
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <cassert>
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <fstream>
#include <string>

#pragma once

//Namespaces…
using namespace glm; //For openGL mathematics
using namespace std; //If we want to print stuff

//Defines…
#define GLFW_DLL
#define APP_NAME "<<Getting Started!>>"
#define EXIT_WITH_ERROR -1
#define EXIT_WITH_SUCCESS 0
#define OPEN_GL_VERSION 3  //Specifies OpenGL 3.3
#define ANTIALIASING 4  //nx antialiasing
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800
#define GLFW_FAIL 0 

//External Globals…
extern GLFWwindow* window;
extern GLint shaderStatus;
extern bool activeRef;

int InitWindowFailed();
GLuint LoadShaders(const char *vertex_file_path, const char *fragment_file_path);
int InitGlewFailed();
GLuint& LoadQuad();
GLuint& LoadCube();
GLuint& LoadTriangle();