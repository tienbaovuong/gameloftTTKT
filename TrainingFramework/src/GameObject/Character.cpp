#include "Character.h"

Character::Character(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture)
	:Sprite2D(-1, model, shader, texture), m_name("unknown"), m_level(1), m_healthPoint(1), m_strength(0)
    , m_magic(0), m_defense(0), m_resistance(0), m_movement(1), m_characterType("unknown"), m_power(0)
    , m_hitRate(100), m_evasion(0), m_critRate(5), m_posX(0), m_posY(0)
{
}

Character::~Character()
{
}

void Character::move(GLint x, GLint y)
{
}
