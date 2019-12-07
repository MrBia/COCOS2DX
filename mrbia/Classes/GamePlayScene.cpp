#include "GamePlayScene.h"



Scene * GamePlayScene::createGamePlay()
{
	return GamePlayScene::create();
}

bool GamePlayScene::init()
{
	if (!Scene::init()) {
		return false;
	}

	// initialize number rock
	this->num_rock = 5;


	// create space shooter
	this->spaceShooter = new SpaceShooter(this);


	// create list rock
	srand(time(NULL));
	for (int i = 0; i < this->num_rock; i++) {
		Objject* rock = new Rock(this);
		this->m_rocks.push_back(rock);
	}


	// touch began
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(GamePlayScene::OnTouchBegan, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

	// update
	scheduleUpdate();
	return true;
}

void GamePlayScene::update(float deltaTime)
{
	this->spaceShooter->Collision(m_rocks);

	for (int i = 0; i < this->num_rock; i++) {
		this->m_rocks[i]->Update(deltaTime);
	}

	this->spaceShooter->Update(deltaTime);
}

GamePlayScene::GamePlayScene()
{
}


GamePlayScene::~GamePlayScene()
{
	delete this->spaceShooter;
}

bool GamePlayScene::OnTouchBegan(Touch * touch, Event * event)
{
	// x shooter and y shooter
	float x_space_shooter = spaceShooter->getSprite()->getPosition().x;
	float y_space_shooter = spaceShooter->getSprite()->getPosition().y;

	float vec_x = touch->getLocation().x - x_space_shooter;
	float vec_y = touch->getLocation().y - y_space_shooter;

	// alpha angle
	float alpha = atan((touch->getLocation().y - y_space_shooter) / (touch->getLocation().x - x_space_shooter))*(180 / M_PI);

	// x move   y move
	float tlx = spaceShooter->getSpeed_spaceShooter() * cos(alpha*(M_PI / 180));
	float tly = spaceShooter->getSpeed_spaceShooter() * sin(alpha*(M_PI / 180));

	if (tly > 0 && touch->getLocation().x < x_space_shooter && touch->getLocation().y < y_space_shooter) {
		tlx = -tlx;
		tly = -tly;
	}
	else if (tly < 0) {
		if (touch->getLocation().x < x_space_shooter) {
			tlx = -tlx;
			tly = -tly;
		}
		else if (touch->getLocation().y < y_space_shooter) {
			//tly = -tly;
		}
	}

	spaceShooter->setPosition_Space(tlx, tly);

	return false;
}
