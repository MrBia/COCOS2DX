#include "MainMenuScene.h"

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

	// get size
	auto visibleSize = Director::getInstance()->getVisibleSize();


	// btn play
	auto button = ui::Button::create("btn_Play.png", "");
	button->setPosition(Vec2(visibleSize.width/2, visibleSize.height / 2 + 50));
	button->setScale(0.2);
	

	button->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type) {
		case ui::Widget::TouchEventType::BEGAN: {
			Director::getInstance()->replaceScene(GamePlayScene::createGamePlay());
			break; 
		}
		case ui::Widget::TouchEventType::ENDED: break;
		default: break;
		}
	});
	this->addChild(button);
	
	auto btn_Setting = ui::Button::create("btn_Setting.png", "");
	btn_Setting->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 - 50));
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

