#include "GameOverScene.h"



Scene * GameOverScene::createSceneOver()
{
	return GameOverScene::create();
}

bool GameOverScene::init()
{
	if (!Scene::init()) {
		return false;
	}

	auto playAgain = ResourceManager::getInstance()->getButtonById(1);
	playAgain->setPosition(Vec2(100, 100));
	this->addChild(playAgain);

	auto home = ResourceManager::getInstance()->getButtonById(2);
	home->setPosition(Vec2(300, 300));
	this->addChild(home);

	return true;
}

GameOverScene::GameOverScene()
{
}


GameOverScene::~GameOverScene()
{
}


