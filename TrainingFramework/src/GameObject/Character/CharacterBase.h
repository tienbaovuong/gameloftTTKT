#pragma once
#include "Character.h"
class Item;
class CharacterBase :
    public Character
{
public:
    CharacterBase() {}
    CharacterBase(GLint level, GLint exp);
    ~CharacterBase();

    bool isEquippable(std::shared_ptr<Item> equipment);
};

