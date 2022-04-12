#include "Staffs.h"

Staffs::Staffs(GLint durability)
	:Item(durability)
{
	this->m_type = "staff";
}

Staffs::~Staffs()
{
}

void Staffs::effect(std::shared_ptr<Character> other)
{
}
