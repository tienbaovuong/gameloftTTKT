#include "GSBattle.h"

GSBattle::GSBattle()
	:GameStateBase(StateType::STATE_BATTLE)
{
	battler1 = AssetManager::GetInstance()->battler1;
	battler2 = AssetManager::GetInstance()->battler2;
	eva1 = AssetManager::GetInstance()->eva1;
	def1 = AssetManager::GetInstance()->def1;
	res1 = AssetManager::GetInstance()->res1;
	eva2 = AssetManager::GetInstance()->eva2;
	def2 = AssetManager::GetInstance()->def2;
	res2 = AssetManager::GetInstance()->res2;
}

GSBattle::~GSBattle()
{
}

void GSBattle::Init()
{

}

void GSBattle::Exit()
{
}

void GSBattle::Pause()
{
}

void GSBattle::Resume()
{
}

void GSBattle::HandleEvents()
{
}

void GSBattle::HandleKeyEvents(int key, bool bIsPressed)
{
}

void GSBattle::HandleTouchEvents(int x, int y, bool bIsPressed)
{
}

void GSBattle::HandleMouseMoveEvents(int x, int y)
{
}

void GSBattle::Update(float deltaTime)
{
}

void GSBattle::Draw()
{
}
