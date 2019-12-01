#pragma once
#include <time.h>

class OObject
{
private:
	int x;
	int y;
	int widthScreen;
	int heightScreen;
public:
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();
	int getWidth();
	int getHeight();
	virtual void move() = 0;
	virtual void DoStart() = 0;
	virtual int getMoney() = 0;
	virtual void setMoney(int) = 0;
	OObject(int width, int height);
	OObject();
	~OObject();
};

