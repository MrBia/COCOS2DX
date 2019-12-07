#pragma once
#include "D:\ProjectCocos\mrbia\cocos2d\cocos\2d\CCScene.h"
#include "cocos2d.h"
#include "ui\CocosGUI.h"
#include "ResourceManager.h"

USING_NS_CC;
class GameOverScene : public Scene
{
public:
	static Scene* createSceneOver();
	virtual bool init() override;
	GameOverScene();
	~GameOverScene();
	
	CREATE_FUNC(GameOverScene);
};

