#pragma once
#include "Sword.h"
class IronSword :
    public Sword
{
public:
    IronSword(){}
    IronSword(GLint durability);
    ~IronSword();
};

