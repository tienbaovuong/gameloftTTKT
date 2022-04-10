#pragma once
#include "Character.h"
class Ally :
    public Character
{
public:
    Ally(){}
    Ally(GLint level, GLint exp);
    ~Ally();

    virtual bool isEquippable(std::shared_ptr<Item> equipment) = 0;
};

