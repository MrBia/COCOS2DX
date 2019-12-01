#include "OObject.h"



void OObject::setX(int x)
{
	this->x = x;
}

void OObject::setY(int y)
{
	this->y = y;
}

int OObject::getX()
{
	return this->x;
}

int OObject::getY()
{
	return this->y;
}

int OObject::getWidth()
{
	return this->widthScreen;
}

int OObject::getHeight()
{
	return this->heightScreen;
}

OObject::OObject(int width, int height)
{
	this->x = 0;
	this->y = 0;
	this->widthScreen = width;
	this->heightScreen = height;
}

OObject::OObject()
{
}


OObject::~OObject()
{
}
