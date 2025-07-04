#pragma once
#include "TDamageBus.h"
#include <cmath>
#include <iostream>

extern HDC hdc;

void DamageBus::DrawWheel(Point WheelPoint, Color color)
{
	// ������� ���� ����� - ������ � ������� �����
	HPEN Pen = CreatePen(PS_SOLID, 10, RGB(color.x, color.y, color.z));

	SelectObject(hdc, Pen);	//������� ���� ��������

	// �������� ����������� ������������� ������


	POINT trianglePoint[3] =
	{
		{WheelPoint.GetX() ,WheelPoint.GetY() - Radius},
		{WheelPoint.GetX() - Radius * sqrt(0.75), WheelPoint.GetY() + Radius / 2},
		{WheelPoint.GetX() + Radius * sqrt(0.75), WheelPoint.GetY() + Radius / 2}
	};
	Polygon(hdc, trianglePoint, 3);

	// ��������� ���� ��������� �������  
	DeleteObject(Pen);
}

void DamageBus2::DrawWheel(Point WheelPoint, Color color)
{
	// ������� ���� ����� - ������ � ������� �����
	HPEN Pen = CreatePen(PS_SOLID, 10, RGB(color.x, color.y, color.z));

	SelectObject(hdc, Pen);	//������� ���� ��������

	// �������� ����������� ������������� ������


	POINT trianglePoint[3] =
	{
		{WheelPoint.GetX() ,WheelPoint.GetY() - Radius},
		{WheelPoint.GetX() - Radius * sqrt(0.75), WheelPoint.GetY() + Radius / 2},
		{WheelPoint.GetX() + Radius * sqrt(0.75), WheelPoint.GetY() + Radius / 2}
	};
	Polygon(hdc, trianglePoint, 3);

	// ��������� ���� ��������� �������  
	DeleteObject(Pen);
}