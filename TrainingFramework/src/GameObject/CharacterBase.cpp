#include "CharacterBase.h"

CharacterBase::CharacterBase(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture)
	:Sprite2D(model, shader, texture)
{

}

CharacterBase::~CharacterBase()
{
}
