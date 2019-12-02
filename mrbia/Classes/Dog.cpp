#include "Dog.h"



Dog::Dog()
{
	DoStart();
}


Dog::~Dog()
{
}

void Dog::move()
{
}

void Dog::DoStart()
{
	int wid = Director::getInstance()->getVisibleSize().width;
	int hei = Director::getInstance()->getVisibleSize().height;

	this->setX(100);
	this->setY(100);

	auto spriteDog = Sprite::create();
	spriteDog->setPosition(this->getX(), this->getY());
	spriteDog->setScale(1.5);
	this->setSprite(spriteDog);
	this->getScene()->addChild(this->getSprite());

	Vector<SpriteFrame*> frameDog;
	for (int i = 0; i < 4; i++) {
		frameDog.pushBack(SpriteFrame::create("dog.png", Rect(32 * i, 96, 32, 32)));
	}
	auto animation = Animation::createWithSpriteFrames(frameDog, 0.1f);
	auto animate = Animate::create(animation);
	spriteDog->runAction(RepeatForever::create(animate));
}

int Dog::getMoney()
{
	return 0;
}

void Dog::setMoney(int)
{
}

Dog::Dog(Scene * scene):OObject(scene)
{
}
