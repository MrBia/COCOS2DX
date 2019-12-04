#pragma once
#include "Objject.h"
class Rock : public Objject
{
private:
	float speed;
public:
	void Init();
	void Update(float deltaTime);
	Rock(Scene* scene);
	~Rock();
};

