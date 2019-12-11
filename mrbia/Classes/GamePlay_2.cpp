#include "GamePlay_2.h"

GamePlay_2::GamePlay_2()
{
}


GamePlay_2::~GamePlay_2()
{
}

Scene * GamePlay_2::createGameplay()
{
	return GamePlay_2::create();
}

bool GamePlay_2::init()
{
	if (!Scene::initWithPhysics()) {
		return false;
	}

	// score
	this->score = 0;

	// number rock
	this->num_rock = NUMBER_ROCK;

	// hv bao quanh doi tuong
	this->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

	// create space shooter
	this->spaceShooter = new SpaceShooter(this); 
	auto physicsBody_space = PhysicsBody::createBox(spaceShooter->getSprite()->getContentSize());
	physicsBody_space->setDynamic(false);
	spaceShooter->getSprite()->setPhysicsBody(physicsBody_space);
	spaceShooter->getSprite()->getPhysicsBody()->setContactTestBitmask(1);
	spaceShooter->getSprite()->setTag(50);
	

	// create physics for bullet
	std::list<Objject*> bullet = spaceShooter->getBullet();
	std::list<Objject*>::iterator i;

	for (i = bullet.begin(); i != bullet.end(); i++) {
		auto physicsBody_bullet = PhysicsBody::createBox((**i).getSprite()->getContentSize());
		physicsBody_bullet->setDynamic(false);
		(**i).getSprite()->setPhysicsBody(physicsBody_bullet);
		(**i).getSprite()->getPhysicsBody()->setContactTestBitmask(1);
		(**i).getSprite()->setTag(10);
	}


	// create list rock
	srand(time(NULL));
	for (int i = 0; i < this->num_rock; i++) {
		Objject* rock = new Rock(this);
		auto physicsBody_rock = PhysicsBody::createBox(rock->getSprite()->getContentSize());
		physicsBody_rock->setDynamic(true);
		physicsBody_rock->setVelocity(Vec2(5, 5));
		physicsBody_rock->setGravityEnable(true);
		rock->getSprite()->setPhysicsBody(physicsBody_rock);
		rock->getSprite()->getPhysicsBody()->setContactTestBitmask(1);
		rock->getSprite()->setTag(100);
		this->m_rocks.push_back(rock);
	}

	// label score
	CCString *tempScore = CCString::createWithFormat("%i", this->score);
	labelScore = Label::createWithTTF(tempScore->getCString(), "fonts/Marker Felt.ttf", 20);
	labelScore->setPosition(10, 10);
	this->addChild(labelScore);


	// key board
	auto keylistener = EventListenerKeyboard::create();
	keylistener->onKeyPressed = CC_CALLBACK_2(GamePlay_2::OnKeyPressed, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keylistener, this);


	// listener contact
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(GamePlay_2::OnContactBegin, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

	// update
	scheduleUpdate();

	return true;
}

void GamePlay_2::update(float deltaTime)
{
	spaceShooter->Update(deltaTime);

	for (int i = 0; i < this->num_rock; i++) {
			((Rock*)m_rocks[i])->InitAgain();
	}

	CCString *tempScore = CCString::createWithFormat("%i", this->score);
	labelScore->setString(tempScore->getCString());
}


void GamePlay_2::OnKeyPressed(EventKeyboard::KeyCode keycode, Event * event)
{
	float speed = 200;
	switch (keycode)
	{
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW: {
		spaceShooter->setPosition_Space(-speed, 0);
		break;
	}
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW: {
		spaceShooter->setPosition_Space(speed, 0);
		break;
	}
	case EventKeyboard::KeyCode::KEY_UP_ARROW: {
		spaceShooter->setPosition_Space(0, speed);
		break;
	}
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW: {
		spaceShooter->setPosition_Space(0, -speed);
		break;
	}
	default:
		break;
	}
}

bool GamePlay_2::OnContactBegin(PhysicsContact & contact)
{
	auto nodeA = contact.getShapeA()->getBody()->getNode();
	auto nodeB = contact.getShapeB()->getBody()->getNode();

	if (nodeA && nodeB) {
		if (nodeA->getTag() == 100 && nodeB->getTag() == 10) {
			nodeA->setVisible(false);
			nodeB->setVisible(false);
			this->score++;
		}
		else if (nodeB->getTag() == 100 && nodeA->getTag() == 10) {
			nodeA->setVisible(false);
			nodeB->setVisible(false);
			this->score++;
		}
		else if (nodeB->getTag() == 100 && nodeA->getTag() == 50) {
			spaceShooter->getSprite()->setVisible(false);
		}
		else if (nodeB->getTag() == 50 && nodeA->getTag() == 100) {
			spaceShooter->getSprite()->setVisible(false);
		}
	}

	return true;
}
