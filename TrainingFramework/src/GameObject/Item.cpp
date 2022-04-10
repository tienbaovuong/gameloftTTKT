#include "Item.h"
Item::Item(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture)
	:Sprite2D(-1, model, shader, texture), m_minRange(1), m_maxRange(1), m_durability(0), m_power(0), m_type("unknown"), m_hitRate(100), m_critRate(100)
{
}

Item::~Item()
{
}

void Item::reduceDurability(GLint duraLost)
{
	this->m_durability -= duraLost;
}

std::string Item::getType()
{
	return this->m_type;
}

