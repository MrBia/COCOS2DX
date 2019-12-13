#pragma once
#include "D:\ProjectCocos\mrbia\cocos2d\cocos\2d\CCScene.h"
#include "cocos2d.h"

USING_NS_CC;
class moveMap : public Layer
{
private:
	TMXTiledMap* map;
	TMXLayer* background;
	TMXLayer* ForeGround;
	TMXLayer* meta;
	Sprite* sprite;

public:
	static Scene* createMap();
	bool init() override;
	moveMap();
	~moveMap();
	void OnKeyPressed(EventKeyboard::KeyCode keycode, Event* event);
	void OnKeyReleased(EventKeyboard::KeyCode keycode, Event* event);
	void setViewPointCenter(CCPoint position);
	//void registerWithTouchDispathcher();
	void setPlayerPosition(CCPoint position);
	bool OnTouchBegan(Touch* touch, Event* event);
	CCPoint tileCoorforposition(CCPoint position);
	void update(float deltaTime);

	CREATE_FUNC(moveMap);
};

