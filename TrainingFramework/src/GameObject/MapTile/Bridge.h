#pragma once
#include "MapSquare.h"
class Bridge :
    public MapSquare
{
    public:
    Bridge() : MapSquare() {}
    Bridge(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture);
    ~Bridge();
};

