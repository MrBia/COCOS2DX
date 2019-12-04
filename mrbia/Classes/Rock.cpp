#include "Rock.h"



void Rock::Init()
{
	this->speed = 1;
	this->setSprite(ResourceManager::getInstance()->loadSpriteById(4));
	this->getSprite()->setPosition(this->getWidthScreen() / 2, this->getHeightScreen() - 10);
	this->getScene()->addChild(this->getSprite());
}

void Rock::Update(float deltaTime)
{
	this->getSprite()->setPosition(this->getSprite()->getPosition().x, this->getSprite()->getPosition().y - speed * deltaTime);
	if (this->getSprite()->getPosition().y < -20) {
		this->getSprite()->setPosition(this->getWidthScreen() / 2, this->getHeightScreen() + 20);
	}
}

Rock::Rock(Scene* scene) : Objject(scene)
{
	Init();
}


Rock::~Rock()
{
}
