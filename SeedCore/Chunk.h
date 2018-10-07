#pragma once
#ifndef _CHUNKSTORAGE
#include <vector>
struct Coord
{
    long int X; // -2147483647 <-> 2147483647 
    long int Y; // -2147483647 <-> 2147483647
};

struct Object
{
    std::vector<int> Verts; // Vertices for the object.
    Coord objcoords;        // Relative to Current Chunk.
};

struct Chunk
{
    Coord coords;
    std::vector<Object> objects;
};
struct World
{
    std::vector<Chunk> chunks;
};
#endif // !_CHUNK
