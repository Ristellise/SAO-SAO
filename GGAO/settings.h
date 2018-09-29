#pragma once
#ifndef _SETTING
#define _SETTING
// Uncap 60FPS.
#include <string>
bool VSyncCap = true;
const char* VertShaderSrc = "#version 330 core\n layout(location = 0) in vec3 aPos; void main(){gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);}";
char* FragmentShaderSrc = "#version 330 core\n out vec4 FragColor; void main(){FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);}";
unsigned int VertBuff;
unsigned int VertShader;
unsigned int FragShader;
unsigned int VertArrObj;
float vertices[] = {
    -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    0.0f,  0.5f, 0.0f
};
#endif // !_SETTING
