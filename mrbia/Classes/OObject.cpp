#include "OObject.h"



void OObject::setX(float x)
{
	this->x = x;
}

void OObject::setY(float y)
{
	this->y = y;
}

float OObject::getX()
{
	return this->x;
}

float OObject::getY()
{
	return this->y;
}

void OObject::setSprite(Sprite * sprite)
{
	this->sprite = sprite;
}

Sprite * OObject::getSprite()
{
	return this->sprite;
}


Scene * OObject::getScene()
{
	return this->scene;
}



OObject::OObject(Scene* scene)
{
	this->x = 0;
	this->y = 0;
	this->scene = scene;
}

OObject::OObject()
{
}


OObject::~OObject()
{
}
