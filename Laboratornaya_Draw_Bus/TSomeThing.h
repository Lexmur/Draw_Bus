#pragma once
#include <Windows.h>
#include "Point.h"

class SomeThing : public Point
{
public:

	SomeThing(int xfloorcoor);
	virtual void Show() {};
	virtual void Hide() {};

	void SetTo(int xfloorcoor);

	void MoveTo();

	Point GetCorrectPoint() const;

	int GetLenght() const;

protected:
	int lenght = 0;
	int floorcoor = 0;
	int pointX = 1920;
};