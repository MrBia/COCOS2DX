#pragma once
#include <time.h>
#include <cocos2d.h>

USING_NS_CC;
class OObject
{
private:
	float x;
	float y;
	Sprite* sprite;
	Scene* scene;
public:
	void setX(float x);
	void setY(float y);
	float getX();
	float getY();
	void setSprite(Sprite* sprite);
	Sprite * getSprite();
	Scene* getScene();



	virtual void move() = 0;
	virtual void DoStart() = 0;
	virtual int getMoney() = 0;
	virtual void setMoney(int) = 0;
	OObject(Scene* scene);
	OObject();
	~OObject();
};

