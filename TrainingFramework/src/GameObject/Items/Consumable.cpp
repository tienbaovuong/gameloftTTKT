#include "Consumable.h"
#include "Item.h"

Consumable::Consumable(GLint durability)
	:Item(durability)
{
	this->m_type = "Consumable";
}

Consumable::~Consumable()
{
}

void Consumable::effect(std::shared_ptr<Character> other)
{
}

class Staff :
	public Item
{
};
