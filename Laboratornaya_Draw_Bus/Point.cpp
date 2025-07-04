#pragma once
#include "Point.h"

Location::Location(int InitX, int InitY)
{
	//инициализация закрытых переменных своего класса
	X = InitX;
	Y = InitY;
};//end Location::Location()

//деструктор
Location::~Location(void)  //формально пустое тело
{
};//end Location::~Location()

//получить X координату точки
int Location::GetX(void)
{
	return X;
};//end Location::GetX()	

//получить Y координату точки
int Location::GetY(void)
{
	return Y;
}; //end Location::GetY()

void Location::SetX(int nX)
{
	X = nX;
}

void Location::SetY(int nY)
{
	Y = nY;
}



Point::Point(int InitX, int InitY) : Location(InitX, InitY)
{
//Не требует дополнения
};

//деструктор
Point::~Point(void)   //формально пустое тело
{
};//end Point::~Point()


//показать ТОЧКУ
void Point::Show(void)
{
	SetPixel(hdc, X, Y, RGB(255, 0, 0));	//рисуем красным цветом
	SetPixel(hdc, X + 1, Y, RGB(255, 0, 0));	// 4 точки для удобства
	SetPixel(hdc, X, Y + 1, RGB(255, 0, 0));
	SetPixel(hdc, X + 1, Y + 1, RGB(255, 0, 0));
};//end Point::Show()


//скрыть ТОЧКУ
void Point::Hide(void)
{
	SetPixel(hdc, X, Y, RGB(0, 0, 255));//рисуем синим цветом или фона
	SetPixel(hdc, X + 1, Y, RGB(0, 0, 255));
	SetPixel(hdc, X, Y + 1, RGB(0, 0, 255));
	SetPixel(hdc, X + 1, Y + 1, RGB(0, 0, 255));
};//end Point::Hide()


//переместить ТОЧКУ
void Point::MoveTo(int NewX, int NewY)
{
	Hide();		//сделать точку невидимой
	X = NewX;	//поменять координаты ТОЧКИ
	Y = NewY;
	Show();		//показать точку на новом месте
};//end Point::MoveTo()
