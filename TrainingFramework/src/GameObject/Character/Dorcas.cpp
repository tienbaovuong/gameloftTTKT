#include "Dorcas.h"

Dorcas::Dorcas(GLint level, GLint exp)
	:Warrior(level, exp)
{
	this->SetTexture(AssetManager::GetInstance()->DorcasFace);
	this->secondFace = std::make_shared<Sprite2D>(AssetManager::GetInstance()->model2D, AssetManager::GetInstance()->shaderTexture, AssetManager::GetInstance()->DorcasFace2);
	this->m_name = "Dorcas";
	this->m_maxHealthPoint = 19;
	this->m_strength = 6;
	this->m_defense = 6;
	this->m_magic = 0;
	this->m_resistance = 0;

	this->m_hpGrwth = 1.2;
	this->m_strGrwth = 1.2;
	this->m_defGrwth = 0.8;
	this->m_magGrwth = 0;
	this->m_resGrwth = 0;
	calculateStat();
	this->fieldAnimation = std::make_shared<SpriteAnimation>(AssetManager::GetInstance()->model2D, AssetManager::GetInstance()->shaderAnimation, AssetManager::GetInstance()->DorcasField, 3, 4, 0, 0.3f);
	
}

Dorcas::~Dorcas()
{
}
