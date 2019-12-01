#include "LogoScene.h"
#include<math.h>
#include"IItem.h"

LogoScene::LogoScene()
{
}


LogoScene::~LogoScene()
{
}

cocos2d::Scene* LogoScene::createScene() {
	return LogoScene::create();
}

bool LogoScene::init() {
	VecBeeX = 0;
	VecBeeY = 0;
	alpha = 0;
	score = 0;
	
	if (!Scene::init()) {
		return false;
	}

	// size Screen
	auto sizeScreen = Director::getInstance()->getVisibleSize();

	// bee
	bee = Sprite::create();
	bee->setPosition(100, 100);
	bee->setScale(0.5);
	this->addChild(bee);

	// action bee
	cocos2d::Vector<cocos2d::SpriteFrame*> animateFrames;
	animateFrames.pushBack(SpriteFrame::create("bee1.png", cocos2d::Rect(0, 0, 150, 150)));
	animateFrames.pushBack(SpriteFrame::create("bee2.png", cocos2d::Rect(0, 0, 150, 150)));
	animateFrames.pushBack(SpriteFrame::create("bee3.png", cocos2d::Rect(0, 0, 150, 150)));

	auto animation = Animation::createWithSpriteFrames(animateFrames, 0.1f);
	auto animate = Animate::create(animation);
	bee->runAction(RepeatForever::create(animate));

	// coin
	coin = Sprite::create();
	coin->setPosition(20, 20);
	coin->setScale(0.3);
	this->addChild(coin);

	// action coin
	Vector<SpriteFrame*> coinFrame;
	for (int i = 0; i < 6; i++) {
		coinFrame.pushBack(SpriteFrame::create("coin1.png", Rect(85 * i, 0, 85, 85)));
	}
	auto animationCoin = Animation::createWithSpriteFrames(coinFrame, 0.1);
	auto animateCoin = Animate::create(animationCoin);
	coin->runAction(RepeatForever::create(animateCoin));

	// label Score
	CCString *tempScore = CCString::createWithFormat("%i", score);
	labelScore = Label::createWithTTF(tempScore->getCString(), "fonts/Marker Felt.ttf", 20);
	labelScore->setPosition(50, 20);
	this->addChild(labelScore);

	// honey
	honey = Sprite::create("oo.png");
	honey->setPosition(sizeScreen.width / 2, sizeScreen.height / 2);
	honey->setScale(0.05);
	this->addChild(honey);

	// logoBee
	logoBee = Sprite::create("logoBee1.jpg");
	logoBee->setAnchorPoint(Vec2(0, 0));
	logoBee->setPosition(0, 0);
	logoBee->setScale(0.1);
	//this->addChild(logoBee);

	// sprite
	mySprite = Sprite::create("mySprite.png");
	mySprite->setPosition(0, 50);
	//this->addChild(mySprite, 0);

	// load sprite frame
	auto spriteCache = SpriteFrameCache::getInstance();
	spriteCache->addSpriteFramesWithFile("ong.plist");
	auto player1 = Sprite::createWithSpriteFrameName("bee1.png");
	auto player2 = Sprite::createWithSpriteFrameName("bee2.png");
	auto player3 = Sprite::createWithSpriteFrameName("bee3.png");
	

	// touch began
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(LogoScene::OnTouchBegan, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

	
	// update
	scheduleUpdate();

	return true;
}

bool LogoScene::OnTouchBegan(Touch* touch, Event* event) {
	// score update
	score++;
	CCString *tempScore = CCString::createWithFormat("%i", score);
	labelScore->setString(tempScore->getCString());


	VecBeeX = touch->getLocation().x - bee->getPosition().x;
	VecBeeY = touch->getLocation().y - bee->getPosition().y;

	alpha = atan((touch->getLocation().y - bee->getPosition().y) / (touch->getLocation().x - bee->getPosition().x))*(180/M_PI);
	log("%f", alpha);
	
	float alpha1;
	if (touch->getLocation().x < bee->getPosition().x) {
		alpha1 = 180 + (90 - alpha);
	}
	else {
		alpha1 = 90 - alpha;
	}
	auto rota = RotateTo::create(0.05, alpha1);
	bee->runAction(rota);

	return false;
}

void LogoScene::update(float deltaTime) {


	bee->setPosition(Vec2(bee->getPosition().x + VecBeeX*deltaTime, bee->getPosition().y + VecBeeY*deltaTime));
	//log("%d\n", VecBeeY);
}