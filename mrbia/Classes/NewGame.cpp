#include "NewGame.h"



NewGame::NewGame()
{
	// get size screen
	auto size_screen = Director::getInstance()->getVisibleSize();
	w_screen = size_screen.width;
	h_screen = size_screen.height;

	// create bee
	this->O_bee = new Bee(w_screen, h_screen);
	
	// create list item
	OObject* item;
	for (int i = 0; i < this->numItem; i++) {
		item = new IItem(w_screen, h_screen);
		this->listItem.push_back(item);
	}

	// Vector
	VecX = 0;
	VecY = 0;
}


NewGame::~NewGame()
{
	delete this->O_bee;

	std::list<OObject*>::iterator i = listItem.begin();
	while (i != listItem.end()) {
		delete *i;
	}
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


	// bee
	spriteBee = Sprite::create();
	spriteBee->setPosition(O_bee->getX(), O_bee->getY());
	spriteBee->setScale(0.5);
	this->addChild(spriteBee);

	// action bee
	cocos2d::Vector<cocos2d::SpriteFrame*> animateFrames;
	animateFrames.pushBack(SpriteFrame::create("bee1.png", cocos2d::Rect(0, 0, 150, 150)));
	animateFrames.pushBack(SpriteFrame::create("bee2.png", cocos2d::Rect(0, 0, 150, 150)));
	animateFrames.pushBack(SpriteFrame::create("bee3.png", cocos2d::Rect(0, 0, 150, 150)));

	auto animation = Animation::createWithSpriteFrames(animateFrames, 0.1f);
	auto animate = Animate::create(animation);
	spriteBee->runAction(RepeatForever::create(animate));


	// list Item
	spriteItem = Sprite::create("oo.png");
	spriteItem->setScale(0.05);
	std::list<OObject*>::iterator i;
	for (i = listItem.begin(); i != listItem.end(); i++) {
		auto sprite = Sprite::create("oo.png");
		sprite->setPosition((**i).getX(), (**i).getY());
		sprite->setScale(0.05);
		this->addChild(sprite);
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
	// score update
	int money = O_bee->getMoney();
	money++;
	CCString *tempScore = CCString::createWithFormat("%i", money);
	labelScore->setString(tempScore->getCString());
	O_bee->setMoney(money);

	// Vector of bee
	VecX = touch->getLocation().x - O_bee->getX();
	VecY = touch->getLocation().y - O_bee->getY();

	// alpha angle
	float alpha = atan((touch->getLocation().y - O_bee->getY()) / (touch->getLocation().x - O_bee->getX()))*(180 / M_PI);
	/*log("%f", alpha);*/

	float alpha1;
	if (touch->getLocation().x < O_bee->getX()) {
		alpha1 = 180 + (90 - alpha);
	}
	else {
		alpha1 = 90 - alpha;
	}

	// rotate
	auto rota = RotateTo::create(0.05, alpha1);
	spriteBee->runAction(rota);

	return false;
}


void NewGame::update(float deltaTime)
{
	spriteBee->setPosition(Vec2(O_bee->getX() + VecX * deltaTime, O_bee->getY() + VecY * deltaTime));
	O_bee->setX(O_bee->getX() + VecX * deltaTime);
	O_bee->setY(O_bee->getY() + VecY * deltaTime);
}
