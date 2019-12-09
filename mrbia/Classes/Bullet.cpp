#include "Bullet.h"



void Bullet::setPosition_Space(float x, float y)
{
	this->x_spaceShooter = x;
	this->y_spaceShooter = y;
}

void Bullet::Init()
{
	this->speed = 500;
	this->setSprite(clone(ResourceManager::getInstance()->loadSpriteById(2)));
	this->getSprite()->removeFromParent();
	this->getScene()->addChild(this->getSprite());
	this->getSprite()->setVisible(false);
}

void Bullet::Update(float deltaTime)
{
	if (this->getSprite()->getPosition().y > this->getHeightScreen() + 0) {
		this->getSprite()->setVisible(false);
	}
	else {
		if(this->getSprite()->isVisible() == true)
		this->getSprite()->setPosition(this->getSprite()->getPosition().x, this->getSprite()->getPosition().y + this->speed * deltaTime);
	}
}

Sprite * Bullet::clone(Sprite* sprite)
{
	Sprite* cloneSprite = Sprite::createWithTexture(sprite->getTexture());
	return cloneSprite;
}

Bullet::Bullet(Scene* scene) : Objject(scene)
{
	Init();
}


Bullet::~Bullet()
{
}
