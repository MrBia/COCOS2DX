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
	//this->addChild(labelMenu);

	// end Item
	endItem = MenuItemLabel::create(labelMenu, nullptr);
	endItem->setPosition(200, 400);

	// Menu Item Play
	itemPlay = MenuItemFont::create("Play", nullptr);
	itemPlay->setPosition(200, 300);

	// Menu Item Exit
	itemExit = MenuItemFont::create("Exit", CC_CALLBACK_1(MainMenuScene::menuCloseCallback, this));
	itemExit->setPosition(200, 250);

	// Menu Item Setting
	auto itemSetting = MenuItemFont::create("Setting", CC_CALLBACK_1(MainMenuScene::menuSetting, this));
	itemSetting->setPosition(200, 200);

	// Menu
	myMenu = Menu::create(itemPlay, itemExit, itemSetting, nullptr);
	myMenu->setPosition(0, 0);
	this->addChild(myMenu);

	auto button = ui::Button::create("play_normal.png", "play_pressed.png");
	button->setPosition(Vec2(200, 200));
	button->setTitleText("text");

	button->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type) {
		case ui::Widget::TouchEventType::BEGAN: {
			//Director::getInstance()->replaceScene(NewGame::createNewGame());
			break; 
		}
		case ui::Widget::TouchEventType::ENDED: break;
		default: break;
		}
	});
	//this->addChild(button);
	


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

void MainMenuScene::menuCloseCallback(Ref * pSender)
{
	exit(0);
}

void MainMenuScene::menuSetting(Ref * pSender)
{
	Director::getInstance()->replaceScene(SettingScene::createSettingScene());
}

