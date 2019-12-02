#pragma once
#include "OObject.h"
class Dog : public OObject
{
private:

public:
	Dog(Scene* scene);
	Dog();
	~Dog();

	void move();
	void DoStart();
	int getMoney();
	void setMoney(int);
};

