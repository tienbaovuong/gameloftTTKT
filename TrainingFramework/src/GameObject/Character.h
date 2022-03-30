#pragma once
#include "Sprite2D.h"
#include "Item.h"
class Item;
class Character :
    public Sprite2D
{
public:
    Character() : Sprite2D() , m_name("unknown"), m_level(1), m_healthPoint(1), m_strength(0)
                  , m_magic(0), m_defense(0), m_resistance(0), m_movement(1), m_characterType("unknown"), m_power(0)
                  , m_hitRate(100), m_evasion(0), m_critRate(5), m_posX(0), m_posY(0){}
    Character(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture);
    ~Character();

    void move(GLint x, GLint y);
    virtual void interact(Character otherPerson, bool enemyDefeated) = 0;

protected:
    char* m_name;
    std::list<std::shared_ptr<Item>> m_itemList;
    GLint m_level;
    GLint m_healthPoint;
    GLint m_strength;
    GLint m_magic;
    GLint m_defense;
    GLint m_resistance;
    GLint m_movement;
    char* m_characterType;
    
    GLint m_power;
    GLint m_hitRate;
    GLint m_evasion;
    GLint m_critRate;
    GLint m_posX;
    GLint m_posY;
};

