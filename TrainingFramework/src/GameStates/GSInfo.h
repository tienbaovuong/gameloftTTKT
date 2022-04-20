#pragma once
#include "GameStateBase.h"
class Item;
class Character;
class Sprite2D;
class Text;
class GSInfo :
    public GameStateBase
{
public:
    GSInfo();
    ~GSInfo();

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

	void	refreshItem();
	void	switchItem(GLint pos);

private:
	std::shared_ptr<Character> chosenOne;
	std::shared_ptr<Item> chosenItem;
	bool readOnly;
	bool isWeapon = true;
	GLint totalItem;
	float m_time;

	//0 = normal state, 1 = item option appear, 2 = item effect
	GLint currentState;

	std::shared_ptr<Sprite2D> background;
	std::shared_ptr<Sprite2D> box1;
	std::shared_ptr<Sprite2D> box2;
	std::shared_ptr<Sprite2D> option1;
	std::shared_ptr<Sprite2D> option2;
	std::shared_ptr<Sprite2D> itemPointer;
	GLint pointerPos;

	std::list<std::shared_ptr<Text>> fixedText;
	std::list<std::shared_ptr<Text>> itemsText;
	std::shared_ptr<Text>	description;
	std::shared_ptr<Text>	option1text;
	std::shared_ptr<Text>	option2text;

	std::shared_ptr<Text> hptext;
	std::shared_ptr<Text> totalPow;
	std::shared_ptr<Text> totalCrit;
	std::shared_ptr<Text> totalHit;
	std::shared_ptr<Text> range1;
	std::shared_ptr<Text> pow;
	std::shared_ptr<Text> crit;
	std::shared_ptr<Text> hit;
	std::shared_ptr<Text> range2;

	//preset position
	double posX1 = Globals::screenWidth * 0.62;
	double posX2 = Globals::screenWidth * 0.65;
	double posY[5] = { Globals::screenHeight * 0.37, Globals::screenHeight * 0.49, Globals::screenHeight * 0.61, Globals::screenHeight * 0.73, Globals::screenHeight * 0.85 };
};

