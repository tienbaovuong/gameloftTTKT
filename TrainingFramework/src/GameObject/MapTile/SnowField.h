#pragma once
#include "MapSquare.h"
class SnowField :
    public MapSquare
{
public:
    SnowField(): MapSquare(){}
    SnowField(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture);
    ~SnowField();

};

