#pragma once
#include "Sprite2D.h"
#include "Character.h"
#include <string>
class Character;
class Item: public Sprite2D
{
public:
	Item() : Sprite2D(), m_minRange(1), m_maxRange(1), m_durability(0), m_power(0), m_type("unknown"), m_hitRate(100), m_critRate(100) {}
	Item(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture);
	~Item();
	
	virtual bool isTargettable(Character user, Character other) = 0;
	virtual void effect(Character user, Character other) = 0;
	void reduceDurability(GLint duraLost);
	std::string getType();

protected:
	GLint m_minRange;
	GLint m_maxRange;
	GLint m_durability;
	GLint m_power;
	std::string m_type;
	GLint m_hitRate;
	GLint m_critRate;
};

