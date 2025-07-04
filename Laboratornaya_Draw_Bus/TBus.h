#pragma once
#include <Windows.h>
#include "Point.h"
#include "Color.h"

class Bus : public Point
{
public:
	 Bus(int xhigh, int xlenght, Color xcolor, Point xpoint);
	 virtual void Show();
	 virtual void Hide();
	 virtual void DrawWindow(Color color);//Рисование окна
	 virtual void DrawBody(Color color);//Рисовнание тела автобуса
	 virtual void DrawWheel(Point LeftPoint,Color color);//Рисование колеса
	 virtual void MoveTo(int Key);//Функция отвечает за движение фигурки по игровому полю
	 void SetTo(int x, int y);//Функция отвечает за установку фигурки на необходимую позицию 
	 int GetFloorCoor();//Получим координату пола, для корректного рисвоания дороги
	 Point GetCorrectPosition() const;//Получим позицию автобуса на данный момент
	 int GetLenght() const;//Получим длину автобуса
	 int GetHigh() const;//Получим высоту автобуса
	 

protected:
	Point startPoint;//Первоначальная позиция автобуса
	int high;//Высота автобуса
	int lenght;//Длина автобуса
	Color color;//Цвет автобуса
	Point point;//Текущая позиция корпуса(Левая верхняя координата)
	int Radius = 30;//Радиус колеса
	int Speed;
};

class IBus
{
	virtual void DrawWindow(Color color) = 0;
	virtual void DrawBody(Color color) = 0;
	virtual void DrawWheel(Point LeftPoint, Color color) = 0;
};

class Bus2 : public Point, public IBus
{
public:
	Bus2(int xhigh, int xlenght, Color xcolor, Point xpoint);
	virtual void Show();
	virtual void Hide();
	virtual void DrawWindow(Color color);//Рисование окна
	virtual void DrawBody(Color color);//Рисовнание тела автобуса
	virtual void DrawWheel(Point LeftPoint, Color color);//Рисование колеса
	virtual void MoveTo(int Key);//Функция отвечает за движение фигурки по игровому полю
	void SetTo(int x, int y);//Функция отвечает за установку фигурки на необходимую позицию 
	int GetFloorCoor();//Получим координату пола, для корректного рисвоания дороги
	Point GetCorrectPosition() const;//Получим позицию автобуса на данный момент
	int GetLenght() const;//Получим длину автобуса
	int GetHigh() const;//Получим высоту автобуса


protected:
	Point startPoint;//Первоначальная позиция автобуса
	int high;//Высота автобуса
	int lenght;//Длина автобуса
	Color color;//Цвет автобуса
	Point point;//Текущая позиция корпуса(Левая верхняя координата)
	int Radius = 30;//Радиус колеса
	int Speed;
};