
#ifndef __SUB_SCENE_H__
#define __SUB_SCENE_H__

#include "cocos2d.h"

class subScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
	bool OnTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
	void update(float deltaTime);
    CREATE_FUNC(subScene);
};

#endif // __HELLOWORLD_SCENE_H__
