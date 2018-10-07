#pragma once
#ifndef _SHADERLOADER
#include <vector>
enum shadertype {
    Fragment = 1,
    Vertex
};
struct RendProgram {
    unsigned int Program;
};
std::vector<RendProgram> Programs;
#endif // !_SHADERLOADER
