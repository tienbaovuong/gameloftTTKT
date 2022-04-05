#include "MapSquare.h"

MapSquare::MapSquare(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture)
	: Sprite2D(-1, model, shader, texture), m_posX(0), m_posY(0), m_evasion(0), m_maptype("unknown")
{
}

MapSquare::~MapSquare()
{
}

GLint MapSquare::getPosX()
{
	return this->m_posX;
}

GLint MapSquare::getPosY()
{
	return this->m_posY;
}

GLint MapSquare::getEvasion()
{
	return this->m_evasion;
}

char* MapSquare::getMapType()
{
	return this->m_maptype;
}

std::shared_ptr<Character> MapSquare::getCharacter()
{
	return this->character;
}

void MapSquare::setPosXY(GLint x, GLint y)
{
	this->m_posX = x;
	this->m_posY = y;
	this->Set2DPosition((float)Globals::squareLength * (x + 0.5), (float)Globals::squareLength * (y + 0.5));
}

void MapSquare::setDrawPos(GLint x, GLint y)
{
	this->Set2DPosition(this->GetPosition().x + x * Globals::squareLength, this->GetPosition().y + y * Globals::squareLength);
}
