#pragma once
#include "Enemy.h"
class EnemyBandit :
    public Enemy
{
public:
    EnemyBandit(){}
    EnemyBandit(GLint level, GLint exp);
    ~EnemyBandit();

    bool isEquippable(std::shared_ptr<Item> equipment) override;
};

