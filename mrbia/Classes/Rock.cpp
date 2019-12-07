#include "Rock.h"



void Rock::Init()
{
	this->speed = 50;
	this->setSprite(clone(ResourceManager::getInstance()->loadSpriteById(4)));
	this->getSprite()->setPosition(this->getWidthScreen() / 2, this->getHeightScreen() - 10);
	this->getSprite()->removeFromParent();
	this->getScene()->addChild(this->getSprite());
}

void Rock::Update(float deltaTime)
{
	this->getSprite()->setPosition(this->getSprite()->getPosition().x, this->getSprite()->getPosition().y - speed * deltaTime);
	if (this->getSprite()->getPosition().y < -20) {
		this->getSprite()->setPosition(this->getWidthScreen() / 2, this->getHeightScreen() + 20);
	}
}

void Rock::setPosition_Space(float x, float y)
{
}

Sprite * Rock::clone(Sprite * sprite)
{
	auto sprite_Clone = Sprite::createWithTexture(sprite->getTexture());
	return sprite_Clone;
}

Rock::Rock(Scene* scene) : Objject(scene)
{
	Init();
}


Rock::~Rock()
{
}
