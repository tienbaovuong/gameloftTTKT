#include "GSSetting.h"

GSSetting::GSSetting()
{
}

GSSetting::~GSSetting()
{
}

void GSSetting::Init()
{
	auto model = AssetManager::GetInstance()->model2D;
	auto shader = AssetManager::GetInstance()->shaderTexture;

	background = std::make_shared<Sprite2D>(model, shader, AssetManager::GetInstance()->brownBox);
	background->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2);
	background->SetSize(Globals::screenWidth + 100, Globals::screenHeight + 100);

	btnOn = std::make_shared<Sprite2D>(model, shader, ResourceManagers::GetInstance()->GetTexture("btn_music.tga"));
	btnOn->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2);
	btnOn->SetSize(Globals::screenHeight / 4, Globals::screenHeight / 4);

	btnOff = std::make_shared<Sprite2D>(model, shader, ResourceManagers::GetInstance()->GetTexture("btn_music_off.tga"));
	btnOff->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2);
	btnOff->SetSize(Globals::screenHeight / 4, Globals::screenHeight / 4);

	button = std::make_shared<GameButton>(model, shader, AssetManager::GetInstance()->brownBox);
	button->SetSize(Globals::screenHeight / 4, Globals::screenHeight / 4);
	button->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2);
	button->SetOnClick([]() {
		Globals::musicOn = !Globals::musicOn;
		});
}

void GSSetting::Exit()
{
}

void GSSetting::Pause()
{
}

void GSSetting::Resume()
{
}

void GSSetting::HandleEvents()
{
}

void GSSetting::HandleKeyEvents(int key, bool bIsPressed)
{
	if (bIsPressed) {
		switch (key) {
		case KEY_BACK:
			GameStateMachine::GetInstance()->PopState();
			break;
		default:
			break;
		}
	}
}

void GSSetting::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	button->HandleTouchEvents(x, y, bIsPressed);
}

void GSSetting::HandleMouseMoveEvents(int x, int y)
{
}

void GSSetting::Update(float deltaTime)
{
	button->Update(deltaTime);
}

void GSSetting::Draw()
{
	background->Draw();
	if (Globals::musicOn) {
		btnOn->Draw();
	}
	else {
		btnOff->Draw();
	}
}
