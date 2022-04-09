#pragma once
#include "MapSquare.h"
class Camp :
    public MapSquare
{
public:
    Camp() : MapSquare() {}
    Camp(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture);
    ~Camp();
};

