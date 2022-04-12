#include "IronSword.h"

IronSword::IronSword(GLint durability)
	:Sword(durability)
{
	this->m_name = "Iron Sword";
	this->m_minRange = 1;
	this->m_maxRange = 1;
	this->m_maxDurability = 30;
	this->m_power = 4;
	this->m_hitRate = 5;
	this->m_critRate = 0;
	this->m_description = "An iron sword";
}

IronSword::~IronSword()
{
}
