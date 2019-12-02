#pragma once
#include "D:\ProjectCocos\mrbia\cocos2d\cocos\2d\CCScene.h"
#include "cocos2d.h"
#include"ui/CocosGUI.h"


USING_NS_CC;
class MenuSound : public Scene
{
public:
	static cocos2d::Scene* createMenuSoundScene();
	virtual bool init() override;

	MenuSound();
	~MenuSound();

	CREATE_FUNC(MenuSound);
};

