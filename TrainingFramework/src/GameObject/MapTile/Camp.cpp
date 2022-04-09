#include "Camp.h"

Camp::Camp(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture)
	: MapSquare(model, shader, texture)
{
	this->m_evasion = 0;
	this->m_defense = 2;
	this->m_resistance = 1;
	this->m_maptype = "Camp";
	this->isPassable = true;
}

Camp::~Camp()
{
}
