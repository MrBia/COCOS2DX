#include "LogoScene.h"
#include<math.h>


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
	
	if (!Scene::init()) {
		return false;
	}
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

	// sprite
	mySprite = Sprite::create("mySprite.png");
	mySprite->setPosition(0, 50);
	this->addChild(mySprite, 0);

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


	// bee move
	/*auto rotate1 = RotateBy::create(0.1, 90);
	auto move1 = MoveBy::create(2, Vec2(Director::getInstance()->getVisibleSize().width/2, 0));
	auto rotate2 = RotateBy::create(0.1, -90);
	auto move2 = MoveBy::create(2, Vec2(0, Director::getInstance()->getVisibleSize().height / 2));
	auto rotate3 = RotateBy::create(0.1, -90);
	auto move3 = MoveBy::create(2, Vec2(-Director::getInstance()->getVisibleSize().width / 2, 0));
	auto rotate4 = RotateBy::create(0.1, -90);
	auto move4 = MoveBy::create(2, Vec2(0, -Director::getInstance()->getVisibleSize().height / 2));
	auto seq = Sequence::create(rotate1, move1, rotate2, move2, rotate3, move3, rotate4, move4, nullptr);
	bee->runAction(seq);*/
	//bee->runAction(seq->reverse());
	
	// update
	scheduleUpdate();

	return true;
}

bool LogoScene::OnTouchBegan(Touch* touch, Event* event) {

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
	log("%d\n", VecBeeY);
}