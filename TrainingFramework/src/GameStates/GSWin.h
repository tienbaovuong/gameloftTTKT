#pragma once
#include "GameStateBase.h"
#include "GameButton.h"

class GSWin :
    public GameStateBase
{
public:
    GSWin();
    ~GSWin();

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

private:
	std::shared_ptr<Sprite2D> m_backgroundWin;
	std::shared_ptr<Sprite2D> m_backgroundLose;
	std::shared_ptr<GameButton> button;
};

