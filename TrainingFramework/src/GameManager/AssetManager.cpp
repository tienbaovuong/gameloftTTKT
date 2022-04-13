#include "AssetManager.h"
#include "GameManager/ResourceManagers.h"
#include "Character.h"

AssetManager::AssetManager()
{
	model2D = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	shaderTexture = ResourceManagers::GetInstance()->GetShader("TextureShader");
	shaderAnimation = ResourceManagers::GetInstance()->GetShader("Animation");
	shaderText = ResourceManagers::GetInstance()->GetShader("TextShader");
	//brown box
	brownBox = ResourceManagers::GetInstance()->GetTexture("brown_box.tga");

	//battle
	slashAnimation = ResourceManagers::GetInstance()->GetTexture("BattleAnimation/SlashAnimation.tga");
	healAnimation = ResourceManagers::GetInstance()->GetTexture("BattleAnimation/HealAnimation.tga");

	//Ike
	IkeField = ResourceManagers::GetInstance()->GetTexture("character sprites/IkeField.tga");
	IkeFace = ResourceManagers::GetInstance()->GetTexture("character sprites/IkeFace.tga");
	IkeFace2 = ResourceManagers::GetInstance()->GetTexture("character sprites/IkeFace2.tga");

	//Dorcas
	DorcasField = ResourceManagers::GetInstance()->GetTexture("character sprites/DorcasField.tga");
	DorcasFace = ResourceManagers::GetInstance()->GetTexture("character sprites/DorcasFace.tga");
	DorcasFace2 = ResourceManagers::GetInstance()->GetTexture("character sprites/DorcasFace2.tga");

	//Serra
	SerraField = ResourceManagers::GetInstance()->GetTexture("character sprites/SerraField.tga");
	SerraFace = ResourceManagers::GetInstance()->GetTexture("character sprites/SerraFace.tga");
	SerraFace2 = ResourceManagers::GetInstance()->GetTexture("character sprites/SerraFace2.tga");

	//Enemy Bandit
	EnemyBanditField = ResourceManagers::GetInstance()->GetTexture("character sprites/EnemyBanditField.tga");
	BanditFace = ResourceManagers::GetInstance()->GetTexture("character sprites/BanditFace.tga");
	BanditFace2 = ResourceManagers::GetInstance()->GetTexture("character sprites/BanditFace2.tga");

	//Enemy Bandit Leader
	EnemyBanditLeaderField = ResourceManagers::GetInstance()->GetTexture("character sprites/EnemyBanditLeaderField.tga");
	BanditLeaderFace = ResourceManagers::GetInstance()->GetTexture("character sprites/BanditLeaderFace.tga");
	BanditLeaderFace2 = ResourceManagers::GetInstance()->GetTexture("character sprites/BanditLeaderFace2.tga");

	battler1 = std::make_shared<Character>();
	battler2 = std::make_shared<Character>();

	escapeBattle = false;
	battleEnd = false;
}

AssetManager::~AssetManager()
{
}
