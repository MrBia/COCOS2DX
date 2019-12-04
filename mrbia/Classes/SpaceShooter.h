#pragma once
#include "Objject.h"
#include "Bullet.h"

class SpaceShooter : public Objject
{
private:
	int num_bullet;
	std::list<Objject*> m_bullet;
public:
	void Shoot();
	void Collision();
	void Init();
	void Update(float deltaTime);
	SpaceShooter(Scene* scene);
	~SpaceShooter();
};

