#include "Axe.h"

Axe::Axe(GLint durability)
	:Item(durability)
{
	this->m_type = "axe";
}

Axe::~Axe()
{
}

void Axe::effect(std::shared_ptr<Character> other)
{
}
