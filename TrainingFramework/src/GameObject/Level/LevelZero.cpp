#include "Level/LevelZero.h"


LevelZero::LevelZero(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture)
{
	std::shared_ptr<Character> enemy = std::make_shared<Character>(model, shader, texture);
	m_enemyList.push_back(enemy);
}

LevelZero::~LevelZero()
{
}
