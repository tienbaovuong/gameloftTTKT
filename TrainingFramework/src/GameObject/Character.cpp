#include "Character.h"

Character::Character(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture)
    :Sprite2D(-1, model, shader, texture), m_name("unknown"), m_level(1), m_healthPoint(1), m_strength(0)
    , m_magic(0), m_defense(0), m_resistance(0), m_movement(1), m_characterType("unknown"), m_power(0)
    , m_hitRate(100), m_evasion(0), m_critRate(5), m_posX(0), m_posY(0), fieldAnimation(nullptr), m_isFinishTurn(false)
{
}


Character::~Character()
{
}

void Character::move(GLint x, GLint y)
{
}

std::shared_ptr<SpriteAnimation> Character::getFieldAnimation()
{
    return this->fieldAnimation;
}

void Character::setFieldAnimation(std::shared_ptr<SpriteAnimation> animation)
{
    this->fieldAnimation = animation;
}

GLint Character::getPosX()
{
    return this->m_posX;
}

GLint Character::getPosY()
{
    return this->m_posY;
}

void Character::setPosXY(GLint x, GLint y)
{
    this->m_posX = x;
    this->m_posY = y;
}

bool Character::getFinishTurn()
{
    return this->m_isFinishTurn;
}

void Character::setFinishTurn(bool finish)
{
    this->m_isFinishTurn = finish;
}

void Character::resetMovementMap()
{
    for (int i = 0; i < Globals::mapWidth; i++) {
        for (int j = 0; j < Globals::mapHeight;j++) {
            m_movementMap[i][j] = false;
        }
    }
}

void Character::calculateMovementMap(std::shared_ptr<MapSquare> mapMatrix)
{

}



    
