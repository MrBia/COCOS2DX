#pragma once
#include "Objject.h"
class Rock : public Objject
{
private:
	float speed;
public:
	void Init();
	void Update(float deltaTime);
	void setPosition_Space(float x, float y);
	Rock(Scene* scene);
	~Rock();
};

