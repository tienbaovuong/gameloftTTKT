#pragma once
#include "utilities.h" 

class Model;
class Shader;
class Texture;
class Character;
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
	//brown box
	std::shared_ptr<Texture> AssetManager::brownBox;
	//battle
	std::shared_ptr<Texture> AssetManager::slashAnimation;
	std::shared_ptr<Texture> AssetManager::healAnimation;

	//Ike
	std::shared_ptr<Texture> AssetManager::IkeField;
	std::shared_ptr<Texture> AssetManager::IkeFace;
	std::shared_ptr<Texture> AssetManager::IkeFace2;

	//Dorcas
	std::shared_ptr<Texture> AssetManager::DorcasField;
	std::shared_ptr<Texture> AssetManager::DorcasFace;
	std::shared_ptr<Texture> AssetManager::DorcasFace2;

	//Serra
	std::shared_ptr<Texture> AssetManager::SerraField;
	std::shared_ptr<Texture> AssetManager::SerraFace;
	std::shared_ptr<Texture> AssetManager::SerraFace2;

	//Enemy Bandit
	std::shared_ptr<Texture> AssetManager::EnemyBanditField;
	std::shared_ptr<Texture> AssetManager::BanditFace;
	std::shared_ptr<Texture> AssetManager::BanditFace2;

	//Enemy Bandit Leader
	std::shared_ptr<Texture> AssetManager::EnemyBanditLeaderField;
	std::shared_ptr<Texture> AssetManager::BanditLeaderFace;
	std::shared_ptr<Texture> AssetManager::BanditLeaderFace2;

	std::shared_ptr<Character> AssetManager::battler1;
	std::shared_ptr<Character> AssetManager::battler2;
	GLint eva1, def1, res1, eva2, def2, res2;
};

