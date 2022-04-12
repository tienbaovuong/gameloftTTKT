#pragma once
#include "Sprite2D.h"
class Character;
class ItemBase :
    public Sprite2D
{
public:
    ItemBase() : Sprite2D() {}
    ItemBase(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture);
    ~ItemBase();
    virtual void effect(std::shared_ptr<Character> other) = 0;
};

