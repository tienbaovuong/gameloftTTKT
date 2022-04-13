#include "Serra.h"

Serra::Serra(GLint level, GLint exp)
	:Priest(level, exp)
{
	this->SetTexture(AssetManager::GetInstance()->SerraFace);
	this->secondFace = std::make_shared<Sprite2D>(AssetManager::GetInstance()->model2D, AssetManager::GetInstance()->shaderTexture, AssetManager::GetInstance()->SerraFace2);
	this->m_name = "Serra";
	this->m_maxHealthPoint = 15;
	this->m_strength = 2;
	this->m_defense = 4;
	this->m_magic = 9;
	this->m_resistance = 7;

	this->m_hpGrwth = 0.8;
	this->m_strGrwth = 0;
	this->m_defGrwth = 0.4;
	this->m_magGrwth = 1.2;
	this->m_resGrwth = 0.8;
	calculateStat();
	this->fieldAnimation = std::make_shared<SpriteAnimation>(AssetManager::GetInstance()->model2D, AssetManager::GetInstance()->shaderAnimation, AssetManager::GetInstance()->SerraField, 3, 4, 0, 0.3f);
}

Serra::~Serra()
{
}
