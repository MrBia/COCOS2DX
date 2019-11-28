
#ifndef __SUB_SCENE_H__
#define __SUB_SCENE_H__

#include "cocos2d.h"

class subScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
