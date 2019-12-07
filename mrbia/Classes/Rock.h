#pragma once
#include "Objject.h"
class Rock : public Objject
{
private:
	float speed;
	int blood;
public:
	void Init();
	void Update(float deltaTime);
	void setPosition_Space(float x, float y);
	Sprite* clone(Sprite* sprite);
	Rock(Scene* scene);
	float rand_position();
	~Rock();
};

