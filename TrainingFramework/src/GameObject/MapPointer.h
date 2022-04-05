#pragma once
#include "Sprite2D.h"
class MapPointer :
    public Sprite2D
{
public:
	MapPointer() : Sprite2D(), m_posX(0), m_posY(0) {}
	MapPointer(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture);
	~MapPointer();

	GLint getPosX();
	GLint getPosY();

	void setPosXY(GLint x, GLint y);

	//check if pointer and map can move together or not
	bool canMoveLeft();
	bool canMoveRight();
	bool canMoveUp();
	bool canMoveDown();

protected:
	GLint m_posX;
	GLint m_posY;
};

