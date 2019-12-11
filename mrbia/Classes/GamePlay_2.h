#pragma once
#include "D:\ProjectCocos\mrbia\cocos2d\cocos\2d\CCScene.h"
#include "cocos2d.h"
#include "SpaceShooter.h"
#include "Rock.h"
#define NUMBER_ROCK 5


USING_NS_CC;
class GamePlay_2 : public Scene
{
private:
	SpaceShooter *spaceShooter;
	int num_rock;
	vector<Objject*> m_rocks;
	int score;
	Label* labelScore;
public:
	static Scene* createGameplay();
	virtual bool init() override;
	void update(float deltaTime) override;
	GamePlay_2();
	~GamePlay_2();
	void OnKeyPressed(EventKeyboard::KeyCode keycode, Event* event);
	bool OnContactBegin(PhysicsContact	&contact);
	Sprite* clone(Sprite* sprite);
	CREATE_FUNC(GamePlay_2);
};

