#include "IronAxe.h"

IronAxe::IronAxe(GLint durability)
	:Axe(durability)
{
	this->m_name = "Axe Sword";
	this->m_minRange = 1;
	this->m_maxRange = 1;
	this->m_maxDurability = 30;
	this->m_power = 6;
	this->m_hitRate = -10;
	this->m_critRate = 10;
	this->m_description = "An iron axe";
}

IronAxe::~IronAxe()
{
}
