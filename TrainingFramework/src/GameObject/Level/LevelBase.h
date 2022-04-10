#pragma once
#include "GameConfig.h"
#include "utilities.h"
#include <Character.h>
#include "Character/CharacterHeader.h"
//class Character;
class Ally;
class Enemy;
class LevelBase
{
public:
	LevelBase(){}
	~LevelBase();

	std::list<std::shared_ptr<Enemy>> m_enemyList;
	std::list<std::shared_ptr<Ally>> m_alliesList;
};

