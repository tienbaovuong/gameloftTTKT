#include "Character/SwordMan.h"

SwordMan::SwordMan(GLint level, GLint exp)
	:Ally(level, exp)
{
	this->m_characterType = "Sword Man";
	this->m_movement = 6;
}

SwordMan::~SwordMan()
{
}

bool SwordMan::isEquippable(std::shared_ptr<Item> equipment)
{
	if (equipment->getType() == "sword") return true;
	else return false;
}
