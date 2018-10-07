#pragma once
#ifndef _SETTING
#define _SETTING
// Uncap 60FPS.
#include <string>
bool VSyncCap = true;
char* VertShaderSrc = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
char* FragmentShaderSrc = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";
unsigned int VertBuff;
unsigned int VertShader;
unsigned int FragShader;
unsigned int VertArrObj;
float vertices[] = {
    -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    0.0f,  0.5f, 0.0f
};
unsigned int shaderProgram;
unsigned int VBO, VAO;
#endif // !_SETTING
