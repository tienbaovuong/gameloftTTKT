#pragma once
#include "Sprite2D.h"
#include "Item.h"
#include <SpriteAnimation.h>
#include <MapSquare.h>
#include <stack>
class MapSquare;
class Item;

class MoveList
{
public:
    MoveList() : x(0), y(0), move(0), preX(0), preY(0), mark(false), expdMark(false), atkMark(false), direction(4) {}
    MoveList(GLint x, GLint y, GLint move, GLint preX, GLint preY, bool mark);
    ~MoveList();

    void setStat(GLint movE, GLint previousX, GLint previousY, bool marker, bool expandMark, GLint direction);
    void setAtk(GLint range, bool atkMark);
    GLint x;
    GLint y;
    GLint move;
    GLint preX;
    GLint preY;
    bool mark;
    bool expdMark;
    bool atkMark;
    GLint direction; //1 = left, 2 = up, 3 = right, 4 = down;
};

class Character :
    public Sprite2D
{
public:
    Character() : Sprite2D() , m_name("unknown"), m_level(1), m_healthPoint(1), m_strength(0), m_isEnemy(false)
                  , m_magic(0), m_defense(0), m_resistance(0), m_movement(5), m_characterType("unknown"), m_power(0)
                  , m_hitRate(100), m_evasion(0), m_critRate(5), m_posX(0), m_posY(0), fieldAnimation(nullptr), m_isAlive(true), m_isFinishTurn(false)
                    , m_movementMap(nullptr), m_time(0), m_disableButton(false) {}
    Character(GLint level, GLint exp);
    ~Character();



    void Update(GLfloat deltatime) override;
    void move(GLint x, GLint y);
    void calculateStat();
    //virtual bool isEquippable(std::shared_ptr<Item> equipment) = 0;
    //virtual void interact(Character otherPerson, bool enemyDefeated) = 0;
    std::shared_ptr<SpriteAnimation> getFieldAnimation();
    void setFieldAnimation(std::shared_ptr<SpriteAnimation> animation);
    GLint getPosX();
    GLint getPosY();
    void setPosXY(GLint x, GLint y);
    bool getFinishTurn();
    void setFinishTurn(bool finish);
    GLint getMove();
    std::string getCharName();
    void setCharName(std::string name);
    bool isEnemy();
    bool getDisableButton();
    bool getAlive();
    void die();
    void resetMovementMap();
    void calculateMovementMap(std::shared_ptr<MapSquare>** mapMatrix);
    void calculateAttackMap(std::shared_ptr<MapSquare>** mapMatrix);
    MoveList** getMovementMap();

protected:
    std::string m_name;
    std::list<std::shared_ptr<Item>> m_itemList;
    bool m_isEnemy;

    //basic stat
    GLint m_level;
    GLint m_exp;
    GLint m_healthPoint;
    GLint m_maxHealthPoint;
    GLint m_strength;
    GLint m_magic;
    GLint m_defense;
    GLint m_resistance;
    GLint m_movement;
    GLint m_minRange;
    GLint m_maxRange;
    std::string m_characterType;
    
    //stat need calculation (from equipment)
    GLint m_power;
    GLint m_hitRate;
    GLint m_evasion;
    GLint m_critRate;

    //growth
    GLfloat m_hpGrwth;
    GLfloat m_strGrwth;
    GLfloat m_magGrwth;
    GLfloat m_defGrwth;
    GLfloat m_resGrwth;

    //stuffs
    GLint m_posX;
    GLint m_posY;

    std::shared_ptr<SpriteAnimation> fieldAnimation;
    //std::shared_ptr<SpriteAnimation> battleAnimation;
    bool m_isAlive;
    bool m_isFinishTurn;
    bool m_disableButton;
    MoveList** m_movementMap;
    std::stack<MoveList> m_stackMove;
    GLfloat	m_time;
};

