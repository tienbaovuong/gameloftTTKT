#pragma once
#include "Items/ItemBase.h"
#include "Character.h"
#include <string>
class Character;
class Item: public ItemBase
{
public:
	Item() : ItemBase(), m_minRange(1), m_maxRange(1), m_durability(20),m_maxDurability(20), m_power(0), m_type("unknown"), m_hitRate(0), m_critRate(0) {}
	Item(GLint durability);
	~Item();
	
	void effect(std::shared_ptr<Character> other) override;

	GLint getMaxRange();
	GLint getMinRange();
	std::string getDescription();
	std::string getItemName();
	GLint getDurability();
	GLint getMaxDurability();
	GLint getPower();
	GLint getHitRate();
	GLint getCritRate();
	void reduceDurability(GLint duraLost);
	std::string getType();

protected:
	GLint m_minRange;
	GLint m_maxRange;
	GLint m_durability;
	GLint m_maxDurability;
	GLint m_power;
	std::string m_type;
	std::string m_name;
	GLint m_hitRate;
	GLint m_critRate;
	std::string m_description;
};

