#pragma once
#include "Staffs.h"
class HealingStaff :
    public Staffs
{
public:
    HealingStaff(){}
    HealingStaff(GLint durability);
    ~HealingStaff();

    void effect(std::shared_ptr<Character> other) override;
};

