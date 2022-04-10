#include "Character/Enemy.h"

Enemy::Enemy(GLint level, GLint exp)
	:Character(level, exp)
{
	this->m_isEnemy = true;
}

Enemy::~Enemy()
{
}

