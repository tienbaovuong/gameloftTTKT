#pragma once
#include "GameConfig.h"
#include "utilities.h"
#include <Character.h>

class Character;
class LevelBase
{
public:
	LevelBase(){}
	~LevelBase();

	std::list<std::shared_ptr<Character>> m_enemyList;

};

