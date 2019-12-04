#pragma once
#include "D:\ProjectCocos\mrbia\cocos2d\cocos\2d\CCScene.h"
#include "cocos2d.h"
#include "SpaceShooter.h"
#include "Rock.h"
#include "Bullet.h"

USING_NS_CC;
class GamePlayScene : public Scene
{
private:
	SpaceShooter *spaceShooter;
	Rock * rock;
public:
	static Scene* createGamePlay();
	virtual bool init() override;
	void update(float deltaTime) override;
	GamePlayScene();
	~GamePlayScene();

	CREATE_FUNC(GamePlayScene);
};

