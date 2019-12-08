#pragma once
#include "D:\ProjectCocos\mrbia\cocos2d\cocos\2d\CCScene.h"
#include "cocos2d.h"
#include "SpaceShooter.h"
#include "Rock.h"
#include "Bullet.h"
#include "GameOverScene.h"

USING_NS_CC;
class GamePlayScene : public Scene
{
private:
	SpaceShooter *spaceShooter;
	int num_rock;
	vector<Objject*> m_rocks;
public:
	static Scene* createGamePlay();
	virtual bool init() override;
	void update(float deltaTime) override;
	GamePlayScene();
	~GamePlayScene();
	bool OnTouchBegan(Touch* touch, Event* event);
	CREATE_FUNC(GamePlayScene);
};

