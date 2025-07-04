#pragma once
#include "TBus.h"

class HighBus : public Bus
{
public:
	HighBus(int high, int lenght, Color color, Point point) : Bus(high, lenght, color, point) {};
	void DrawWindow(Color color);
private:

};

class HighBus2 : public Bus2
{
public:
	HighBus2(int high, int lenght, Color color, Point point) : Bus2(high, lenght, color, point) {};
	void DrawWindow(Color color);
private:

};