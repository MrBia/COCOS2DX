#include "Objject.h"



float Objject::getWidthScreen()
{
	return this->widthScreen;
}

float Objject::getHeightScreen()
{
	return this->heightScreen;
}

void Objject::setSprite(Sprite * sprite)
{
	this->m_sprite = sprite;
}

Sprite * Objject::getSprite()
{
	return this->m_sprite;
}

Scene * Objject::getScene()
{
	return this->scene;
}

Objject::Objject(Scene* scene)
{
	this->scene = scene;
	this->widthScreen = Director::getInstance()->getVisibleSize().width;
	this->heightScreen = Director::getInstance()->getVisibleSize().height;
}


Objject::~Objject()
{
}
