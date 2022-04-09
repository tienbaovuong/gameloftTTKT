#include "MapTile/Castle.h"

Castle::Castle(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture)
	: MapSquare(model, shader, texture)
{
	this->m_evasion = 0;
	this->m_defense = 3;
	this->m_resistance = 2;
	this->m_maptype = "Castle";
	this->isPassable = true;
}

Castle::~Castle()
{
}
