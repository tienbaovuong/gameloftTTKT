#pragma once
#include "MapSquare.h"
class NormalTree :
    public MapSquare
{
public:
    NormalTree() : MapSquare() {}
    NormalTree(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture);
    ~NormalTree();
};

