#include "EnemyBanditHeader.h"

EnemyBanditHeader::EnemyBanditHeader(GLint level, GLint exp)
	:Enemy(level, exp)
{
	this->m_name = "Bandit Leader";
	this->m_maxHealthPoint = 1;
	this->m_strength = 1;
	this->m_defense = 1;
	this->m_magic = 1;
	this->m_resistance = 1;
	this->m_movement = 3;
	this->m_characterType = "Bandit Leader";

	this->m_hpGrwth = 1;
	this->m_strGrwth = 1;
	this->m_defGrwth = 1;
	this->m_magGrwth = 0;
	this->m_resGrwth = 0;
	calculateStat();
	this->fieldAnimation = std::make_shared<SpriteAnimation>(AssetManager::GetInstance()->model2D, AssetManager::GetInstance()->shaderAnimation, AssetManager::GetInstance()->EnemyBanditLeaderField, 3, 4, 0, 0.3f);
}

EnemyBanditHeader::~EnemyBanditHeader()
{
}

bool EnemyBanditHeader::isEquippable(std::shared_ptr<Item> equipment)
{
	if (equipment->getType() == "axe" || equipment->getType() == "sword") return true;
	else return false;
}
