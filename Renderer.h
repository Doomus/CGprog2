#pragma once

#include "Init.h"

void BeginRendering();

void RenderVertex(GLuint vertexBuffer, GLuint programID /*shader program id*/, glm::mat4 model);
void RenderQuad(GLuint vertexBuffer, GLuint programID, glm::mat4 model);
void RenderTriangle(GLuint vertexBuffer, GLuint programID, glm::mat4 model);
void RenderCube(GLuint vertexBuffer, GLuint programID, glm::mat4 model);