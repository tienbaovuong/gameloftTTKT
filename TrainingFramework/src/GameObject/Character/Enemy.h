#pragma once
#include "Character.h"
class Enemy :
    public Character
{
public:
    Enemy(){}
    Enemy(GLint level, GLint exp);
    ~Enemy();

    virtual bool isEquippable(std::shared_ptr<Item> equipment) = 0;
};

