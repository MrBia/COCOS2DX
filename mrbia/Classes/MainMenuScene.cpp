#include "MainMenuScene.h"
#include "NewGame.h"
#include "SettingScene.h"
#include "ResourceManager.h"

MainMenuScene::MainMenuScene()
{
}


MainMenuScene::~MainMenuScene()
{
}


cocos2d::Scene * MainMenuScene::createMainMenu()
{
	return MainMenuScene::create();
}

bool MainMenuScene::init()
{
	if (!Scene::init()) {
		return false;
	}

	auto sprite = ResourceManager::getInstance()->loadSpriteById(1);
	sprite->setPosition(100, 100);
	this->addChild(sprite);

	// get size
	auto visibleSize = Director::getInstance()->getVisibleSize();


	// Create Logo
	G = Sprite::create("G.png");
	G->setScale(0.3);
	G->setPosition(visibleSize.width/2, visibleSize.height/2);
	gameloft = Sprite::create("gameloft.png");
	gameloft->setScale(0.3);
	gameloft->setPosition(visibleSize.width / 2, visibleSize.height / 2 - 70);
	this->addChild(G);
	this->addChild(gameloft);


	// btn play
	auto button = ui::Button::create("btn_Play.png", "");
	button->setPosition(Vec2(visibleSize.width/2, visibleSize.height - 100));
	button->setScale(0.2);

	button->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type) {
		case ui::Widget::TouchEventType::BEGAN: {
			Director::getInstance()->replaceScene(NewGame::createNewGame());
			break; 
		}
		case ui::Widget::TouchEventType::ENDED: break;
		default: break;
		}
	});
	this->addChild(button);
	
	auto btn_Setting = ui::Button::create("btn_Setting.png", "");
	btn_Setting->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - 150));
	btn_Setting->setScale(0.2);
	
	btn_Setting->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN: {
			Director::getInstance()->replaceScene(SettingScene::createSettingScene());
			break;
		}
		case ui::Widget::TouchEventType::ENDED: {
			break;
		}
		default:
			break;
		}
	});

	this->addChild(btn_Setting);


	return true;
}

