#include "GSMap.h"

#include "Shader.h"
#include "Texture.h"
#include "Model.h"
#include "Camera.h"
#include "Font.h"
#include "Sprite2D.h"
#include "Sprite3D.h"
#include "Text.h"
#include "GameButton.h"
#include "MapSquare.h"
#include "MapPointer.h"
#include "SpriteAnimation.h"

GSMap::GSMap()
{
}

GSMap::~GSMap()
{
}

void GSMap::Init()
{
	m_isPause = false;
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	
	//map matrix
	auto texture = ResourceManagers::GetInstance()->GetTexture("tileset/Field_Snow1.tga");
	auto texture2 = ResourceManagers::GetInstance()->GetTexture("tileset/River.tga");

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if(i == 9 || j == 9) 
				m_mapMatrix[i][j] = std::make_shared<MapSquare>(model, shader, texture2);
			else 
				m_mapMatrix[i][j] = std::make_shared<MapSquare>(model, shader, texture);
			m_mapMatrix[i][j]->setPosXY(i,j);
			m_mapMatrix[i][j]->SetSize(Globals::squareLength, Globals::squareLength);
		}
	}
	//map pointer
	texture = ResourceManagers::GetInstance()->GetTexture("pointersquare.tga");
	m_mapPointer = std::make_shared<MapPointer>(model, shader, texture);
	m_mapPointer->setPosXY(5, 5);
	m_mapPointer->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2);
	m_mapPointer->SetSize(Globals::squareLength, Globals::squareLength);

	// button list
	// button pause
	texture = ResourceManagers::GetInstance()->GetTexture("btn_pause.tga");
	std::shared_ptr<GameButton>  button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth - 45, 50);
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
	button->Set2DPosition(Globals::screenWidth / 2, 350);
	button->SetSize(200, 100);
	button->SetOnClick([this]() {
		Resume();
		//GameStateMachine::GetInstance()->PopState();
		});
	m_listButtonOnPause.push_back(button);

	// button return to main menu
	texture = ResourceManagers::GetInstance()->GetTexture("btn_quit.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth / 2, 450);
	button->SetSize(200, 100);
	button->SetOnClick([this]() {
		GameStateMachine::GetInstance()->PopState();
		});
	m_listButtonOnPause.push_back(button);


	//debug
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Brightly Crush Shine.otf");
	m_debug = std::make_shared<Text>(shader, font, "", TextColor::RED, 1.0);
	m_debug->Set2DPosition(Vector2(5, 25));

	//animation
	shader = ResourceManagers::GetInstance()->GetShader("Animation");
	texture = ResourceManagers::GetInstance()->GetTexture("Ike.tga");
	std::shared_ptr<SpriteAnimation> obj = std::make_shared<SpriteAnimation>(model, shader, texture, 4, 4, 2, 0.25f);

	obj->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2);
	obj->SetSize(Globals::squareLength * 2, Globals::squareLength * 2);
	m_listAnimation.push_back(obj);
}

void GSMap::Exit()
{
}

void GSMap::Pause()
{
	m_isPause = std::make_shared<BOOLEAN>(TRUE);
}

void GSMap::Resume()
{
	if (m_isPause.get()) {
		m_isPause = false;
		//std::wcout << "Yes";
	}
}

void GSMap::HandleEvents()
{
}

void GSMap::HandleKeyEvents(int key, bool bIsPressed)
{
	if (bIsPressed) {
		//int xtemp = m_mapPointer->getPosX(), ytemp = m_mapPointer->getPosY();
		switch (key)
		{
		case KEY_MOVE_LEFT:
		case KEY_LEFT:
			//pointer transition
			if (m_mapPointer->getPosX() == 0) break;
			m_mapPointer->setPosXY(m_mapPointer->getPosX() - 1, m_mapPointer->getPosY());

			//map transition
			if (m_mapMatrix[0][0]->GetPosition().x != Globals::squareLength / 2 && m_mapPointer->canMoveLeft()) {
				for (int i = 0; i < 20; i++) {
					for (int j = 0; j < 20; j++) {
						auto temp = m_mapMatrix[i][j];
						temp->setDrawPos(1, 0);
					}
				}
			}
			//m_mapPointer->Set2DPosition(m_mapMatrix[xtemp][ytemp]->GetPosition().x, m_mapMatrix[xtemp][ytemp]->GetPosition().y);

			break;
		case KEY_MOVE_BACKWORD:
		case KEY_DOWN:
			//pointer transition
			if (m_mapPointer->getPosY() == 19) break;
			m_mapPointer->setPosXY(m_mapPointer->getPosX(), m_mapPointer->getPosY()+1);

			//map transition
			if (m_mapMatrix[19][19]->GetPosition().y != Globals::screenHeight - Globals::squareLength/2 && m_mapPointer->canMoveDown())
				for (int i = 0; i < 20; i++) {
					for (int j = 0; j < 20; j++) {
						auto temp = m_mapMatrix[i][j];
						temp->setDrawPos(0, - 1);
					}
				}
			//m_mapPointer->Set2DPosition(m_mapMatrix[xtemp][ytemp]->GetPosition().x, m_mapMatrix[xtemp][ytemp]->GetPosition().y);
			break;
		case KEY_MOVE_RIGHT:
		case KEY_RIGHT:
			//pointer transition
			if (m_mapPointer->getPosX() == 19) break;
			m_mapPointer->setPosXY(m_mapPointer->getPosX() + 1, m_mapPointer->getPosY());

			//map transition
			if (m_mapMatrix[19][19]->GetPosition().x != Globals::screenWidth - Globals::squareLength/2 && m_mapPointer->canMoveRight())
				for (int i = 0; i < 20; i++) {
					for (int j = 0; j < 20; j++) {
						auto temp = m_mapMatrix[i][j];
						temp->setDrawPos(- 1, 0);
					}
				}
			//m_mapPointer->Set2DPosition(m_mapMatrix[xtemp][ytemp]->GetPosition().x, m_mapMatrix[xtemp][ytemp]->GetPosition().y);
			break;
		case KEY_MOVE_FORWORD:
		case KEY_UP:
			//pointer transition
			if (m_mapPointer->getPosY() == 0) break;
			m_mapPointer->setPosXY(m_mapPointer->getPosX(), m_mapPointer->getPosY() - 1);

			//map transition
			if (m_mapMatrix[0][0]->GetPosition().y != Globals::squareLength/2 && m_mapPointer->canMoveUp())
				for (int i = 0; i < 20; i++) {
					for (int j = 0; j < 20; j++) {
						auto temp = m_mapMatrix[i][j];
						temp->setDrawPos(0, 1);
					}
				}
			//m_mapPointer->Set2DPosition(m_mapMatrix[xtemp][ytemp]->GetPosition().x, m_mapMatrix[xtemp][ytemp]->GetPosition().y);
			break;
		default:
			break;
		}
	}
}

void GSMap::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto button : m_listButton)
	{
		if (button->HandleTouchEvents(x, y, bIsPressed))
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

void GSMap::HandleMouseMoveEvents(int x, int y)
{
}

void GSMap::Update(float deltaTime)
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
	m_debug->SetText(std::to_string(m_mapPointer->getPosX()) + " - " + std::to_string(m_mapPointer->getPosY()));

	int xtemp = m_mapPointer->getPosX(), ytemp = m_mapPointer->getPosY();
	m_mapPointer->Set2DPosition(m_mapMatrix[xtemp][ytemp]->GetPosition().x, m_mapMatrix[xtemp][ytemp]->GetPosition().y);

	for (auto it : m_listAnimation)
	{
		it->Update(deltaTime);
	}
}

void GSMap::Draw()
{
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			m_mapMatrix[i][j]->Draw();
		}
	}
	m_mapPointer->Draw();
	
	for (auto it : m_listAnimation)
	{
		it->Draw();
	}
	m_debug->Draw();
	for (auto it : m_listButton)
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
