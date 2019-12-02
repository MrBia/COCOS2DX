#pragma once
#include "OObject.h"
#include<cstdlib>

class IItem : public OObject
{
private:
	bool state;
public:
	bool getState();
	void move();
	void DoStart();
	int getMoney();
	void setMoney(int money);
	IItem(Scene *scene);
	IItem();
	~IItem();
};

