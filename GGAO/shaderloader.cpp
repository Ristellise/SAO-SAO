#include <string>
#include <iostream>
#include <fstream>
const char * loadershader(std::string file,int type)
{
    char *res;
    std::string buff;
    std::ifstream starbuststream;
    starbuststream.open(file);
    if (starbuststream.is_open())
    {
        while (std::getline(starbuststream, buff))
        {
            *res += buff.c_str() + '\n';

        }
    }
}