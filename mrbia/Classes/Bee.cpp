#include "Bee.h"



void Bee::setBlood(int blood)
{
	this->blood = blood;
}

int Bee::getBlood()
{
	return this->blood;
}

void Bee::setMoney(int money)
{
	this->money = money;
}

int Bee::getMoney()
{
	return this->money;
}

void Bee::move()
{

}

void Bee::DoStart()
{
	this->setX(Director::getInstance()->getVisibleSize().width / 2);
	this->setY(20);
	this->blood = 100;
	this->money = 0;


	// bee
	auto spriteBee = Sprite::create();
	spriteBee->setPosition(this->getX(), this->getY());
	spriteBee->setScale(0.5);
	this->setSprite(spriteBee);
	this->getScene()->addChild(this->getSprite());

	// action bee
	cocos2d::Vector<cocos2d::SpriteFrame*> animateFrames;
	animateFrames.pushBack(SpriteFrame::create("bee1.png", cocos2d::Rect(0, 0, 150, 150)));
	animateFrames.pushBack(SpriteFrame::create("bee2.png", cocos2d::Rect(0, 0, 150, 150)));
	animateFrames.pushBack(SpriteFrame::create("bee3.png", cocos2d::Rect(0, 0, 150, 150)));

	auto animation = Animation::createWithSpriteFrames(animateFrames, 0.1f);
	auto animate = Animate::create(animation);
	spriteBee->runAction(RepeatForever::create(animate));
}

Bee::Bee(Scene* scene):OObject(scene)
{
	DoStart();
}

Bee::Bee()
{
}


Bee::~Bee()
{
}
