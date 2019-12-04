#include "SpaceShooter.h"



SpaceShooter::SpaceShooter(Scene* scene) : Objject(scene)
{
	Init();
}


void SpaceShooter::Shoot()
{

}

void SpaceShooter::Init()
{
	// create number bullet
	this->num_bullet = 2;

	// create space shooter
	this->setSprite(ResourceManager::getInstance()->loadSpriteById(8));
	this->getSprite()->setPosition(this->getWidthScreen() / 2, 30);
	this->getScene()->addChild(this->getSprite());

	// crate list bullet
	for (int i = 0; i < num_bullet; i++) {
		Objject* bullet = new Bullet(this->getScene());
		bullet->getSprite()->setPosition(this->getSprite()->getPosition().x, this->getSprite()->getPosition().y);
		this->m_bullet.push_back(bullet);
	}
}

void SpaceShooter::Update(float deltaTime)
{
	std::list<Objject*>::iterator i;
	for (i = this->m_bullet.begin(); i != this->m_bullet.end(); i++) {
		(**i).Update(deltaTime);
	}
}

SpaceShooter::~SpaceShooter()
{
}
