#include "Character/CharacterBase.h"

CharacterBase::CharacterBase(GLint level, GLint exp)
	:Character(level, exp)
{
}

CharacterBase::~CharacterBase()
{
}

bool CharacterBase::isEquippable(std::shared_ptr<Item> equipment)
{
	return true;
}
