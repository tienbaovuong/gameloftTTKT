#include "Warrior.h"

Warrior::Warrior(GLint level, GLint exp)
	:Ally(level, exp)
{
	this->m_characterType = "Warrior";
	this->m_movement = 5;
}

Warrior::~Warrior()
{
}

bool Warrior::isEquippable(std::shared_ptr<Item> equipment)
{
	if (equipment->getType() == "axe") return true;
	else return false;
}
