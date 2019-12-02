#include "IItem.h"



bool IItem::getState()
{
	return this->state;
}

void IItem::move()
{
	this->setY(this->getY() - 0.5);
	this->getSprite()->setPosition(this->getX(), this->getY());
}

void IItem::DoStart()
{
	//srand(time(NULL));
	int wid = Director::getInstance()->getVisibleSize().width;
	int hei = Director::getInstance()->getVisibleSize().height;
	float x = 5 + rand() % (wid + 1 - 5);
	this->setY(Director::getInstance()->getVisibleSize().height - 10);
	this->setX(x);
	
	Sprite* spriteItem = Sprite::create("oo.png");
	spriteItem->setPosition(this->getX(), this->getY());
	spriteItem->setScale(0.05);
	this->setSprite(spriteItem);
	this->getScene()->addChild(spriteItem);
}

int IItem::getMoney()
{
	return 0;
}

void IItem::setMoney(int money)
{
}

IItem::IItem(Scene *scene):OObject(scene)
{
	DoStart();
	this->state = true;
}

IItem::IItem()
{
}


IItem::~IItem()
{
	this->state = false;
}
