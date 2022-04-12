#pragma once
#include "Item.h"
class Staffs :
    public Item
{
public:
    Staffs(){}
    Staffs(GLint durability);
    ~Staffs();

    void effect(std::shared_ptr<Character> other) override;
};

