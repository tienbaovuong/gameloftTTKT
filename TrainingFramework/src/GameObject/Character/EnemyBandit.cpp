#include "EnemyBandit.h"

EnemyBandit::EnemyBandit(GLint level, GLint exp)
	:Enemy(level, exp)
{
	this->SetTexture(AssetManager::GetInstance()->BanditFace);
	this->secondFace = std::make_shared<Sprite2D>(AssetManager::GetInstance()->model2D, AssetManager::GetInstance()->shaderTexture, AssetManager::GetInstance()->BanditFace2);
	this->m_name = "Bandit";
	this->m_maxHealthPoint = 14;
	this->m_strength = 10;
	this->m_defense = 3;
	this->m_magic = 0;
	this->m_resistance = 0;
	this->m_movement = 3;
	this->m_characterType = "Bandit";

	this->m_hpGrwth = 1.1;
	this->m_strGrwth = 1;
	this->m_defGrwth = 0.6;
	this->m_magGrwth = 0;
	this->m_resGrwth = 0;
	calculateStat();
	this->fieldAnimation = std::make_shared<SpriteAnimation>(AssetManager::GetInstance()->model2D, AssetManager::GetInstance()->shaderAnimation, AssetManager::GetInstance()->EnemyBanditField, 3, 4, 0, 0.3f);
}

EnemyBandit::~EnemyBandit()
{
}

bool EnemyBandit::isEquippable(std::shared_ptr<Item> equipment)
{
	if (equipment->getType() == "axe") return true;
	else return false;
}
