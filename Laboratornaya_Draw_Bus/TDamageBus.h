#pragma once
#include "TBus.h"

class DamageBus : public Bus
{
public:
	DamageBus(int high, int lenght, Color color, Point point) : Bus(high, lenght, color, point) { Speed = 5; };
	
	virtual void DrawWheel(Point LeftPoint, Color color);
private:

};

class DamageBus2 : public Bus2
{
public:
	DamageBus2(int high, int lenght, Color color, Point point) : Bus2(high, lenght, color, point) { Speed = 5; };

	virtual void DrawWheel(Point LeftPoint, Color color);
private:

};