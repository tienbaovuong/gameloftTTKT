#pragma once
#include "Sprite2D.h"
#include <Character.h>

class MapSquare: public Sprite2D
{
public:
	MapSquare() : Sprite2D(), m_posX(0), m_posY(0), m_evasion(0), m_maptype("unknown") , character(nullptr){}
	MapSquare(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture);
	~MapSquare();
	virtual bool isPassable(Character user) = 0;
	GLint getPosX();
	GLint getPosY();
	GLint getEvasion();
	char* getMapType();
	std::shared_ptr<Character> getCharacter();

protected:
	GLint m_posX;
	GLint m_posY;
	GLint m_evasion;
	char* m_maptype;
	std::shared_ptr<Character> character;
};
