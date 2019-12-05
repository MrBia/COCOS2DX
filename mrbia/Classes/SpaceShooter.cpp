#include "SpaceShooter.h"



SpaceShooter::SpaceShooter(Scene* scene) : Objject(scene)
{
	Init();
}




float SpaceShooter::getSpeed_Shooter()
{
	return this->speed_Shooter;
}

void SpaceShooter::Shoot(float deltaTime)
{
	// bullet update
	std::list<Objject*>::iterator i;
	for (i = this->m_bullet.begin(); i != this->m_bullet.end(); i++) {
		if ((**i).getSprite()->isVisible() == true) {
			(**i).Update(deltaTime);
		}
		else {
			(**i).getSprite()->setPosition(this->getSprite()->getPosition().x, this->getSprite()->getPosition().y);
			(**i).getSprite()->setVisible(true);
			break;
		}
	}
}

void SpaceShooter::setPosition_Space(float x, float y)
{
	this->x_space = x;
	this->y_space = y;
}

void SpaceShooter::Init()
{
	// initial time shoot
	time_shoot = 0.05;

	// create number bullet
	this->num_bullet = 20;

	// initial space shooter speed
	speed_Shooter = 100;

	// initial x, y
	x_space = 0;
	y_space = 0;


	// create space shooter
	this->setSprite(ResourceManager::getInstance()->loadSpriteById(8));
	this->getSprite()->setPosition(this->getWidthScreen() / 2, 30);
	this->getScene()->addChild(this->getSprite());

	// create list bullet
	for (int i = 0; i < num_bullet; i++) {
		Objject* bullet = new Bullet(this->getScene());
		//bullet->getSprite()->setPosition(this->getSprite()->getPosition().x, this->getSprite()->getPosition().y - i * 30);
		this->m_bullet.push_back(bullet);
	}
}

void SpaceShooter::Update(float deltaTime)
{
	// bullet update after 10 frames
	static float count = 0;
	count += deltaTime;

	if (count >= time_shoot) {
		Shoot(deltaTime);
		count = 0;
	}

	// space shooter update
	this->getSprite()->setPosition(this->getSprite()->getPosition().x + x_space * deltaTime, this->getSprite()->getPosition().y + y_space * deltaTime);
}

SpaceShooter::~SpaceShooter()
{
}
