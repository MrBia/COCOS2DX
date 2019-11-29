#pragma once
#include "D:\ProjectCocos\mrbia\cocos2d\cocos\2d\CCScene.h"
#include "cocos2d.h"

USING_NS_CC;
class LogoScene :
	public cocos2d::Scene
{
private:
	Sprite* bee;
	Sprite* mySprite;
	int VecBeeX;
	int VecBeeY;
public:
	LogoScene();
	~LogoScene();
	static cocos2d::Scene* createScene();
	virtual bool init() override;
	void update(float deltaTime) override;
	bool OnTouchBegan(Touch* touch, Event* event);

	CREATE_FUNC(LogoScene);
};

