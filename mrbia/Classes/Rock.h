#pragma once
#include "Objject.h"
#define blod 2
class Rock : public Objject
{
private:
	float speed;
public:
	void Init();
	void Update(float deltaTime);
	void setPosition_Space(float x, float y);
	Sprite* clone(Sprite* sprite);
	Rock(Scene* scene);
	float rand_position();
	~Rock();
};

