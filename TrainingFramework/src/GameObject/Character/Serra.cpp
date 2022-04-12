#include "Serra.h"

Serra::Serra(GLint level, GLint exp)
	:Priest(level, exp)
{
	this->SetTexture(AssetManager::GetInstance()->SerraFace);
	this->secondFace = std::make_shared<Sprite2D>(AssetManager::GetInstance()->model2D, AssetManager::GetInstance()->shaderTexture, AssetManager::GetInstance()->SerraFace2);
	this->m_name = "Serra";
	this->m_maxHealthPoint = 1;
	this->m_strength = 1;
	this->m_defense = 1;
	this->m_magic = 1;
	this->m_resistance = 1;

	this->m_hpGrwth = 1;
	this->m_strGrwth = 1;
	this->m_defGrwth = 1;
	this->m_magGrwth = 0;
	this->m_resGrwth = 0;
	calculateStat();
	this->fieldAnimation = std::make_shared<SpriteAnimation>(AssetManager::GetInstance()->model2D, AssetManager::GetInstance()->shaderAnimation, AssetManager::GetInstance()->SerraField, 3, 4, 0, 0.3f);
}

Serra::~Serra()
{
}
