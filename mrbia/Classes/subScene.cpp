
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "subScene.h"

USING_NS_CC;

Scene* subScene::createScene()
{
    return subScene::create();
}



bool subScene::init()
{
	static int x = 0;
    if ( !Scene::init() )
    {
        return false;
    }

	auto visibaleSize = Director::getInstance()->getVisibleSize();

	sprite = Sprite::create("meo.jpg");
	if (sprite == nullptr) {
		printf("error loadding %s", "meo.jpg");
	}
	else {
		sprite->setScale(0.5);
		sprite->setPosition(Vec2(x, visibaleSize.height / 2));
		this->addChild(sprite, 0);
	}
	
	// Touch
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(subScene::OnTouchBegan, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

	/*auto mouseListener = EventListenerMouse::create();
	mouseListener->onMouseDown = CC_CALLBACK_1(subScene::OnMouseDown, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener, this);*/



	scheduleUpdate();
    return true;
}

bool subScene::OnTouchBegan(cocos2d::Touch * touch, cocos2d::Event * event)
{
	auto scene1 = HelloWorld::createScene();
	//Director::getInstance()->replaceScene(scene1);
	//Director::getInstance()->replaceScene(TransitionFlipX::create(2, scene1));
	//Director::getInstance()->replaceScene(TransitionSlideInT::create(1, scene1));
	
	Vx = touch->getLocation().x - sprite->getPosition().x;
	Vy = touch->getLocation().y - sprite->getPosition().y;

	return false;
}

bool subScene::OnMouseDown(cocos2d::Event * event)
{
	EventMouse* e = (EventMouse*)event;
	
	sprite->setPosition(Vec2(e->getLocation().x, e->getLocation().y));
	return false;
}

void subScene::update(float deltaTime)
{
	sprite->setPosition(Vec2(sprite->getPosition().x + Vx*deltaTime, sprite->getPosition().y + Vy*deltaTime));
}





