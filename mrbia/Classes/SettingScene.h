#pragma once
#include "D:\ProjectCocos\mrbia\cocos2d\cocos\2d\CCScene.h"
#include <cocos2d.h>
#include"ui/CocosGUI.h"
#include"MainMenuScene.h"

USING_NS_CC;
class SettingScene : public Scene
{
private:
	MenuItemFont* itemSound;
	MenuItemFont* itemAbout;
	Menu* myMenu;
	ui::Slider* slider;
	ui::CheckBox* checkbox;
	ui::ScrollView* scrollView;
	ui::Button* btn_return;
	ui::Button* btn_return_mainMenu;
public:
	static cocos2d::Scene* createSettingScene();
	virtual bool init() override;
	void menuSound(Ref* pSender);
	void menuAbout(Ref* pSender);
	SettingScene();
	~SettingScene();
	CREATE_FUNC(SettingScene);
};

