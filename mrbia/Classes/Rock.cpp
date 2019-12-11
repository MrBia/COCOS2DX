#include "Rock.h"


void Rock::Init()
{
	this->setBlood(BLOOD_ROCK);
	this->speed = 30;
	this->setSprite(clone(ResourceManager::getInstance()->loadSpriteById(4)));
	this->getSprite()->setPosition(this->rand_position(), this->getHeightScreen() + 20);
	this->getSprite()->removeFromParent();
	this->getScene()->addChild(this->getSprite());
}

void Rock::Update(float deltaTime)
{
	this->getSprite()->setPosition(this->getSprite()->getPosition().x, this->getSprite()->getPosition().y - speed * deltaTime);
	
	/*if (this->getSprite()->getPosition().y > 0 && this->getSprite()->isVisible() == false) {
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Sounds/fire.wav");
	}*/
	
	InitAgain();
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

float Rock::rand_position()
{
	int wid = Director::getInstance()->getVisibleSize().width;

	float r = 0 + rand() % (wid + 1);

	return r;
}

void Rock::InitAgain()
{
	if (this->getSprite()->getPosition().y < -20 || this->getSprite()->isVisible() == false) {
		this->getSprite()->setPosition(this->rand_position(), this->getHeightScreen() + 20);
		this->getSprite()->setVisible(true);
		this->setBlood(BLOOD_ROCK);
	}
}


Rock::~Rock()
{
}

void test()
{
}
