#include "GSInfo.h"
#include "Character.h"
#include "Font.h"

GSInfo::GSInfo()
{
}

GSInfo::~GSInfo()
{
}

void GSInfo::Init()
{
	currentState = 0;
	m_time = 0;

	chosenOne = AssetManager::GetInstance()->battler1;
	chosenOne->SetSize(Globals::screenHeight * 0.3, Globals::screenHeight * 0.3);
	chosenOne->Set2DPosition(Globals::screenHeight * 0.2, Globals::screenHeight * 0.15);
	readOnly = AssetManager::GetInstance()->infoReadOnly;

	auto model = AssetManager::GetInstance()->model2D;
	auto shader = AssetManager::GetInstance()->shaderTexture;
	//item marker
	auto texture = ResourceManagers::GetInstance()->GetTexture("pointersquare.tga");
	itemPointer = std::make_shared<Sprite2D>(model, shader, texture);
	itemPointer->SetSize(50, 50);
	itemPointer->Set2DPosition(50, 50);

	//brown box
	texture = AssetManager::GetInstance()->brownBox;
	background = std::make_shared<Sprite2D>(model, shader, texture);
	box1 = std::make_shared<Sprite2D>(model, shader, texture);
	box2 = std::make_shared<Sprite2D>(model, shader, texture);
	option1 = std::make_shared<Sprite2D>(model, shader, texture);
	option2 = std::make_shared<Sprite2D>(model, shader, texture);

	background->Set2DPosition(Globals::screenWidth / 2.0, Globals::screenHeight / 2.0);
	background->SetSize(Globals::screenWidth + 100, Globals::screenHeight + 100);

	box1->Set2DPosition(Globals::screenWidth*0.3, Globals::screenHeight *0.6);
	box1->SetSize(Globals::screenWidth * 0.6, Globals::screenHeight *0.6);

	box2->Set2DPosition(Globals::screenWidth *0.8, Globals::screenHeight*0.6);
	box2->SetSize(Globals::screenWidth *0.4, Globals::screenHeight *0.6);

	option1->Set2DPosition(Globals::screenWidth * 0.3, Globals::screenHeight * 0.45);
	option1->SetSize(Globals::screenWidth * 0.6, Globals::screenHeight * 0.3);

	option2->Set2DPosition(Globals::screenWidth * 0.3, Globals::screenHeight * 0.75);
	option2->SetSize(Globals::screenWidth * 0.6, Globals::screenHeight * 0.3);

	itemPointer = std::make_shared<Sprite2D>(model, shader, ResourceManagers::GetInstance()->GetTexture("pointersquare.tga"));
	itemPointer->SetSize(Globals::screenWidth * 0.38, Globals::screenHeight * 0.1);
	itemPointer->Set2DPosition(Globals::screenWidth * 0.8, posY[0]);
	pointerPos = 1;
	

	//text
	shader = AssetManager::GetInstance()->shaderText;
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Ramaraja-Regular.ttf");
	//fixed text
	auto text = std::make_shared<Text>(shader, font, chosenOne->getCharName(), TextColor::WHITE, 2.0);
	text->Set2DPosition(Globals::screenHeight * 0.37, Globals::screenHeight * 0.1);
	fixedText.push_back(text);

	text = std::make_shared<Text>(shader, font, chosenOne->getCharType(), TextColor::WHITE, 2.0);
	text->Set2DPosition(Globals::screenHeight * 0.37, Globals::screenHeight * 0.2);
	fixedText.push_back(text);

	text = std::make_shared<Text>(shader, font, "Lvl: " + std::to_string(chosenOne->getLevel()), TextColor::WHITE, 2.0);
	text->Set2DPosition(Globals::screenWidth*0.05 , Globals::screenHeight * 0.4);
	fixedText.push_back(text);

	text = std::make_shared<Text>(shader, font, "Exp: " + std::to_string(chosenOne->getExp()), TextColor::WHITE, 2.0);
	text->Set2DPosition(Globals::screenWidth*0.35  , Globals::screenHeight * 0.4);
	fixedText.push_back(text);

	text = std::make_shared<Text>(shader, font, "Move: " + std::to_string(chosenOne->getMove()), TextColor::WHITE, 2.0);
	text->Set2DPosition(Globals::screenWidth * 0.35, Globals::screenHeight * 0.55);
	fixedText.push_back(text);

	text = std::make_shared<Text>(shader, font, "Str: " + std::to_string(chosenOne->getStrength()), TextColor::WHITE, 2.0);
	text->Set2DPosition(Globals::screenWidth * 0.05, Globals::screenHeight * 0.7);
	fixedText.push_back(text);

	text = std::make_shared<Text>(shader, font, "Def: " + std::to_string(chosenOne->getDef()), TextColor::WHITE, 2.0);
	text->Set2DPosition(Globals::screenWidth * 0.35, Globals::screenHeight * 0.7);
	fixedText.push_back(text);

	text = std::make_shared<Text>(shader, font, "Mag: " + std::to_string(chosenOne->getMagic()), TextColor::WHITE, 2.0);
	text->Set2DPosition(Globals::screenWidth * 0.05, Globals::screenHeight * 0.85);
	fixedText.push_back(text);

	text = std::make_shared<Text>(shader, font, "Res: " + std::to_string(chosenOne->getRes()), TextColor::WHITE, 2.0);
	text->Set2DPosition(Globals::screenWidth * 0.35, Globals::screenHeight * 0.85);
	fixedText.push_back(text);

	//changable text
	hptext = std::make_shared<Text>(shader, font, "Hp: " + std::to_string(chosenOne->getHealthPoint()) + "/" + std::to_string(chosenOne->getMaxHealth()), TextColor::WHITE, 2.0);
	hptext->Set2DPosition(Globals::screenWidth * 0.05, Globals::screenHeight * 0.55);

	totalPow = std::make_shared<Text>(shader, font, "Pow: " + std::to_string(chosenOne->getPower()), TextColor::WHITE, 2.0);
	totalPow->Set2DPosition(Globals::screenWidth * 0.6, Globals::screenHeight * 0.1);

	totalHit = std::make_shared<Text>(shader, font, "Hit: " + std::to_string(chosenOne->getHitRate()), TextColor::WHITE, 2.0);
	totalHit->Set2DPosition(Globals::screenWidth * 0.6, Globals::screenHeight * 0.2);

	totalCrit = std::make_shared<Text>(shader, font, "Crit: " + std::to_string(chosenOne->getCritRate()), TextColor::WHITE, 2.0);
	totalCrit->Set2DPosition(Globals::screenWidth * 0.8, Globals::screenHeight * 0.1);

	range1 = std::make_shared<Text>(shader, font, "", TextColor::WHITE, 2.0);
	range1->Set2DPosition(Globals::screenWidth * 0.8, Globals::screenHeight * 0.2);

	if (chosenOne->getEquipment() != nullptr) {
		auto temp = chosenOne->getEquipment();
		if (temp->getMinRange() == temp->getMaxRange()) {
			range1->SetText("Range: " + std::to_string(temp->getMinRange()));
		}
		else range1->SetText("Range: " + std::to_string(temp->getMinRange()) + " - " + std::to_string(temp->getMaxRange()));
	}

	pow = std::make_shared<Text>(shader, font, "", TextColor::WHITE, 2.0);
	pow->Set2DPosition(Globals::screenWidth * 0.1, Globals::screenHeight * 0.95);

	hit = std::make_shared<Text>(shader, font, "", TextColor::WHITE, 2.0);
	hit->Set2DPosition(Globals::screenWidth * 0.3, Globals::screenHeight * 0.95);

	crit = std::make_shared<Text>(shader, font, "", TextColor::WHITE, 2.0);
	crit->Set2DPosition(Globals::screenWidth * 0.5, Globals::screenHeight * 0.95);

	range2 = std::make_shared<Text>(shader, font, "", TextColor::WHITE, 2.0);
	range2->Set2DPosition(Globals::screenWidth * 0.7, Globals::screenHeight * 0.95);

	description = std::make_shared<Text>(shader, font, "", TextColor::WHITE, 2.0);
	description->Set2DPosition(Globals::screenWidth * 0.1, Globals::screenHeight * 0.95);

	option1text = std::make_shared<Text>(shader, font, "", TextColor::WHITE, 2.0);
	option1text->Set2DPosition(Globals::screenWidth * 0.1, Globals::screenHeight * 0.45);

	option2text = std::make_shared<Text>(shader, font, "Discard (S)", TextColor::WHITE, 2.0);
	option2text->Set2DPosition(Globals::screenWidth * 0.1, Globals::screenHeight * 0.75);

	refreshItem();
	switchItem(pointerPos);
}

void GSInfo::Exit()
{
}

void GSInfo::Pause()
{
}

void GSInfo::Resume()
{
}

void GSInfo::HandleEvents()
{
}

void GSInfo::HandleKeyEvents(int key, bool bIsPressed)
{
	if (bIsPressed) {
		switch (key)
		{
		case KEY_MOVE_BACKWORD:
			if (currentState == 1) {
				chosenOne->m_itemList.remove(chosenItem);
				if (chosenItem == chosenOne->getEquipment()) {
					chosenOne->unequip(chosenItem);
				}
				refreshItem();
				switchItem(1);
				pointerPos = 1;
				currentState = 0;
				break;
			}
		case KEY_DOWN:
			if (currentState == 0 && totalItem > 0) {
				if (pointerPos == totalItem) {
					pointerPos = 1;
					switchItem(pointerPos);
				}
				else {
					pointerPos++;
					switchItem(pointerPos);
				}
			}
			break;
		case KEY_MOVE_FORWORD:
			if (currentState == 1) {
				if (isWeapon || chosenItem->getItemName() == "staff") {
					if (chosenItem == chosenOne->getEquipment()) {
						chosenOne->unequip(chosenItem);
					}
					else {
						chosenOne->equip(chosenItem);
					}
				}
				else {
					chosenItem->effect(chosenOne);
					chosenItem->reduceDurability(1);
					if (chosenItem->getDurability() == 0) {
						chosenOne->m_itemList.remove(chosenItem);
					}
					chosenOne->setFinishTurn(true);
					currentState = 2;
					
				}
				refreshItem();
				switchItem(1);
				pointerPos = 1;
				if (currentState == 2) break;
				currentState = 0;
				break;
			}
		case KEY_UP:
			if (currentState == 0 && totalItem > 0) {
				if (pointerPos == 1) {
					pointerPos = totalItem;
					switchItem(pointerPos);
				}
				else {
					pointerPos--;
					switchItem(pointerPos);
				}
			}
			break;
		case KEY_ENTER:
			if (currentState == 0 && totalItem > 0 && !readOnly) {
				currentState = 1;
				if (isWeapon || chosenItem->getItemName() == "staff") {
					option1text->SetText("Equip (W)");
					if (chosenItem == chosenOne->getEquipment()) {
						option1text->SetText("Remove (W)");
					}
				}
				else {
					option1text->SetText("Use (W)");
				}
			}
			break;
		case KEY_BACK:
			if (currentState == 0) {
				GameStateMachine::GetInstance()->PopState();
			}
			else if (currentState == 1) {
				currentState = 0;
			}
			break;
		default:
			break;
		}
	}
}

void GSInfo::HandleTouchEvents(int x, int y, bool bIsPressed)
{
}

void GSInfo::HandleMouseMoveEvents(int x, int y)
{
}

void GSInfo::Update(float deltaTime)
{
	if (currentState == 2) {
		m_time += deltaTime;
		if (m_time > 0.4) {
			m_time = 0;
			AssetManager::GetInstance()->itemEnd = true;
			GameStateMachine::GetInstance()->PopState();
		}
	}
	hptext->SetText("Hp: " + std::to_string(chosenOne->getHealthPoint()) + "/" + std::to_string(chosenOne->getMaxHealth()));
}

void GSInfo::Draw()
{
	background->Draw();
	box1->Draw();
	box2->Draw();
	chosenOne->Draw();
	
	for (auto it : fixedText) {
		it->Draw();
	}

	//other text
	hptext->Draw();
	totalPow->Draw(); totalHit->Draw(); totalCrit->Draw(); range1->Draw();
	for (auto it : itemsText) {
		it->Draw();
	}
	if (totalItem > 0) {
		itemPointer->Draw();
	}
	if (isWeapon) {
		pow->Draw(); crit->Draw(); hit->Draw(); range2->Draw();
	}
	else {
		description->Draw();
	}
	if (currentState == 1) {
		option1->Draw();
		option2->Draw();
		option1text->Draw();
		option2text->Draw();
	}
}

void GSInfo::refreshItem()
{
	itemsText.clear();
	int counter = 0;
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Ramaraja-Regular.ttf");
	std::shared_ptr<Text> temp;
	for (auto it : chosenOne->m_itemList) {
		temp = std::make_shared<Text>(AssetManager::GetInstance()->shaderText, font, 
			it->getItemName() + "  " + std::to_string(it->getDurability()) + "/" + std::to_string(it->getMaxDurability()), TextColor::WHITE, 2.0);
		temp->Set2DPosition(posX2, posY[counter]);
		itemsText.push_back(temp);
		if (it == chosenOne->getEquipment()) {
			temp = std::make_shared<Text>(AssetManager::GetInstance()->shaderText, font, "E", TextColor::RED, 1.5);
			temp->Set2DPosition(posX1, posY[counter]);
			itemsText.push_back(temp);
		}
		counter++;
	}
	totalItem = counter;
	totalPow->SetText("Pow: " + std::to_string(chosenOne->getPower()));
	totalCrit->SetText("Crit: " + std::to_string(chosenOne->getCritRate()));
	totalHit->SetText("Hit: " + std::to_string(chosenOne->getHitRate()));

	auto equip = chosenOne->getEquipment();
	if (equip == nullptr) range1->SetText("Range: --");
	else {
		if (equip->getMinRange() == equip->getMaxRange()) {
			range1->SetText("Range: " + std::to_string(equip->getMinRange()));
		}
		else range1->SetText("Range: " + std::to_string(equip->getMinRange()) + " - " + std::to_string(equip->getMaxRange()));
	}
}

void GSInfo::switchItem(GLint pos)
{
	itemPointer->Set2DPosition(Globals::screenWidth * 0.8, posY[pos - 1]);
	int counter = 1;
	for (auto it : chosenOne->m_itemList) {
		if (pos == counter) {
			chosenItem = it;
			break;
		}
		else counter++;
	}
	if (totalItem == 0) return;
	if (chosenItem->getType() == "Consumable" || chosenItem->getType() == "staff") {
		description->SetText(chosenItem->getDescription());
		isWeapon = false;
	}
	else {
		isWeapon = true;
		pow->SetText("Pow: " + std::to_string(chosenItem->getPower()));
		hit->SetText("Hit: " + std::to_string(100 + chosenItem->getHitRate()));
		crit->SetText("Crit: " + std::to_string(chosenItem->getCritRate()));
		if (chosenItem->getMinRange() == chosenItem->getMaxRange()) {
			range2->SetText("Range: " + std::to_string(chosenItem->getMinRange()));
		}
		else range2->SetText("Range: " + std::to_string(chosenItem->getMinRange()) + " - " + std::to_string(chosenItem->getMaxRange()));
	}
}
