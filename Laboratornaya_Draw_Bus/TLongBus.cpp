#pragma once
#include "TLongBus.h"

extern HDC hdc;

void LongBus::DrawWindow(Color color)
{
	HBRUSH hBrush = CreateSolidBrush(RGB(color.x, color.y, color.z));//������ ����� ������ �����
	SelectObject(hdc, hBrush);

	int Midlcoor = point.GetY() + high / 2;//���������� �������� ������ ������� ��������

	// �������� ������������� ������������� ������
	for (int i = point.GetX() + lenght / 8; i < point.GetX() + lenght; i += lenght / 4)
	{
		RECT rect = { i - 45 ,Midlcoor - 40,i + 45,Midlcoor + 40 };
		FillRect(hdc, &rect, hBrush);
	}

	// ��������� ���� ��������� ������  
	DeleteObject(hBrush);
}

void LongBus2::DrawWindow(Color color)
{
	HBRUSH hBrush = CreateSolidBrush(RGB(color.x, color.y, color.z));//������ ����� ������ �����
	SelectObject(hdc, hBrush);

	int Midlcoor = point.GetY() + high / 2;//���������� �������� ������ ������� ��������

	// �������� ������������� ������������� ������
	for (int i = point.GetX() + lenght / 8; i < point.GetX() + lenght; i += lenght / 4)
	{
		RECT rect = { i - 45 ,Midlcoor - 40,i + 45,Midlcoor + 40 };
		FillRect(hdc, &rect, hBrush);
	}

	// ��������� ���� ��������� ������  
	DeleteObject(hBrush);
}

void ModifyLongBus2::DrawWindow(Color color)
{
	HBRUSH Pen = CreateSolidBrush(RGB(color.x, color.y, color.z));
	SelectObject(hdc, Pen);
	int Midlcoor = point.GetY() + high / 2;//���������� �������� ������ ������� ��������

	// �������� ������������� ������������� ������
	
	for (int i = point.GetX() + lenght / 8; i < point.GetX() + lenght; i += lenght / 4)
	{
		Ellipse(hdc, i - 40, Midlcoor - 40, i + 40, Midlcoor + 40);
	}

	// ��������� ���� ��������� ������  
	DeleteObject(Pen);
}

void ModifyLongBus2::DrawWheel(Point centalpoint, Color color)
{
	// ������� ���� ����� - ������ � ������� �����
	HPEN Pen = CreatePen(PS_SOLID, 20, RGB(color.x, color.y, color.z));

	SelectObject(hdc, Pen);	//������� ���� ��������

	// �������� ������ ������������� ������

	for (int i = (centalpoint.GetX() - lenght/2) + lenght / 8; i < (centalpoint.GetX() - lenght / 2) + lenght; i += lenght / 4)
	{
		Ellipse(hdc, i - Radius, centalpoint.GetY() - Radius, i + Radius, centalpoint.GetY() + Radius);
	}

	// ��������� ���� ��������� �������  
	DeleteObject(Pen);
}

void ModifyLongBus2::Show()
{
	int bottomCoor = point.GetY() + high;//���������� ��� ��������
	Point leftWheelCoor = { (int)(point.GetX() + lenght / 2.0) , bottomCoor };//��������� ���������� ������ ������
	Point RightWheelCoor = { (int)(point.GetX() + lenght * 3.0 / 4.0) , bottomCoor, };//��������� ���������� ������� ������

	DrawBody({ 255,0,0 });//������ ������ ��������
	DrawWheel(leftWheelCoor, { 0,0,0 });//������ ����� ������
	//DrawWheel(RightWheelCoor, { 0,0,0 });//������ ������ ������
	DrawWindow({ 0,0,255 });//������ ����
}