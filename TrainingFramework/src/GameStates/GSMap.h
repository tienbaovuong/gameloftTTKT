#pragma once
#include "GameStateBase.h"

class MapSquare;
class MapPointer;
class Character;
class Sprite2D;
class Text;
class GameButton;
class SpriteAnimation;

class GSMap :
    public GameStateBase
{
public:
	GSMap();
	~GSMap();

	void	Init() override;
	void	Exit() override;

	void	Pause() override;
	void	Resume() override;

	void	HandleEvents() override;
	void	HandleKeyEvents(int key, bool bIsPressed) override;
	void	HandleTouchEvents(int x, int y, bool bIsPressed) override;
	void	HandleMouseMoveEvents(int x, int y) override;
	void	Update(float deltaTime) override;
	void	Draw() override;
	
	void	GameOver();
	bool	checkEndTurn();

private:
	std::shared_ptr<MapSquare>**	m_mapMatrix;
	int m_map[Globals::mapWidth][Globals::mapHeight];
	std::shared_ptr<BOOLEAN>    m_isPause;
	std::list<std::shared_ptr<GameButton>>	m_listButton;
	std::list<std::shared_ptr<GameButton>>	m_listButtonOnPause;
	std::list<std::shared_ptr<SpriteAnimation>>	m_listAnimation;
	std::list<std::shared_ptr<Character>> m_listCharacter;
	std::list<std::shared_ptr<Character>> m_listEnemy;
	std::shared_ptr<MapPointer> m_mapPointer;
	std::shared_ptr<Character> m_chosenCharacter;
	std::shared_ptr <Sprite2D> m_moveMarker;
	std::shared_ptr <Sprite2D> m_atkMarker;

 	//0 = normal map state, 1 = character moving state, 2 = character pick action, 3 = choose target, 4 = enemy turn
	GLint currentState = 0;

	//text
	std::shared_ptr<Text>		m_infoTile;
	std::shared_ptr<Text>		m_debug;
	std::shared_ptr<Text>		m_numMovement;
	
	//main character
	std::shared_ptr<Character> m_mainCharacter;
};

