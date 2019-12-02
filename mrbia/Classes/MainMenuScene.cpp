#include "MainMenuScene.h"
#include "NewGame.h"
#include "SettingScene.h"

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

	// label Menu
	labelMenu = Label::create("MENU", "Arial", 30);
	//this->setPosition(230, 250);
	//this->addChild(labelMenu, -1);

	auto button = ui::Button::create("btn_Play.png", "");
	button->setPosition(Vec2(230, 200));
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
	btn_Setting->setPosition(Vec2(230, 150));
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

