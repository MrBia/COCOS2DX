#pragma once
#include "Objject.h"
#include "SpaceShooter.h"

class Bullet : public Objject
{
private:
	float speed;
public:
	void Init();              // virtual
	void Update(float deltaTime);
	Bullet(Scene *scene);
	~Bullet();
};

