#pragma once
#include "Sprite2D.h"
class Character :
    public Sprite2D
{
public:
    Character() : Sprite2D() {}
    Character(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture);
    ~Character();

    void move(GLint x, GLint y);
    virtual void gainExp(Character otherPerson, bool enemyDefeated) = 0;

protected:

};

