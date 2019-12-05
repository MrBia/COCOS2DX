#pragma once
#include <list>
#include "ResourceManager.h"

USING_NS_CC;
class Objject
{
private:
	Sprite* m_sprite;
	Scene* scene;
	float widthScreen;
	float heightScreen;
public:
	float getWidthScreen();
	float getHeightScreen();
	void setSprite(Sprite* sprite);
	Sprite* getSprite();
	Scene* getScene();
	virtual void Init() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void setPosition_Space(float x, float y) = 0;
	Objject(Scene* scene);
	~Objject();
};

