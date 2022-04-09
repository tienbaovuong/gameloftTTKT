#pragma once
#include "utilities.h" 

class Model;
class Shader;
class Texture;
class AssetManager : public CSingleton<AssetManager>
{
public:
	AssetManager();
	~AssetManager();
	//basic
	std::shared_ptr<Model> AssetManager::model2D;
	std::shared_ptr<Shader> AssetManager::shaderTexture;
	std::shared_ptr<Shader> AssetManager::shaderAnimation;
	std::shared_ptr<Shader> AssetManager::shaderText;

	//Ike
	std::shared_ptr<Texture> AssetManager::IkeField;
};

