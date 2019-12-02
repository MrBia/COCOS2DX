#pragma once
#include "OObject.h"

class Bee :	public OObject
{
private:
	int blood;
	int money;
public:
	void setBlood(int blood);
	int getBlood();
	void setMoney(int money);
	int getMoney();
	void move();
	void DoStart();

	Bee(Scene* scene);
	Bee();
	~Bee();
};

