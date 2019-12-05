#pragma once
#include "Objject.h"
#include "Bullet.h"

class SpaceShooter : public Objject
{
private:
	int num_bullet;
	std::list<Objject*> m_bullet;
	float x_space;
	float y_space;
	float speed_Shooter;
	float time_shoot;
public:
	float getSpeed_Shooter();
	void Shoot(float deltaTime);
	void Collision();
	void setPosition_Space(float x, float y);
	void Init();
	void Update(float deltaTime);
	SpaceShooter(Scene* scene);
	~SpaceShooter();
};

