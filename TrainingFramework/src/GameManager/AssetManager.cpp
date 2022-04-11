#include "AssetManager.h"
#include "GameManager/ResourceManagers.h"

AssetManager::AssetManager()
{
	model2D = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	shaderTexture = ResourceManagers::GetInstance()->GetShader("TextureShader");
	shaderAnimation = ResourceManagers::GetInstance()->GetShader("Animation");
	shaderText = ResourceManagers::GetInstance()->GetShader("TextShader");
	//brown box
	brownBox = ResourceManagers::GetInstance()->GetTexture("brown_box.tga");

	//Ike
	IkeField = ResourceManagers::GetInstance()->GetTexture("character sprites/IkeField.tga");

	//Dorcas
	DorcasField = ResourceManagers::GetInstance()->GetTexture("character sprites/DorcasField.tga");

	//Serra
	SerraField = ResourceManagers::GetInstance()->GetTexture("character sprites/SerraField.tga");

	//Enemy Bandit
	EnemyBanditField = ResourceManagers::GetInstance()->GetTexture("character sprites/EnemyBanditField.tga");

	//Enemy Bandit Leader
	EnemyBanditLeaderField = ResourceManagers::GetInstance()->GetTexture("character sprites/EnemyBanditLeaderField.tga");
}

AssetManager::~AssetManager()
{
}
