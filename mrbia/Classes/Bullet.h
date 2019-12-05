#pragma once
#include "Objject.h"
#include "SpaceShooter.h"

class Bullet : public Objject
{
private:
	float speed;
	float x_spaceShooter;
	float y_spaceShooter;
public:
	void setPosition_Space(float x, float y);
	void Init();              // virtual
	void Update(float deltaTime);
	Sprite* clone(Sprite* sprite);
	Bullet(Scene *scene);
	~Bullet();
};

