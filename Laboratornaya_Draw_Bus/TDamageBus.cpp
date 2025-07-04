#pragma once
#include "TDamageBus.h"
#include <cmath>
#include <iostream>

extern HDC hdc;

void DamageBus::DrawWheel(Point WheelPoint, Color color)
{
	// Зададим цвет ручки - чёрный и ТОЛЩИНУ ручки
	HPEN Pen = CreatePen(PS_SOLID, 10, RGB(color.x, color.y, color.z));

	SelectObject(hdc, Pen);	//сделаем перо активным

	// Нарисуем треугольник установленным цветом


	POINT trianglePoint[3] =
	{
		{WheelPoint.GetX() ,WheelPoint.GetY() - Radius},
		{WheelPoint.GetX() - Radius * sqrt(0.75), WheelPoint.GetY() + Radius / 2},
		{WheelPoint.GetX() + Radius * sqrt(0.75), WheelPoint.GetY() + Radius / 2}
	};
	Polygon(hdc, trianglePoint, 3);

	// Уничтожим нами созданные объекты  
	DeleteObject(Pen);
}

void DamageBus2::DrawWheel(Point WheelPoint, Color color)
{
	// Зададим цвет ручки - чёрный и ТОЛЩИНУ ручки
	HPEN Pen = CreatePen(PS_SOLID, 10, RGB(color.x, color.y, color.z));

	SelectObject(hdc, Pen);	//сделаем перо активным

	// Нарисуем треугольник установленным цветом


	POINT trianglePoint[3] =
	{
		{WheelPoint.GetX() ,WheelPoint.GetY() - Radius},
		{WheelPoint.GetX() - Radius * sqrt(0.75), WheelPoint.GetY() + Radius / 2},
		{WheelPoint.GetX() + Radius * sqrt(0.75), WheelPoint.GetY() + Radius / 2}
	};
	Polygon(hdc, trianglePoint, 3);

	// Уничтожим нами созданные объекты  
	DeleteObject(Pen);
}