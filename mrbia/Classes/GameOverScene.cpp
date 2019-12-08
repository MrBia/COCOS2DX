#include "GameOverScene.h"



Scene * GameOverScene::createSceneOver()
{
	return GameOverScene::create();
}

bool GameOverScene::init()
{
	if (!Scene::init()) {
		return false;
	}

	auto visiblesize = Director::getInstance()->getVisibleSize();

	auto playAgain = ResourceManager::getInstance()->getButtonById(1);
	playAgain->setScale(0.7);
	playAgain->setPosition(Vec2(visiblesize.width / 2 - 50, visiblesize.height / 2));
	
	playAgain->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN: {
			Director::getInstance()->replaceScene(GamePlayScene::createGamePlay());
			break;
		}
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			break;
		default:
			break;
		}
	});
	this->addChild(playAgain);

	auto home = ResourceManager::getInstance()->getButtonById(2);
	home->setPosition(Vec2(visiblesize.width / 2 + 50, visiblesize.height / 2));
	
	home->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN: {
			Director::getInstance()->replaceScene(MainMenuScene::createMainMenu());
			break;
		}
		case cocos2d::ui::Widget::TouchEventType::ENDED: {
			break;
		}
		default:
			break;
		}
	});
	this->addChild(home);

	return true;
}

GameOverScene::GameOverScene()
{
}


GameOverScene::~GameOverScene()
{
}


