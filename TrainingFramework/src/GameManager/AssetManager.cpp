#include "AssetManager.h"
#include "GameManager/ResourceManagers.h"

AssetManager::AssetManager()
{
	model2D = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	shaderTexture = ResourceManagers::GetInstance()->GetShader("TextureShader");
	shaderAnimation = ResourceManagers::GetInstance()->GetShader("Animation");
	shaderText = ResourceManagers::GetInstance()->GetShader("TextShader");

	//Ike
	IkeField = ResourceManagers::GetInstance()->GetTexture("Ike.tga");
}

AssetManager::~AssetManager()
{
}
