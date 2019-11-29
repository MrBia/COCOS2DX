#include "LogoScene.h"



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
	VecBeeX = 0;

	if (!Scene::init()) {
		return false;
	}
	// bee
	bee = Sprite::create();
	bee->setPosition(100, 100);
	bee->setScale(0.5);
	this->addChild(bee);

	cocos2d::Vector<cocos2d::SpriteFrame*> animateFrames;
	animateFrames.pushBack(SpriteFrame::create("bee1.png", cocos2d::Rect(0, 0, 150, 150)));
	animateFrames.pushBack(SpriteFrame::create("bee2.png", cocos2d::Rect(0, 0, 150, 150)));
	animateFrames.pushBack(SpriteFrame::create("bee3.png", cocos2d::Rect(0, 0, 150, 150)));

	auto animation = Animation::createWithSpriteFrames(animateFrames, 0.1f);
	auto animate = Animate::create(animation);
	bee->runAction(RepeatForever::create(animate));

	// sprite
	mySprite = Sprite::create("mySprite.png");
	mySprite->setPosition(50, 50);
	this->addChild(mySprite);

	auto scale = ScaleBy::create(2, 0.5);
	auto move = MoveTo::create(2, Vec2(100, 100));
	auto sequence = Sequence::create(scale, move, nullptr);
	mySprite->runAction(move);

	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(LogoScene::OnTouchBegan, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

	

	scheduleUpdate();

	return true;
}

bool LogoScene::OnTouchBegan(Touch* touch, Event* event) {
	VecBeeX = touch->getLocation().x - bee->getPosition().x;
	VecBeeY = touch->getLocation().y - bee->getPosition().y;

	//bee->setPosition(Vec2(VecBeeX, VecBeeY));

	/*static int i = 0;
	if (i == 0) {
		auto scale = ScaleBy::create(1, 1.5);
		mySprite->runAction(scale);
		if (mySprite->getScale() > 2) i = 1;
	}
	else if (i == 1) {
		auto scale = ScaleBy::create(1, 0.5);
		mySprite->runAction(scale);
		if (mySprite->getScale() < 0.1) i = 0;
	}*/

	return false;
}

void LogoScene::update(float deltaTime) {
	static int i = 1;
	/*if (i == 0) {
		auto scale = ScaleBy::create(2, 0.5);
		mySprite->runAction(scale);
		i = 1;
	}*/

	/*auto scale = ScaleBy::create(2, 3);

	auto scale1 = MoveBy::create(2, Vec2(50, 50));

	auto sequence = Sequence::create(scale, scale1);

	if (i == 1) {
		mySprite->runAction(sequence);
		i = 0;
	}*/
	

	/*static int i = 0;
	if (mySprite->getScale() > 2) {
		i = 0;
	}
	else if (mySprite->getScale() < 0) {
		i = 1;
	}
	
	if (i == 0) {
		auto scale = ScaleTo::create(deltaTime, 0.9);
		mySprite->runAction(scale);
	}
	else if (i == 1) {
		auto scale = ScaleTo::create(deltaTime, 1.1);
		mySprite->runAction(scale);
	}*/
	

	/*if (bee->getPosition().x != VecBeeX && bee->getPosition().y != VecBeeY) {
		auto moveTo = MoveTo::create(deltaTime, Vec2(bee->getPosition().x + VecBeeX * deltaTime, bee->getPosition().y + VecBeeY * deltaTime));
		bee->runAction(moveTo);
	}*/
	
}
