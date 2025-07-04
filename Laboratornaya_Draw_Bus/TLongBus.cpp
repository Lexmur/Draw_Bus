#pragma once
#include "TLongBus.h"

extern HDC hdc;

void LongBus::DrawWindow(Color color)
{
	HBRUSH hBrush = CreateSolidBrush(RGB(color.x, color.y, color.z));//Создаём кисть синего цвета
	SelectObject(hdc, hBrush);

	int Midlcoor = point.GetY() + high / 2;//Координата середины высоты корпуса автобуса

	// Нарисуем прямоугольник установленным цветом
	for (int i = point.GetX() + lenght / 8; i < point.GetX() + lenght; i += lenght / 4)
	{
		RECT rect = { i - 45 ,Midlcoor - 40,i + 45,Midlcoor + 40 };
		FillRect(hdc, &rect, hBrush);
	}

	// Уничтожим нами созданные объект  
	DeleteObject(hBrush);
}

void LongBus2::DrawWindow(Color color)
{
	HBRUSH hBrush = CreateSolidBrush(RGB(color.x, color.y, color.z));//Создаём кисть синего цвета
	SelectObject(hdc, hBrush);

	int Midlcoor = point.GetY() + high / 2;//Координата середины высоты корпуса автобуса

	// Нарисуем прямоугольник установленным цветом
	for (int i = point.GetX() + lenght / 8; i < point.GetX() + lenght; i += lenght / 4)
	{
		RECT rect = { i - 45 ,Midlcoor - 40,i + 45,Midlcoor + 40 };
		FillRect(hdc, &rect, hBrush);
	}

	// Уничтожим нами созданные объект  
	DeleteObject(hBrush);
}

void ModifyLongBus2::DrawWindow(Color color)
{
	HBRUSH Pen = CreateSolidBrush(RGB(color.x, color.y, color.z));
	SelectObject(hdc, Pen);
	int Midlcoor = point.GetY() + high / 2;//Координата середины высоты корпуса автобуса

	// Нарисуем прямоугольник установленным цветом
	
	for (int i = point.GetX() + lenght / 8; i < point.GetX() + lenght; i += lenght / 4)
	{
		Ellipse(hdc, i - 40, Midlcoor - 40, i + 40, Midlcoor + 40);
	}

	// Уничтожим нами созданные объект  
	DeleteObject(Pen);
}

void ModifyLongBus2::DrawWheel(Point centalpoint, Color color)
{
	// Зададим цвет ручки - чёрный и ТОЛЩИНУ ручки
	HPEN Pen = CreatePen(PS_SOLID, 20, RGB(color.x, color.y, color.z));

	SelectObject(hdc, Pen);	//сделаем перо активным

	// Нарисуем кольцо установленным цветом

	for (int i = (centalpoint.GetX() - lenght/2) + lenght / 8; i < (centalpoint.GetX() - lenght / 2) + lenght; i += lenght / 4)
	{
		Ellipse(hdc, i - Radius, centalpoint.GetY() - Radius, i + Radius, centalpoint.GetY() + Radius);
	}

	// Уничтожим нами созданные объекты  
	DeleteObject(Pen);
}

void ModifyLongBus2::Show()
{
	int bottomCoor = point.GetY() + high;//Координата дна автобуса
	Point leftWheelCoor = { (int)(point.GetX() + lenght / 2.0) , bottomCoor };//Определим координату левого колеса
	Point RightWheelCoor = { (int)(point.GetX() + lenght * 3.0 / 4.0) , bottomCoor, };//Определим координату правого колеса

	DrawBody({ 255,0,0 });//Рисуем корпус автобуса
	DrawWheel(leftWheelCoor, { 0,0,0 });//Рисуем левое колесо
	//DrawWheel(RightWheelCoor, { 0,0,0 });//Рисуем правое колесо
	DrawWindow({ 0,0,255 });//Рисуем окна
}