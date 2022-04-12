#pragma once
#include "Item.h"
class Axe :
    public Item
{
public:
    Axe(){}
    Axe(GLint durability);
    ~Axe();

    void effect(std::shared_ptr<Character> other) override;
};

