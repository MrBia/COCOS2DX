#include "MainMenuScene.h"



cocos2d::Scene * MainMenuScene::createMainMenu()
{
	return MainMenuScene::create();
}

bool MainMenuScene::init()
{
	if (!Scene::create()) {
		return false;
	}


	// on touch began
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(MainMenuScene::OnTouchBegan, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

	return true;
}

bool MainMenuScene::OnTouchBegan(Touch * touch, Event * event)
{
	return false;
}

MainMenuScene::MainMenuScene()
{
}


MainMenuScene::~MainMenuScene()
{
}
