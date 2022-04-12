#pragma once
#include "Item.h"
class Sword :
    public Item
{
public:
    Sword(){}
    Sword(GLint durability);
    ~Sword();

    void effect(std::shared_ptr<Character> other) override;
};

