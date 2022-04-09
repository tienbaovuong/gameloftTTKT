#include "MapTile/SnowTree.h"

SnowTree::SnowTree(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture)
	: MapSquare(model, shader, texture)
{
	this->m_evasion = 15;
	this->m_defense = 0;
	this->m_resistance = 0;
	this->m_maptype = "Snow Tree";
	this->isPassable = true;
}

SnowTree::~SnowTree()
{
}
