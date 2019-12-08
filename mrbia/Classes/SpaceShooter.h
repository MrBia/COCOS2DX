#pragma once
#include "Objject.h"
#include "Bullet.h"
#define blodd 5

class SpaceShooter : public Objject
{
private:
	int num_bullet;
	std::list<Objject*> m_bullet;
	float x_space;
	float y_space;
	float speed_spaceShooter;
	float time_shoot;
public:
	float getSpeed_spaceShooter();
	void Shoot(float deltaTime);
	void Collision(vector<Objject*> rock);
	bool isCollision(float dis, Objject* rock, Objject* bullet);
	float getDistance(Objject* x, Objject* y);
	void setPosition_Space(float x, float y);
	void Init();
	void Update(float deltaTime);
	SpaceShooter(Scene* scene);
	Sprite* clone(Sprite* sprite);
	~SpaceShooter();
};

