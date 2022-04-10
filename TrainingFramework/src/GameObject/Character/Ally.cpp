#include "Ally.h"

Ally::Ally(GLint level, GLint exp)
	:Character(level, exp)
{
	this->m_isEnemy = false;
}

Ally::~Ally()
{
}
