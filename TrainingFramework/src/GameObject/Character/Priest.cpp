#include "Priest.h"

Priest::Priest(GLint level, GLint exp)
	:Ally(level, exp)
{
	this->m_characterType = "Priest";
	this->m_movement = 3;
}

Priest::~Priest()
{
}

bool Priest::isEquippable(std::shared_ptr<Item> equipment)
{
	if (equipment->getType() == "staff") return true;
	else return false;
}
