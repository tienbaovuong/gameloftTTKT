#pragma once
#include "Consumable.h"
class Food :
    public Consumable
{
public:
    Food(){}
    Food(GLint durability);
    ~Food();

    void effect(std::shared_ptr<Character> other) override;
};

