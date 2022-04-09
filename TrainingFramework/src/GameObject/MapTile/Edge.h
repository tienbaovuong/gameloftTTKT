#pragma once
#include "MapSquare.h"
class Edge :
    public MapSquare
{
public:
    Edge() : MapSquare() {}
    Edge(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture);
    ~Edge();
};

