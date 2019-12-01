#include "IItem.h"



bool IItem::getState()
{
	return this->state;
}

void IItem::move()
{
	this->setY(this->getY() - 1);
}

void IItem::DoStart()
{
	srand(time(NULL));
	int x = 5 + rand() % (this->getWidth() + 1 - 5);
	this->setY(this->getHeight() - 10);
	this->setX(x);
}

int IItem::getMoney()
{
	return 0;
}

void IItem::setMoney(int money)
{
}

IItem::IItem(int width, int height):OObject(width, height)
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
