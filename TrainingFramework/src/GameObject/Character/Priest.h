#pragma once
#include "Ally.h"
class Priest :
    public Ally
{
public:
    Priest() {}
    Priest(GLint level, GLint exp);
    ~Priest();

    bool isEquippable(std::shared_ptr<Item> equipment) override;
};

