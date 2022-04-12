#include "Sword.h"

Sword::Sword(GLint durability)
	:Item(durability)
{
	this->m_type = "sword";
}

Sword::~Sword()
{
}

void Sword::effect(std::shared_ptr<Character> other)
{
}
