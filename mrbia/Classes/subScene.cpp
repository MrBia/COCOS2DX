
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
   
    if ( !Scene::init() )
    {
        return false;
    }

	auto visibaleSize = Director::getInstance()->getVisibleSize();

	auto sprite = Sprite::create("meo.jpg");
	if (sprite == nullptr) {
		printf("error loadding %s", "meo.jpg");
	}
	else {
		sprite->setPosition(Vec2(visibaleSize.width / 2, visibaleSize.height / 2));
		this->addChild(sprite, 0);
	}
	
	// Touch
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(subScene::OnTouchBegan, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

	
	scheduleUpdate();
    return true;
}

bool subScene::OnTouchBegan(cocos2d::Touch * touch, cocos2d::Event * event)
{
	auto scene1 = HelloWorld::createScene();
	//Director::getInstance()->replaceScene(scene1);
	//Director::getInstance()->replaceScene(TransitionFlipX::create(2, scene1));
	Director::getInstance()->replaceScene(TransitionSlideInT::create(1, scene1));
	return false;
}

void subScene::update(float deltaTime)
{
	

	static int j = 0;
	j++;
	if (j == 10) {
		j = 0;
		auto scene1 = HelloWorld::createScene();
		static int jj = 0;
		auto scene2 = subScene::createScene();
		if (jj == 0) {
			jj++;
			Director::getInstance()->replaceScene(scene1);
		}
		else if (jj == 1) {
			jj++;
			//Director::getInstance()->replaceScene(scene1);
			Director::getInstance()->replaceScene(TransitionFadeDown::create(0.5, scene1));
		}
		else if (jj == 2) {
			jj = 0;
			//Director::getInstance()->replaceScene(scene1);
			Director::getInstance()->replaceScene(TransitionFlipX::create(0.5, scene1));
		}
	}
}





