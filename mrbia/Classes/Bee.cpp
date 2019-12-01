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
	this->setX(this->getWidth() / 2);
	this->setY(20);
	this->blood = 100;
	this->money = 0;
}

Bee::Bee(int width, int height):OObject(width, height)
{
	DoStart();
}

Bee::Bee()
{
}


Bee::~Bee()
{
}
