#pragma once
#include "Ally.h"
class Warrior :
    public Ally
{
public:
    Warrior(){}
    Warrior(GLint level, GLint exp);
    ~Warrior();
    bool isEquippable(std::shared_ptr<Item> equipment) override;
};

