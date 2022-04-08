#pragma once
#include "MapSquare.h"
class River :
    public MapSquare
{
public:
    River() : MapSquare() {}
    River(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture);
    ~River();
};

