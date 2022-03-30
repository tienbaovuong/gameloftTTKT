#include "MapSquare.h"

MapSquare::MapSquare(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture)
	:Sprite2D(-1, model, shader, texture), m_posX(0), m_posY(0), m_evasion(0), m_maptype("unknown")
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
