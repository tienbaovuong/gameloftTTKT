#pragma once
#include "MapSquare.h"
class Chess :
    public MapSquare
{
public:
    Chess() : MapSquare() {}
    Chess(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture);
    ~Chess();
};

