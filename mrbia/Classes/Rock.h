#pragma once
#include "Objject.h"
#define BLOOD_ROCK 2
class Rock : public Objject
{
private:
	float speed;
	friend class Objject;
public:
	void Init();
	void Update(float deltaTime);
	void setPosition_Space(float x, float y);
	Sprite* clone(Sprite* sprite);
	Rock(Scene* scene);
	float rand_position();
	void InitAgain();
	friend void test();
	~Rock();
};

