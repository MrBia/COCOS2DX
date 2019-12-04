#include "GamePlayScene.h"



Scene * GamePlayScene::createGamePlay()
{
	return GamePlayScene::create();
}

bool GamePlayScene::init()
{
	if (!Scene::init()) {
		return false;
	}

	this->spaceShooter = new SpaceShooter(this);
	this->rock = new Rock(this);

	scheduleUpdate();
	return true;
}

void GamePlayScene::update(float deltaTime)
{
	this->rock->Update(deltaTime);
	this->spaceShooter->Update(deltaTime);
}

GamePlayScene::GamePlayScene()
{
}


GamePlayScene::~GamePlayScene()
{
	delete this->spaceShooter;
	delete this->rock;
}
