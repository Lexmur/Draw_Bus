#pragma once
#include "TBus.h"

class LongBus : public Bus
{
public:
	//Иницилизурем поля LongBus через поля Bus
	LongBus(int high, int lenght, Color color, Point point) : Bus(high, lenght, color, point) {};
	void DrawWindow(Color color);
private:
	//int Longlenght;
};

class LongBus2 : public Bus2
{
public:
	//Иницилизурем поля LongBus через поля Bus
	LongBus2(int high, int lenght, Color color, Point point) : Bus2(high, lenght, color, point) {};
	void DrawWindow(Color color);
private:
	//int Longlenght;
};

class ModifyLongBus2 : public Bus2
{
public:
	ModifyLongBus2(int high, int lenght, Color color, Point point) : Bus2(high, lenght, color, point) {};
	virtual void Show();
	void DrawWindow(Color color);
	void DrawWheel(Point centalpoint, Color color);
};