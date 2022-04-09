#pragma once
#include "MapSquare.h"
class Castle :
    public MapSquare
{
public:
    Castle() : MapSquare() {}
    Castle(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture);
    ~Castle();
};

