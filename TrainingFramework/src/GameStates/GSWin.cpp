#include "GSWin.h"

GSWin::GSWin()
{
}

GSWin::~GSWin()
{
}

void GSWin::Init()
{
	auto model = AssetManager::GetInstance()->model2D;
	auto shader = AssetManager::GetInstance()->shaderTexture;

	m_backgroundWin = std::make_shared<Sprite2D>(model, shader, ResourceManagers::GetInstance()->GetTexture("gamewin.tga"));
	m_backgroundWin->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2);
	m_backgroundWin->SetSize(Globals::screenWidth, Globals::screenHeight);

	m_backgroundLose = std::make_shared<Sprite2D>(model, shader, ResourceManagers::GetInstance()->GetTexture("gameover.tga"));
	m_backgroundLose->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2);
	m_backgroundLose->SetSize(Globals::screenWidth, Globals::screenHeight);

	button = std::make_shared<GameButton>(model, shader, ResourceManagers::GetInstance()->GetTexture("btn_quit.tga"));
	button->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight * 0.8);
	button->SetSize(200, 100);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->PopState();
		});
}

void GSWin::Exit()
{
}

void GSWin::Pause()
{
}

void GSWin::Resume()
{
}

void GSWin::HandleEvents()
{
}

void GSWin::HandleKeyEvents(int key, bool bIsPressed)
{
}

void GSWin::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	button->HandleTouchEvents(x, y, bIsPressed);
}

void GSWin::HandleMouseMoveEvents(int x, int y)
{
}

void GSWin::Update(float deltaTime)
{
	button->Update(deltaTime);
}

void GSWin::Draw()
{
	if (Globals::gameLevel == 1) {
		m_backgroundWin->Draw();
	}
	else {
		m_backgroundLose->Draw();
	}
	button->Draw();
}
