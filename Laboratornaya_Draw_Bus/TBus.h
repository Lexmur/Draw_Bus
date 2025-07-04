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
	 virtual void DrawWindow(Color color);//��������� ����
	 virtual void DrawBody(Color color);//���������� ���� ��������
	 virtual void DrawWheel(Point LeftPoint,Color color);//��������� ������
	 virtual void MoveTo(int Key);//������� �������� �� �������� ������� �� �������� ����
	 void SetTo(int x, int y);//������� �������� �� ��������� ������� �� ����������� ������� 
	 int GetFloorCoor();//������� ���������� ����, ��� ����������� ��������� ������
	 Point GetCorrectPosition() const;//������� ������� �������� �� ������ ������
	 int GetLenght() const;//������� ����� ��������
	 int GetHigh() const;//������� ������ ��������
	 

protected:
	Point startPoint;//�������������� ������� ��������
	int high;//������ ��������
	int lenght;//����� ��������
	Color color;//���� ��������
	Point point;//������� ������� �������(����� ������� ����������)
	int Radius = 30;//������ ������
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
	virtual void DrawWindow(Color color);//��������� ����
	virtual void DrawBody(Color color);//���������� ���� ��������
	virtual void DrawWheel(Point LeftPoint, Color color);//��������� ������
	virtual void MoveTo(int Key);//������� �������� �� �������� ������� �� �������� ����
	void SetTo(int x, int y);//������� �������� �� ��������� ������� �� ����������� ������� 
	int GetFloorCoor();//������� ���������� ����, ��� ����������� ��������� ������
	Point GetCorrectPosition() const;//������� ������� �������� �� ������ ������
	int GetLenght() const;//������� ����� ��������
	int GetHigh() const;//������� ������ ��������


protected:
	Point startPoint;//�������������� ������� ��������
	int high;//������ ��������
	int lenght;//����� ��������
	Color color;//���� ��������
	Point point;//������� ������� �������(����� ������� ����������)
	int Radius = 30;//������ ������
	int Speed;
};