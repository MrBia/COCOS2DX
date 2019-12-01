#pragma once
#include "cocos2d.h"
#include <list>
#include "OObject.h"
#include "Bee.h"
#include "IItem.h"

USING_NS_CC;
class NewGame : public cocos2d::Scene
{
private:
	Sprite *spriteBee;
	Sprite *spriteItem;
	Sprite *spriteCoin;
	Label *labelScore;
	
	OObject* O_bee;
	int numItem = 5;
	int w_screen;
	int h_screen;
	int VecX;
	int VecY;
	std::list<OObject*> listItem;
public:
	static cocos2d::Scene* createNewGame();
	virtual bool init() override;
	void update(float deltaTime) override;
	bool OnTouchBegan(Touch* touch, Event* event);
	NewGame();
	~NewGame();

	CREATE_FUNC(NewGame);
};

