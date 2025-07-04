#pragma once
#include "TBusWindow.h"
#include <cmath>

extern HDC hdc;

void BusWindow::Show()
{
	HBRUSH hBrush = CreateSolidBrush(RGB(color.x, color.y, color.z));//������ ����� ������ �����
	SelectObject(hdc, hBrush);

	// �������� ������������� ������������� ������
	RECT rect = { pointX - 100 ,floorcoor - 100,pointX,floorcoor };
	FillRect(hdc, &rect, hBrush);

	// ��������� ���� ��������� ������  
	DeleteObject(hBrush);
};

void BusWindow::Hide()
{
	HBRUSH hBrush = CreateSolidBrush(RGB(204, 204, 204));//������ ����� ������ �����
	SelectObject(hdc, hBrush);

	// �������� ������������� ������������� ������
	RECT rect = { pointX - 100 ,floorcoor - 100,pointX,floorcoor };
	FillRect(hdc, &rect, hBrush);

	// ��������� ���� ��������� ������  
	DeleteObject(hBrush);
};

void BusWheel::Show()
{
	// ������� ���� ����� - ������ � ������� �����
	HPEN Pen = CreatePen(PS_SOLID, 10, RGB(color.x, color.y, color.z));
	SelectObject(hdc, Pen);	//������� ���� ��������
	// �������� ����������� ������������� ������
	POINT trianglePoint[3] =
	{
		{pointX ,floorcoor - 70},
		{pointX - 50 * sqrt(0.75), floorcoor},
		{pointX + 50 * sqrt(0.75), floorcoor}
	};
	Polygon(hdc, trianglePoint, 3);
	// ��������� ���� ��������� �������  
	DeleteObject(Pen);
};

void BusWheel::Hide()
{
	// ������� ���� ����� - ������ � ������� �����
	HPEN Pen = CreatePen(PS_SOLID, 10, RGB(204, 204, 204));
	SelectObject(hdc, Pen);	//������� ���� ��������
	// �������� ����������� ������������� ������
	POINT trianglePoint[3] =
	{
		{pointX ,floorcoor - 70},
		{pointX - 50 * sqrt(0.75), floorcoor},
		{pointX + 50 * sqrt(0.75), floorcoor}
	};
	Polygon(hdc, trianglePoint, 3);
	// ��������� ���� ��������� �������  
	DeleteObject(Pen);
};

void BusBody::Show()
{
	HBRUSH hBrush = CreateSolidBrush(RGB(color.x, color.y, color.z));//������ ����� �������� �����
	SelectObject(hdc, hBrush);

	// �������� ������������� ������������� ������

	RECT rect = { pointX - 150,floorcoor - 100,pointX ,floorcoor };
	FillRect(hdc, &rect, hBrush);

	// ��������� ���� ��������� ������  
	DeleteObject(hBrush);
};

void BusBody::Hide()
{
	HBRUSH hBrush = CreateSolidBrush(RGB(204, 204, 204));//������ ����� �������� �����
	SelectObject(hdc, hBrush);

	// �������� ������������� ������������� ������

	RECT rect = { pointX - 150,floorcoor - 100,pointX ,floorcoor };
	FillRect(hdc, &rect, hBrush);

	// ��������� ���� ��������� ������  
	DeleteObject(hBrush);
};