/*
#include "GSIntro.h"
#include "GSMenu.h"
*/
#include "GSPlay.h"
#include "GSIntro.h"
#include "GSMenu.h"
#include "GSMap.h"
#include "GSBattle.h"
#include "GameStatebase.h"
#include "GameStates/GSInfo.h"
#include "GSSetting.h"
#include "GSWin.h"


GameStateBase::GameStateBase(StateType stateType) : m_stateType(stateType)
{}

std::shared_ptr<GameStateBase> GameStateBase::CreateState(StateType stt)
{
	std::shared_ptr<GameStateBase> gs = nullptr;
	switch (stt)
	{
	case StateType::STATE_INVALID:
		break;
	case StateType::STATE_INTRO:
		gs = std::make_shared<GSIntro>();
		break;
	case StateType::STATE_MENU:
		gs = std::make_shared<GSMenu>();
		break;
	case StateType::STATE_PLAY:
		gs = std::make_shared<GSPlay>();
		break;
	case StateType::STATE_MAP:
		gs = std::make_shared<GSMap>();
		break;
	case StateType::STATE_BATTLE:
		gs = std::make_shared<GSBattle>();
		break;
	case StateType::STATE_INFO:
		gs = std::make_shared<GSInfo>();
		break;
	case StateType::STATE_SETTING:
		gs = std::make_shared<GSSetting>();
		break;
	case StateType::STATE_WIN:
		gs = std::make_shared<GSWin>();
		break;
	default:
		break;
	}
	return gs;
}

StateType GameStateBase::GetGameStateType()
{
	return m_stateType;
}