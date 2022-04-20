#pragma once
#include "GameConfig.h"
#include "utilities.h"
#include <Character.h>
#include "Character/CharacterHeader.h"
#include "Items/ItemHeader.h"
#include "LevelBaseBase.h"
//class Character;
class Ally;
class Enemy;
class LevelBase: 
	public LevelBaseBase
{
public:
	LevelBase(): LevelBaseBase() {}
	~LevelBase();

	std::list<std::shared_ptr<Enemy>> m_enemyList;
	std::list<std::shared_ptr<Ally>> m_alliesList;
	int startXPointer;
	int startYPointer;
	int xOffset;
	int yOffset;
	void update() override;
};

