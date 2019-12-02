#include "SettingScene.h"


SettingScene::SettingScene()
{
}


SettingScene::~SettingScene()
{
}

cocos2d::Scene * SettingScene::createSettingScene()
{
	return SettingScene::create();
}

bool SettingScene::init()
{
	if (!Scene::init()) {
		return false;
	}

	// Menu Item Sound
	auto itemSound = MenuItemFont::create("Sound", CC_CALLBACK_1(SettingScene::menuSound, this));
	itemSound->setPosition(200, 300);

	// Menu Item About
	auto itemAbout = MenuItemFont::create("About", CC_CALLBACK_1(SettingScene::menuAbout, this));
	itemAbout->setPosition(200, 250);

	// Menu
	auto myMenu = Menu::create(itemSound, itemAbout, nullptr);
	myMenu->setPosition(0, 0);
	this->addChild(myMenu);

	return true;
}

void SettingScene::menuSound(Ref * pSender)
{

}

void SettingScene::menuAbout(Ref * pSender)
{
}

