#pragma once
#include "THighBus.h"

extern HDC hdc;

void HighBus::DrawWindow(Color color)
{
	HBRUSH hBrush = CreateSolidBrush(RGB(color.x, color.y, color.z));//Создаём кисть синего цвета
	SelectObject(hdc, hBrush);

	int Midlcoor = point.GetY() + high / 4;//Координата верхней четверти высоты корпуса автобуса

	// Нарисуем прямоугольник установленным цветом
	for (int i = point.GetX() + lenght / 4; i < point.GetX() + lenght; i += lenght / 2)
	{
		RECT rect = { i - 45 ,Midlcoor- 40,i + 45,Midlcoor + 40 };
		FillRect(hdc, &rect, hBrush);
		rect = { i - 45 ,Midlcoor- 40 + high / 2,i + 45,Midlcoor + 40 + high / 2};
		FillRect(hdc, &rect, hBrush);
	}

	// Уничтожим нами созданные объект  


	DeleteObject(hBrush);
}

void HighBus2::DrawWindow(Color color)
{
	HBRUSH hBrush = CreateSolidBrush(RGB(color.x, color.y, color.z));//Создаём кисть синего цвета
	SelectObject(hdc, hBrush);

	int Midlcoor = point.GetY() + high / 4;//Координата верхней четверти высоты корпуса автобуса

	// Нарисуем прямоугольник установленным цветом
	for (int i = point.GetX() + lenght / 4; i < point.GetX() + lenght; i += lenght / 2)
	{
		RECT rect = { i - 45 ,Midlcoor - 40,i + 45,Midlcoor + 40 };
		FillRect(hdc, &rect, hBrush);
		rect = { i - 45 ,Midlcoor - 40 + high / 2,i + 45,Midlcoor + 40 + high / 2 };
		FillRect(hdc, &rect, hBrush);
	}

	// Уничтожим нами созданные объект  


	DeleteObject(hBrush);
}