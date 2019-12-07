#include "SpaceShooter.h"



SpaceShooter::SpaceShooter(Scene* scene) : Objject(scene)
{
	Init();
}

Sprite * SpaceShooter::clone(Sprite * sprite)
{
	auto sprite_clone = Sprite::createWithTexture(sprite->getTexture());
	return sprite_clone;
}




float SpaceShooter::getSpeed_spaceShooter()
{
	return this->speed_spaceShooter;
}

void SpaceShooter::Shoot(float deltaTime)
{
	// bullet shoot

	std::list<Objject*>::iterator j;
	for (j = this->m_bullet.begin(); j != this->m_bullet.end(); j++) {
		if ((**j).getSprite()->isVisible() == false) {
			(**j).getSprite()->setVisible(true);
			(**j).getSprite()->setPosition(this->getSprite()->getPosition().x, this->getSprite()->getPosition().y);
			break;
		}
	}
}

void SpaceShooter::Collision(vector<Objject*> rock)
{
	std::list<Objject*>::iterator i;
	for (i = this->m_bullet.begin(); i != this->m_bullet.end(); i++) {
		if ((**i).getSprite()->isVisible() == true) {
			for (int j = 0; j < rock.size(); j++) {
				float dis = this->getDistance(*i, rock[j]);
				if (isCollision(dis, rock[j], *i)) {
					log("chammmmmmmmm");
					(**i).getSprite()->setVisible(false);
					rock[j]->getSprite()->setVisible(false);
				}
			}
		}
	}
}

bool SpaceShooter::isCollision(float dis, Objject * rock, Objject * bullet)
{
	// get size of bullet and rock
	float wid_rock = rock->getSprite()->getBoundingBox().size.width;
	float hei_rock = rock->getSprite()->getBoundingBox().size.height;
	float wid_bullet = bullet->getSprite()->getBoundingBox().size.width;
	float hei_bullet = bullet->getSprite()->getBoundingBox().size.height;

	// check
	float dis_collisionX = wid_rock / 2 + wid_bullet / 2;
	float dis_collisionY = hei_rock / 2 + hei_bullet / 2;
	
	if (dis <= dis_collisionX || dis <= dis_collisionY) {
			return true;
	}
	return false;
}

float SpaceShooter::getDistance(Objject* x, Objject* y)
{
	auto pos_X = x->getSprite()->getPosition();
	auto pos_Y = y->getSprite()->getPosition();

	// (y2-y1)^2 + (x2-x1)^2
	float dis = sqrt((pos_X.x - pos_Y.x)*(pos_X.x - pos_Y.x) + (pos_X.y - pos_Y.y)*(pos_X.y - pos_Y.y));
	return dis;
}

void SpaceShooter::setPosition_Space(float x, float y)
{
	this->x_space = x;
	this->y_space = y;
}

void SpaceShooter::Init()
{
	// initial time shoot
	time_shoot = 0.2;

	// create number bullet
	this->num_bullet = 50;

	// initial space shooter speed
	speed_spaceShooter = 200;

	// initial x, y space
	x_space = 0;
	y_space = 0;


	// create space shooter
	this->setSprite(ResourceManager::getInstance()->loadSpriteById(8));
	this->getSprite()->setPosition(this->getWidthScreen() / 2, 30);
	this->getScene()->addChild(this->getSprite());


	// create list bullet
	for (int i = 0; i < num_bullet; i++) {
		Objject* bullet = new Bullet(this->getScene());
		this->m_bullet.push_back(bullet);
	}
}

void SpaceShooter::Update(float deltaTime)
{

	// bullet shoot after 0.2 s
	static float count = 0;
	count += deltaTime;

	if (count >= time_shoot) {
		Shoot(deltaTime);
		count = 0;
	}


	// update bullet 
	std::list<Objject*>::iterator i;
	for (i = this->m_bullet.begin(); i != this->m_bullet.end(); i++) {
		(**i).Update(deltaTime);
	}

	// space shooter update
	this->getSprite()->setPosition(this->getSprite()->getPosition().x + x_space * deltaTime, this->getSprite()->getPosition().y + y_space * deltaTime);
}

SpaceShooter::~SpaceShooter()
{
}
