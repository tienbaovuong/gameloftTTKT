#pragma once
#include "MapSquare.h"
class Ground :
    public MapSquare
{
public:
    Ground() : MapSquare() {}
    Ground(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture);
    ~Ground();
};

