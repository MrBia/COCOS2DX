#include "NewGame.h"



NewGame::NewGame()
{
	// create bee
	this->O_bee = new Bee(this);
	
	// create list item
	OObject* item;
	for (int i = 0; i < this->numItem; i++) {
		item = new IItem(this);
		this->listItem.push_back(item);
	}

	// create dog
	dog = new Dog(this);

	// Vector
	VecX = 0;
	VecY = 0;

	// distance move
	speed_bee = 0;
	tlx = 0;
	tly = 0;
}


NewGame::~NewGame()
{
	delete this->O_bee;

	/*std::list<OObject*>::iterator i = listItem.begin();
	while (i != listItem.end()) {
		delete *i;
	}*/
}

cocos2d::Scene * NewGame::createNewGame()
{
	return NewGame::create();
}

bool NewGame::init()
{
	if (!Scene::init()) {
		return false;
	}


	// coin
	spriteCoin = Sprite::create();
	spriteCoin->setPosition(20, 20);
	spriteCoin->setScale(0.3);
	this->addChild(spriteCoin);

	// action coin
	Vector<SpriteFrame*> coinFrame;
	for (int i = 0; i < 6; i++) {
		coinFrame.pushBack(SpriteFrame::create("coin1.png", Rect(85 * i, 0, 85, 85)));
	}
	auto animationCoin = Animation::createWithSpriteFrames(coinFrame, 0.1);
	auto animateCoin = Animate::create(animationCoin);
	spriteCoin->runAction(RepeatForever::create(animateCoin));


	// label Score
	CCString *tempScore = CCString::createWithFormat("%i", O_bee->getMoney());
	labelScore = Label::createWithTTF(tempScore->getCString(), "fonts/Marker Felt.ttf", 20);
	labelScore->setPosition(50, 20);
	this->addChild(labelScore);


	// touch began
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(NewGame::OnTouchBegan, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);


	// update
	scheduleUpdate();

	return true;
}


bool NewGame::OnTouchBegan(Touch * touch, Event * event)
{
	// speed of bee
	speed_bee = 0.9;

	// Vector of bee
	VecX = touch->getLocation().x - O_bee->getX();
	VecY = touch->getLocation().y - O_bee->getY();

	// alpha angle
	float alpha = atan((touch->getLocation().y - O_bee->getY()) / (touch->getLocation().x - O_bee->getX()))*(180 / M_PI);

	float alpha1;
	if (touch->getLocation().x < O_bee->getX()) {
		alpha1 = 180 + (90 - alpha);
	}
	else {
		alpha1 = 90 - alpha;
	}


	// x move   y move
	tlx = speed_bee * cos(alpha*(M_PI/180));
	tly = speed_bee * sin(alpha*(M_PI / 180));

	if (tly > 0 && touch->getLocation().x < O_bee->getX() && touch->getLocation().y < O_bee->getY()) {
		tlx = -tlx;
		tly = -tly;
	}
	else if (tly < 0) {
		if (touch->getLocation().x < O_bee->getX()) {
			tlx = -tlx;
			tly = -tly;
		}
		else if (touch->getLocation().y < O_bee->getY()) {
			//tly = -tly;
		}
	}

	

	// rotate
	auto rota = RotateTo::create(0.05, alpha1);
	O_bee->getSprite()->runAction(rota);
	
	return false;
}



void NewGame::update(float deltaTime)
{
	// update bee position
	O_bee->getSprite()->setPosition(Vec2(O_bee->getX() + tlx, O_bee->getY() + tly));
	O_bee->setX(O_bee->getX() + tlx);
	O_bee->setY(O_bee->getY() + tly);

	// update item position
	std::list<OObject*>::iterator i;
	for (i = listItem.begin(); i != listItem.end(); i++) {
		(**i).move();
		if ((**i).getY() < -10) (**i).setY(Director::getInstance()->getVisibleSize().height + 20);
		if (checkDistance(O_bee, *i)) {
			// score update
			int money = O_bee->getMoney();
			money++;
			CCString *tempScore = CCString::createWithFormat("%i", money);
			labelScore->setString(tempScore->getCString());
			O_bee->setMoney(money);

			(**i).setY(Director::getInstance()->getVisibleSize().height + 20);
		}
	}

}

bool NewGame::checkDistance(OObject * bee, OObject * item)
{
	if (distance(bee->getX(), bee->getY(), item->getX(), item->getY()) < this->dis) return true;
	return false;
}

float NewGame::distance(float x1, float y1, float x2, float y2)
{
	float dis = sqrt(abs(x2 - x1) * abs(x2 - x1) + abs(y2 - y1) * abs(y2 - y1));
	return dis;
}