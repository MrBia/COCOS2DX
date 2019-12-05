#include "LoadingScene.h"

#include"GamePlayScene.h"

LoadingScene::LoadingScene()
{
}


LoadingScene::~LoadingScene()
{
}

cocos2d::Scene * LoadingScene::createLoaddingScene()
{
	return LoadingScene::create();
}

bool LoadingScene::init()
{
	if (!Scene::init()) {
		return false;
	}

	// logo
	auto logo = ResourceManager::getInstance()->loadSpriteById(3);
	logo->setPosition(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 2 + 70);
	this->addChild(logo);


	// loading bar
	auto loadingBar = ResourceManager::getInstance()->loadSpriteById(9);
	loadingBar->setPosition(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 2);
	this->addChild(loadingBar);

	static auto loadingBar_2 = ResourceManager::getInstance()->getLoadingBarById(0);
	loadingBar_2->setPosition(loadingBar->getPosition());
	loadingBar_2->setPercent(0);

	loadingBar_2->setDirection(ui::LoadingBar::Direction::LEFT);
	this->addChild(loadingBar_2);

	auto updateLoadingBar = CallFunc::create([]() {
		if (loadingBar_2->getPercent() < 100) {
			loadingBar_2->setPercent(loadingBar_2->getPercent() + 1);
	}
	});

	auto sequenRunUpdateLoadingBar = Sequence::createWithTwoActions(updateLoadingBar, DelayTime::create(0.05f));
	auto repeat = Repeat::create(sequenRunUpdateLoadingBar, 100);
	loadingBar_2->runAction(repeat);


	// update
	scheduleUpdate();

	return true;
}

void LoadingScene::update(float deltaTime)
{
	Sleep(1000);
	Director::getInstance()->replaceScene(MainMenuScene::createMainMenu());
}
