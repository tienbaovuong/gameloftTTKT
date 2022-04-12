#include "Item.h"
Item::Item(GLint durability)
	:ItemBase(AssetManager::GetInstance()->model2D, AssetManager::GetInstance()->shaderTexture, AssetManager::GetInstance()->brownBox), m_minRange(1), m_maxRange(1), m_durability(durability),m_maxDurability(20), m_power(0), m_type("unknown"), m_hitRate(100), m_critRate(100)
{
}

Item::~Item()
{
}

void Item::effect(std::shared_ptr<Character> other)
{
}

GLint Item::getMaxRange()
{
	return this->m_maxRange;
}

GLint Item::getMinRange()
{
	return this->m_minRange;
}

std::string Item::getDescription()
{
	return this->m_description;
}

std::string Item::getItemName()
{
	return this->m_name;
}

GLint Item::getDurability()
{
	return this->m_durability;
}

GLint Item::getMaxDurability()
{
	return this->m_maxDurability;
}

GLint Item::getPower()
{
	return this->m_power;
}

GLint Item::getHitRate()
{
	return this->m_hitRate;
}

GLint Item::getCritRate()
{
	return this->m_critRate;
}

void Item::reduceDurability(GLint duraLost)
{
	this->m_durability -= duraLost;
	if (m_durability < 0) m_durability = 0;
}

std::string Item::getType()
{
	return this->m_type;
}

