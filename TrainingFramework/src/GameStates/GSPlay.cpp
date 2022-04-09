#include "GSPlay.h"

#include "Shader.h"
#include "Texture.h"
#include "Model.h"
#include "Camera.h"
#include "Font.h"
#include "Sprite2D.h"
#include "Sprite3D.h"
#include "Text.h"
#include "GameButton.h"
#include "SpriteAnimation.h"


GSPlay::GSPlay()
{
}


GSPlay::~GSPlay()
{
}


void GSPlay::Init()
{
	m_isPause = false;
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("bg_play1.tga");

	// background
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition((float)Globals::screenWidth / 2, (float)Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);

	// button list
	// button pause
	texture = ResourceManagers::GetInstance()->GetTexture("btn_pause.tga");
	std::shared_ptr<GameButton>  button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth - 75, 50);
	button->SetSize(75, 75);
	button->SetOnClick([this]() {
			//GameStateMachine::GetInstance()->PopState();
			Pause();
		});
	m_listButton.push_back(button);

	// button list in pause mode
	// button continue
	texture = ResourceManagers::GetInstance()->GetTexture("btn_resume.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth/2, 350);
	button->SetSize(200, 100);
	button->SetOnClick([this]() {
			Resume();
			//GameStateMachine::GetInstance()->PopState();
		});
	m_listButtonOnPause.push_back(button);

	// button return to main menu
	texture = ResourceManagers::GetInstance()->GetTexture("btn_quit.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth/2, 450);
	button->SetSize(200, 100);
	button->SetOnClick([this]() {
		GameStateMachine::GetInstance()->PopState();
		});
	m_listButtonOnPause.push_back(button);

	// score
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Ramaraja-Regular.ttf");
	m_score = std::make_shared< Text>(shader, font, "score: 10", TextColor::RED, 1.0);
	m_score->Set2DPosition(Vector2(5, 25));

	//animation
	shader = ResourceManagers::GetInstance()->GetShader("Animation");
	texture = ResourceManagers::GetInstance()->GetTexture("Actor1_2.tga");
	std::shared_ptr<SpriteAnimation> obj = std::make_shared<SpriteAnimation>(model, shader, texture, 9, 6, 5, 0.1f);
	
	obj->Set2DPosition(Globals::screenWidth/2 - 15, Globals::screenHeight/2 - 15);
	obj->SetSize(334, 223);
	//obj->SetRotation(Vector3(0.0f, 3.14f, 0.0f));
	m_listAnimation.push_back(obj);
}

void GSPlay::Exit()
{
}


void GSPlay::Pause()
{
	m_isPause = std::make_shared<BOOLEAN>(TRUE);
}

void GSPlay::Resume()
{
	if (m_isPause.get()) {
		m_isPause = false;
		//std::wcout << "Yes";
	}
}


void GSPlay::HandleEvents()
{
}

void GSPlay::HandleKeyEvents(int key, bool bIsPressed)
{
}

void GSPlay::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto button : m_listButton)
	{
		if(button->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}
	if (m_isPause.get())
		for (auto button : m_listButtonOnPause)
		{
			if (button->HandleTouchEvents(x, y, bIsPressed))
			{
				break;
			}
		}
}

void GSPlay::HandleMouseMoveEvents(int x, int y)
{
}

void GSPlay::Update(float deltaTime)
{
	if (m_isPause.get()) {
		for (auto it : m_listButtonOnPause)
		{
			it->Update(deltaTime);
		}
		return;
	}
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}

	for (auto it : m_listAnimation)
	{
		it->Update(deltaTime);
	}
	
}

void GSPlay::Draw()
{
	m_background->Draw();
	//m_score->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}

	for (auto it : m_listAnimation)
	{
		it->Draw();
	}

	if (m_isPause.get()) {
		for (auto it : m_listButtonOnPause)
		{
			it->Draw();
		}
	}

}