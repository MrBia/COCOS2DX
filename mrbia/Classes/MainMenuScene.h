#pragma once
#include "GamePlayScene.h"
#include "SettingScene.h"
#include "ResourceManager.h"
#include"ui/CocosGUI.h"

USING_NS_CC;
class MainMenuScene:public cocos2d::Scene
{
private:
	Menu* myMenu;
	Label* labelMenu;
	MenuItemLabel* endItem;
	MenuItemFont* itemPlay;
	MenuItemFont* itemExit;
public:
	static cocos2d::Scene* createMainMenu();
	virtual bool init() override;
	MainMenuScene();
	~MainMenuScene();
	CREATE_FUNC(MainMenuScene);
};

