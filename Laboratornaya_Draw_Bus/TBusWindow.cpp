#pragma once
#include "TBusWindow.h"
#include <cmath>

extern HDC hdc;

void BusWindow::Show()
{
	HBRUSH hBrush = CreateSolidBrush(RGB(color.x, color.y, color.z));//Создаём кисть синего цвета
	SelectObject(hdc, hBrush);

	// Нарисуем прямоугольник установленным цветом
	RECT rect = { pointX - 100 ,floorcoor - 100,pointX,floorcoor };
	FillRect(hdc, &rect, hBrush);

	// Уничтожим нами созданные объект  
	DeleteObject(hBrush);
};

void BusWindow::Hide()
{
	HBRUSH hBrush = CreateSolidBrush(RGB(204, 204, 204));//Создаём кисть синего цвета
	SelectObject(hdc, hBrush);

	// Нарисуем прямоугольник установленным цветом
	RECT rect = { pointX - 100 ,floorcoor - 100,pointX,floorcoor };
	FillRect(hdc, &rect, hBrush);

	// Уничтожим нами созданные объект  
	DeleteObject(hBrush);
};

void BusWheel::Show()
{
	// Зададим цвет ручки - чёрный и ТОЛЩИНУ ручки
	HPEN Pen = CreatePen(PS_SOLID, 10, RGB(color.x, color.y, color.z));
	SelectObject(hdc, Pen);	//сделаем перо активным
	// Нарисуем треугольник установленным цветом
	POINT trianglePoint[3] =
	{
		{pointX ,floorcoor - 70},
		{pointX - 50 * sqrt(0.75), floorcoor},
		{pointX + 50 * sqrt(0.75), floorcoor}
	};
	Polygon(hdc, trianglePoint, 3);
	// Уничтожим нами созданные объекты  
	DeleteObject(Pen);
};

void BusWheel::Hide()
{
	// Зададим цвет ручки - чёрный и ТОЛЩИНУ ручки
	HPEN Pen = CreatePen(PS_SOLID, 10, RGB(204, 204, 204));
	SelectObject(hdc, Pen);	//сделаем перо активным
	// Нарисуем треугольник установленным цветом
	POINT trianglePoint[3] =
	{
		{pointX ,floorcoor - 70},
		{pointX - 50 * sqrt(0.75), floorcoor},
		{pointX + 50 * sqrt(0.75), floorcoor}
	};
	Polygon(hdc, trianglePoint, 3);
	// Уничтожим нами созданные объекты  
	DeleteObject(Pen);
};

void BusBody::Show()
{
	HBRUSH hBrush = CreateSolidBrush(RGB(color.x, color.y, color.z));//Создаём кисть красного цвета
	SelectObject(hdc, hBrush);

	// Нарисуем прямоугольник установленным цветом

	RECT rect = { pointX - 150,floorcoor - 100,pointX ,floorcoor };
	FillRect(hdc, &rect, hBrush);

	// Уничтожим нами созданные объект  
	DeleteObject(hBrush);
};

void BusBody::Hide()
{
	HBRUSH hBrush = CreateSolidBrush(RGB(204, 204, 204));//Создаём кисть красного цвета
	SelectObject(hdc, hBrush);

	// Нарисуем прямоугольник установленным цветом

	RECT rect = { pointX - 150,floorcoor - 100,pointX ,floorcoor };
	FillRect(hdc, &rect, hBrush);

	// Уничтожим нами созданные объект  
	DeleteObject(hBrush);
};