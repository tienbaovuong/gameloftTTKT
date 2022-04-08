#include "MapSquare.h"

MapSquare::MapSquare(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture)
	: Sprite2D(-1, model, shader, texture), m_posX(0), m_posY(0), m_evasion(0), m_maptype("unknown"), isPassable(true)
{
	this->SetSize(Globals::squareLength, Globals::squareLength);
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

std::string MapSquare::getMapType()
{
	return this->m_maptype;
}

bool MapSquare::getPassable()
{
	return this->isPassable;
}

std::shared_ptr<Character> MapSquare::getCharacter()
{
	return this->character;
}

void MapSquare::setCharacter(std::shared_ptr<Character> character)
{
	this->character = character;
}

void MapSquare::setPassable(bool pass)
{
	this->isPassable = pass;
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
