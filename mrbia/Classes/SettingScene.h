#pragma once
#include "D:\ProjectCocos\mrbia\cocos2d\cocos\2d\CCScene.h"
#include <cocos2d.h>

USING_NS_CC;
class SettingScene : public Scene
{
private:

public:
	static cocos2d::Scene* createSettingScene();
	virtual bool init() override;
	void menuSound(Ref* pSender);
	void menuAbout(Ref* pSender);
	SettingScene();
	~SettingScene();
	CREATE_FUNC(SettingScene);
};

