#include "Bullet.h"



void Bullet::Init()
{
	this->speed = 5;
	this->setSprite(ResourceManager::getInstance()->loadSpriteById(2));
	this->getScene()->addChild(this->getSprite());
	//this->getSprite()->setPosition(SpaceShooter::getSprite()->getPosition().x, SpaceShooter::getSprite()->getPosition().y);*/
}

void Bullet::Update(float deltaTime)
{
	this->getSprite()->setPosition(this->getSprite()->getPosition().x, this->getSprite()->getPosition().y + this->speed * deltaTime);
	/*if (this->getSprite()->getPosition().y > this->getHeightScreen() + 10) {
		this->getSprite()->setPosition(SpaceShooter::getSprite()->getPosition().x, SpaceShooter::getSprite()->getPosition().y);
	}*/
}

Bullet::Bullet(Scene* scene) : Objject(scene)
{
	Init();
}


Bullet::~Bullet()
{
}
