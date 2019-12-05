#pragma once
#include "D:\ProjectCocos\mrbia\cocos2d\cocos\2d\CCScene.h"
#include "cocos2d.h"
#include "ui\CocosGUI.h"
#include "ResourceManager.h"
#include "MainMenuScene.h"

USING_NS_CC;
class LoadingScene : public Scene
{
private:

public:
	LoadingScene();
	~LoadingScene();
	static cocos2d::Scene* createLoaddingScene();
	virtual bool init() override;
	void update(float deltaTime) override;

	CREATE_FUNC(LoadingScene);
};

