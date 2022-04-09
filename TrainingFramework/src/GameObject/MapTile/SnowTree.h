#pragma once
#include "MapSquare.h"
class SnowTree :
    public MapSquare
{
public:
    SnowTree() : MapSquare() {}
    SnowTree(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture);
    ~SnowTree();
};

