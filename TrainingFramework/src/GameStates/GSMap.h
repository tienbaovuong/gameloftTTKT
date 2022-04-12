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
	
	bool	CheckHealer();
	void	Battle(std::shared_ptr<Character> battler1, std::shared_ptr<Character> battle2, std::shared_ptr<MapSquare> square1, std::shared_ptr<MapSquare> square2);
	void	GameOver();
	bool	checkEndTurn();
	void	enemyTurn();

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
	
	//box
	std::shared_ptr <Sprite2D> mapsquareInfoBox;
	std::shared_ptr <Sprite2D> characterNameBox;
	std::shared_ptr <Sprite2D> attackOption;
	std::shared_ptr <Sprite2D> itemOption;
	std::shared_ptr <Sprite2D> waitOption;
	std::shared_ptr <Sprite2D> openChestOption;

	//text
	std::shared_ptr<Text>		m_infoEvasion;
	std::shared_ptr<Text>		m_infoSquareType;
	std::shared_ptr<Text>		m_infoDef;
	std::shared_ptr<Text>		m_infoRes;
	std::shared_ptr<Text>		m_charName;
	std::shared_ptr<Text>		m_attackWord;
	std::shared_ptr<Text>		m_itemWord;
	std::shared_ptr<Text>		m_waitWord;
	std::shared_ptr<Text>		m_openChestWord;
	std::shared_ptr<Text>		m_debug;
	std::shared_ptr<Text>		m_numMovement;
	std::shared_ptr<Text>		m_finishTurnMark;
	
	//main character
	std::shared_ptr<Character> m_mainCharacter;
};

