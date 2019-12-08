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

	// background
	auto background = clone(ResourceManager::getInstance()->loadSpriteById(0));
	background->setScale(1.5);
	background->setPosition(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 2);
	this->addChild(background, -1);

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

	auto sequenRunUpdateLoadingBar = Sequence::createWithTwoActions(updateLoadingBar, DelayTime::create(0.01f));
	auto repeat = Repeat::create(sequenRunUpdateLoadingBar, 100);
	loadingBar_2->runAction(repeat);


	// update
	scheduleUpdate();

	return true;
}

void LoadingScene::update(float deltaTime)
{
	static float count = 0;
	count += deltaTime;
	if(count >= 4)
	Director::getInstance()->replaceScene(MainMenuScene::createMainMenu());
}

Sprite * LoadingScene::clone(Sprite * sprite)
{
	auto s_clone = Sprite::createWithTexture(sprite->getTexture());
	return s_clone;
}
