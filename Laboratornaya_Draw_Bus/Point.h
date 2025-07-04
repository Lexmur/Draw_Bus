#pragma once
#include <windows.h>

using namespace std;

// Макрос для проверки состояния клавиатуры – из ШАБЛОНА
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

extern HDC hdc;      // объявим  контекст устройства

class Location
{
protected:		//предоставляет возможность потомкам (производному 
	//классу) иметь доступ к частным данным
	int X;		//координата X
	int Y;		//координата Y
public:   //эти методы доступны извне всем в программе
	Location(int InitX, int InitY); //конструктор
	~Location();                    //деструктор
	int GetX();						//получить X координату точки
	void SetX(int nX);                     //Установить X координату
	int GetY();						//получить Y координату точки
	void SetY(int nY);                     //Уставновить Y координату
};//end class Location


class Point : public Location
{
public:
	Point(int InitX, int InitY);	//конструктор класса
	Point() : Location(0, 0) {}; //Конструктор по умолчанию
	~Point();						//деструктор
	virtual void MoveTo(int NewX, int NewY);//переместить фигуру	
	//виртуальные функции
	virtual void Show();              //показать фигуру ТОЧКА
	virtual void Hide();              //спрятать фигуру ТОЧКА

};//end class Point
