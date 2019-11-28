
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "subScene.h"

USING_NS_CC;

Scene* subScene::createScene()
{
    return subScene::create();
}


// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    

    
    

   
    return true;
}

