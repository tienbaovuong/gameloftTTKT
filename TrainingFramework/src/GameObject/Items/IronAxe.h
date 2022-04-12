#pragma once
#include "Axe.h"
class IronAxe :
    public Axe
{
public: 
    IronAxe() {};
    IronAxe(GLint durability);
    ~IronAxe();
};

