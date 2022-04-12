#include "Ike.h"

Ike::Ike(GLint level, GLint exp)
	:SwordMan(level, exp)
{
	this->SetTexture(AssetManager::GetInstance()->IkeFace);
	this->secondFace = std::make_shared<Sprite2D>(AssetManager::GetInstance()->model2D, AssetManager::GetInstance()->shaderTexture, AssetManager::GetInstance()->IkeFace2);
	this->m_name = "Ike";
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
	this->fieldAnimation = std::make_shared<SpriteAnimation>(AssetManager::GetInstance()->model2D, AssetManager::GetInstance()->shaderAnimation, AssetManager::GetInstance()->IkeField, 3, 4, 0, 0.3f);
}

Ike::~Ike()
{
}
