#pragma once
#include "cocos2d.h"
#include <list>
#include "OObject.h"
#include "Bee.h"
#include "IItem.h"
#include "Dog.h"

USING_NS_CC;
class NewGame : public cocos2d::Scene
{
private:
	Sprite *spriteCoin;
	Label *labelScore;
	
	OObject* O_bee;
	std::list<OObject*> listItem;
	OObject* dog;

	int numItem = 5;
	int w_screen;
	int h_screen;
	int VecX;
	int VecY;
	int dis = 20;
	float speed_bee;
	float tlx;
	float tly;
public:
	static cocos2d::Scene* createNewGame();
	virtual bool init() override;
	void update(float deltaTime) override;
	bool OnTouchBegan(Touch* touch, Event* event);
	bool checkDistance(OObject *bee, OObject *item);
	float distance(float x1, float y1, float x2, float y2);
	NewGame();
	~NewGame();

	CREATE_FUNC(NewGame);
};

