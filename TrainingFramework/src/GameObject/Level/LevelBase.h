#pragma once
#include "GameConfig.h"
#include "utilities.h"
#include <Character.h>

class Character;
class LevelBase
{
public:
	LevelBase(){}
	LevelBase(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture);
	~LevelBase();

	std::list<std::shared_ptr<Character>> m_enemyList;

};

