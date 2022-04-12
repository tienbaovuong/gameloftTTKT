#include "Food.h"

Food::Food(GLint durability)
	:Consumable(durability)
{
	this->m_name = "Foods";
	this->m_description = "Heal yourself for 10HP";
	this->m_maxDurability = 3;
}

Food::~Food()
{
}

void Food::effect(std::shared_ptr<Character> other)
{
	other->setHealthPoint(other->getHealthPoint() + 10);
}
