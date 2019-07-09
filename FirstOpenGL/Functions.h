#pragma once
#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include <vector>
#include <map>
#include <glew.h>
#include <glfw3.h>
#include <SOIL.h>
#include <glm/gtx/rotate_vector.hpp>

#include "Shader.h"

using namespace glm;

bool IsAbroad(float areaWidth, float areaLong, float tankWidth, float tankLong, vec3 move, float angle);

void PassCoordsToVAO(GLuint VAO, GLuint VBO, GLuint EBO, GLfloat vertices[], GLuint indices[], GLint countOfV, GLint countOfI);
void LoadTexture(GLuint texture, const char* path);
void Draw(GLuint VAO, GLint countV);
void BindTexture(GLint blockOffset, GLuint texture, Shader shader);

#endif 
