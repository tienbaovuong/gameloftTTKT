#include "MapPointer.h"

MapPointer::MapPointer(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture)
	: Sprite2D(-1, model, shader, texture), m_posX(0), m_posY(0)
{
}

MapPointer::~MapPointer()
{
}

GLint MapPointer::getPosX()
{
	return this->m_posX;
}

GLint MapPointer::getPosY()
{
	return this->m_posY;
}

void MapPointer::setPosXY(GLint x, GLint y)
{
	this->m_posX = x;
	this->m_posY = y;
}

bool MapPointer::canMoveLeft()
{
	if (this->GetPosition().x > Globals::screenWidth / 2) return false;
	else
		return true;
}

bool MapPointer::canMoveRight()
{
	if (this->GetPosition().x < Globals::screenWidth / 2) return false;
	else
		return true;
}

bool MapPointer::canMoveUp()
{
	if (this->GetPosition().y > Globals::screenHeight / 2) return false;
	else
		return true;
}

bool MapPointer::canMoveDown()
{
	if (this->GetPosition().y < Globals::screenHeight / 2) return false;
	else
		return true;
}

