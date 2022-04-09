#include "Level/LevelZero.h"


LevelZero::LevelZero(std::shared_ptr<Model> model)
	:LevelBase()
{
	auto enemy = std::make_shared<Character>(model);
	m_enemyList.push_back(enemy);
}

LevelZero::~LevelZero()
{
}
