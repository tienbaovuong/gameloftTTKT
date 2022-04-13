#include "Ike.h"

Ike::Ike(GLint level, GLint exp)
	:SwordMan(level, exp)
{
	this->SetTexture(AssetManager::GetInstance()->IkeFace);
	this->secondFace = std::make_shared<Sprite2D>(AssetManager::GetInstance()->model2D, AssetManager::GetInstance()->shaderTexture, AssetManager::GetInstance()->IkeFace2);
	this->m_name = "Ike";
	this->m_maxHealthPoint = 19;
	this->m_strength = 11;
	this->m_defense = 5;
	this->m_magic = 2;
	this->m_resistance = 2;
	
	this->m_hpGrwth = 1.2;
	this->m_strGrwth = 1.2;
	this->m_defGrwth = 0.8;
	this->m_magGrwth = 0.3;
	this->m_resGrwth = 0.3;
	calculateStat();
	this->fieldAnimation = std::make_shared<SpriteAnimation>(AssetManager::GetInstance()->model2D, AssetManager::GetInstance()->shaderAnimation, AssetManager::GetInstance()->IkeField, 3, 4, 0, 0.3f);
}

Ike::~Ike()
{
}
