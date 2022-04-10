#pragma once
#include "Enemy.h"
class EnemyBanditHeader :
    public Enemy
{
public:
    EnemyBanditHeader() {}
    EnemyBanditHeader(GLint level, GLint exp);
    ~EnemyBanditHeader();

    bool isEquippable(std::shared_ptr<Item> equipment) override;
};

