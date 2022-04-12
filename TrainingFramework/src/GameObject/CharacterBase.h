#pragma once
#include "Sprite2D.h"
class Item;
class CharacterBase :
    public Sprite2D
{
public:
    CharacterBase() : Sprite2D() {}
    CharacterBase(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture);
    ~CharacterBase();
    virtual bool isEquippable(std::shared_ptr<Item> equipment) = 0;
};

