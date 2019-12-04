#pragma once
#include"cocos2d.h"
#include"ui/CocosGUI.h"

USING_NS_CC;
class MainMenuScene:public cocos2d::Scene
{
private:
	Sprite* G;
	Sprite* gameloft;
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

