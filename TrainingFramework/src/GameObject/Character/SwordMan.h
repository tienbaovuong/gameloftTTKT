#pragma once
#include "Ally.h"
class SwordMan :
    public Ally
{
public:
    SwordMan(){}
    SwordMan(GLint level, GLint exp);
    ~SwordMan();

    bool isEquippable(std::shared_ptr<Item> equipment) override;
};

