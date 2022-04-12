#pragma once
#include "Item.h"
class Consumable :
    public Item
{
public:
    Consumable(): Item(){}
    Consumable(GLint durability);
    ~Consumable();

    void effect(std::shared_ptr<Character> other) override;
};

