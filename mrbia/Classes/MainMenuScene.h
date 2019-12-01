#pragma once
#include"cocos2d.h"

USING_NS_CC;
class MainMenuScene:cocos2d::Scene
{
public:
	static cocos2d::Scene* createMainMenu();
	virtual bool init() override;
	bool OnTouchBegan(Touch* touch, Event* event);
	MainMenuScene();
	~MainMenuScene();
};

