#pragma once
#include "D:\ProjectCocos\mrbia\cocos2d\cocos\2d\CCScene.h"
#include "cocos2d.h"
#include"ui/CocosGUI.h"

USING_NS_CC;
class MenuAbout : public Scene
{
public:
	static cocos2d::Scene* createMenuAboutScene();
	virtual bool init() override;
	MenuAbout();
	~MenuAbout();

	CREATE_FUNC(MenuAbout);
};

