#include "Chess.h"

Chess::Chess(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture)
	:MapSquare(model, shader, texture)
{
	this->m_evasion = 0;
	this->m_defense = 0;
	this->m_resistance = 0;
	this->m_maptype = "Chess";
	this->isPassable = true;
	this->isChess = true;
}

Chess::~Chess()
{
}
