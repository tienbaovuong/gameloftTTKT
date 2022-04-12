#include "HealingStaff.h"

HealingStaff::HealingStaff(GLint durability)
	:Staffs(durability)
{
	this->m_name = "Healing Staff";
	this->m_minRange = 1;
	this->m_maxRange = 2;
	this->m_maxDurability = 20;
	this->m_power = 3;
	this->m_hitRate = 0;
	this->m_critRate = 0;
	this->m_description = "Heal ally with magic power";
}

HealingStaff::~HealingStaff()
{
}

void HealingStaff::effect(std::shared_ptr<Character> other)
{
	other->setHealthPoint(other->getHealthPoint() + 8);
}
