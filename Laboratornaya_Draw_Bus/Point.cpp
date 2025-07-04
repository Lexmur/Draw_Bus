#pragma once
#include "Point.h"

Location::Location(int InitX, int InitY)
{
	//������������� �������� ���������� ������ ������
	X = InitX;
	Y = InitY;
};//end Location::Location()

//����������
Location::~Location(void)  //��������� ������ ����
{
};//end Location::~Location()

//�������� X ���������� �����
int Location::GetX(void)
{
	return X;
};//end Location::GetX()	

//�������� Y ���������� �����
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
//�� ������� ����������
};

//����������
Point::~Point(void)   //��������� ������ ����
{
};//end Point::~Point()


//�������� �����
void Point::Show(void)
{
	SetPixel(hdc, X, Y, RGB(255, 0, 0));	//������ ������� ������
	SetPixel(hdc, X + 1, Y, RGB(255, 0, 0));	// 4 ����� ��� ��������
	SetPixel(hdc, X, Y + 1, RGB(255, 0, 0));
	SetPixel(hdc, X + 1, Y + 1, RGB(255, 0, 0));
};//end Point::Show()


//������ �����
void Point::Hide(void)
{
	SetPixel(hdc, X, Y, RGB(0, 0, 255));//������ ����� ������ ��� ����
	SetPixel(hdc, X + 1, Y, RGB(0, 0, 255));
	SetPixel(hdc, X, Y + 1, RGB(0, 0, 255));
	SetPixel(hdc, X + 1, Y + 1, RGB(0, 0, 255));
};//end Point::Hide()


//����������� �����
void Point::MoveTo(int NewX, int NewY)
{
	Hide();		//������� ����� ���������
	X = NewX;	//�������� ���������� �����
	Y = NewY;
	Show();		//�������� ����� �� ����� �����
};//end Point::MoveTo()
