#pragma once
#include "GameStateBase.h"

class Character;
class Sprite2D;
class Text;
class GameButton;
class GSBattle :
    public GameStateBase
{
public:
    GSBattle();
    ~GSBattle();

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

	std::shared_ptr<Character> battler1, battler2;
	GLint eva1, def1, res1, eva2, def2, res2;

private:
	std::shared_ptr<Sprite2D> background;
	std::shared_ptr<Sprite2D> box1;
	std::shared_ptr<Sprite2D> box2;

	std::shared_ptr<std::list<Text>> fixedText;
	std::shared_ptr<Text> hp1;
	std::shared_ptr<Text> hp2;
};

