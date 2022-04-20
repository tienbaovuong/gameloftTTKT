#pragma once
#include "Character.h"
class Enemy :
    public Character
{
public:
    Enemy(){}
    Enemy(GLint level, GLint exp);
    ~Enemy();
    void Update(GLfloat deltatime) override;
    bool AI(std::shared_ptr<MapSquare>** mapMatrix) override;
    MoveList m_attackMap[Globals::mapWidth][Globals::mapHeight];
    //virtual bool isEquippable(std::shared_ptr<Item> equipment) = 0;
};

