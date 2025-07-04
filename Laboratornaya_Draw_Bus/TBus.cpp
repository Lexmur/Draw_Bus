#pragma once
#include "TBus.h"

extern HDC hdc;

Bus::Bus(int xhigh, int xlenght, Color xcolor, Point xpoint)
{
	high = xhigh;
	lenght = xlenght;
	color = xcolor;
	point = xpoint;
	startPoint = point;
	Speed = 10;
};

void Bus::Show()
{
	int bottomCoor = point.GetY() + high;//���������� ��� ��������
	Point leftWheelCoor = { (int)(point.GetX() + lenght / 4.0) , bottomCoor};//��������� ���������� ������ ������
	Point RightWheelCoor = { (int)(point.GetX() + lenght * 3.0 / 4.0) , bottomCoor,};//��������� ���������� ������� ������
	
	DrawBody({255,0,0});//������ ������ ��������
	DrawWheel(leftWheelCoor,{0,0,0});//������ ����� ������
	DrawWheel(RightWheelCoor,{0,0,0});//������ ������ ������
	DrawWindow({0,0,255});//������ ����

}

void Bus::Hide()
{
	int bottomCoor = point.GetY() + high;
	Point leftWheelCoor = { (int)(point.GetX() + lenght / 4.0 ), bottomCoor};
	Point RightWheelCoor = { (int)(point.GetX() + lenght * 3.0 / 4.0 ), bottomCoor,};
	DrawBody({204,204,204});
	DrawWheel(leftWheelCoor, { 204,204,204 });
	DrawWheel(RightWheelCoor, { 204,204,204 });
	DrawWindow({ 204,204,204 });
	//system("color 70");//������ ������� � ����� ����
}

void Bus::DrawBody(Color color)
{
	HBRUSH hBrush = CreateSolidBrush(RGB(color.x, color.y, color.z));//������ ����� �������� �����
	SelectObject(hdc, hBrush);

	// �������� ������������� ������������� ������
	
	RECT rect = {point.GetX(),point.GetY(),point.GetX() + lenght,point.GetY() + high};
	FillRect(hdc, &rect, hBrush);

	// ��������� ���� ��������� ������  
	DeleteObject(hBrush);
}

void Bus::DrawWindow(Color color)
{
	HBRUSH hBrush = CreateSolidBrush(RGB(color.x,color.y,color.z));//������ ����� ������ �����
	SelectObject(hdc, hBrush);

	// �������� ������������� ������������� ������

	int Midlcoor = point.GetY() + high / 2;//���������� �������� ������ ������� ��������
	for (int i = point.GetX() + lenght / 4; i < point.GetX() + lenght; i += lenght / 2)
	{
		RECT rect = { i - 45 ,Midlcoor-40,i + 45,Midlcoor+40};
		FillRect(hdc, &rect, hBrush);
	}

	// ��������� ���� ��������� ������  
	DeleteObject(hBrush);
}

void Bus::DrawWheel(Point WheelPoint,Color color)
{
	// ������� ���� ����� - ������ � ������� �����
	HPEN Pen = CreatePen(PS_SOLID, 20, RGB(color.x, color.y, color.z));

	SelectObject(hdc, Pen);	//������� ���� ��������

	// �������� ������ ������������� ������
	Ellipse(hdc, WheelPoint.GetX() - Radius, WheelPoint.GetY() - Radius, WheelPoint.GetX() + Radius, WheelPoint.GetY() + Radius);

	// ��������� ���� ��������� �������  
	DeleteObject(Pen);
}

void Bus::MoveTo(int Key)
{
	Hide();
	switch (Key)
	{
	case 38://������ �����
		if (startPoint.GetY() > point.GetY() - high)//�������� �� ������� �������
		{
			point.SetY(startPoint.GetY());
		}
		else
		{
			point.SetY(point.GetY() - (high + 50));//50 - ����� ��� ��������������� "������" �������� � ����� ������ �� ������
		}
		Show();
		break;
	case 40://����� ����
		if (startPoint.GetY() + 2 * high + 100 < point.GetY() + high)//�������� �� ������ ��������, (2*high + 100) ������� 2 ������� � ��������
		{
			point.SetY( startPoint.GetY() + 2*high + 100);
		}
		else
		{
			point.SetY(point.GetY() + (high + 50));
			
		}
		Show();
		break;
	case 37://�������� ������
		if (point.GetX() <= 0)
		{
			point.SetX(0);
		}
		else
		{
			point.SetX(point.GetX() - Speed);
		}
		Show();
		break;
	case 39://�������� �������
		if (point.GetX() + lenght >= 1920)
		{
			point.SetX(1920 - lenght);
		}
		else
		{
			point.SetX(point.GetX() + Speed);
		}
		Show();
		break;
	default:
		break;
		
	}
}

void Bus::SetTo(int x, int y)
{
	point.SetX(x);
	point.SetY(y);
};

int Bus::GetFloorCoor()//������� ���������� ����, ��� ����������� ��������� ������
{
	return startPoint.GetY() + high + Radius;
};

Point Bus::GetCorrectPosition() const//������� ������� �������� �� ������ ������
{
	return point;
};

int Bus::GetLenght() const//������� ����� ��������
{
	return lenght;
};

int Bus::GetHigh() const//������� ������ ��������
{
	return high;
};

Bus2::Bus2(int xhigh, int xlenght, Color xcolor, Point xpoint)
{
	high = xhigh;
	lenght = xlenght;
	color = xcolor;
	point = xpoint;
	startPoint = point;
	Speed = 10;
};

void Bus2::Show()
{
	int bottomCoor = point.GetY() + high;//���������� ��� ��������
	Point leftWheelCoor = { (int)(point.GetX() + lenght / 4.0) , bottomCoor };//��������� ���������� ������ ������
	Point RightWheelCoor = { (int)(point.GetX() + lenght * 3.0 / 4.0) , bottomCoor, };//��������� ���������� ������� ������

	DrawBody({ 255,0,0 });//������ ������ ��������
	DrawWheel(leftWheelCoor, { 0,0,0 });//������ ����� ������
	DrawWheel(RightWheelCoor, { 0,0,0 });//������ ������ ������
	DrawWindow({ 0,0,255 });//������ ����

}

void Bus2::Hide()
{
	int bottomCoor = point.GetY() + high;
	Point leftWheelCoor = { (int)(point.GetX() + lenght / 4.0), bottomCoor };
	Point RightWheelCoor = { (int)(point.GetX() + lenght * 3.0 / 4.0), bottomCoor, };
	DrawBody({ 204,204,204 });
	DrawWheel(leftWheelCoor, { 204,204,204 });
	DrawWheel(RightWheelCoor, { 204,204,204 });
	DrawWindow({ 204,204,204 });
	//system("color 70");//������ ������� � ����� ����
}

void Bus2::DrawBody(Color color)
{
	HBRUSH hBrush = CreateSolidBrush(RGB(color.x, color.y, color.z));//������ ����� �������� �����
	SelectObject(hdc, hBrush);

	// �������� ������������� ������������� ������

	RECT rect = { point.GetX(),point.GetY(),point.GetX() + lenght,point.GetY() + high };
	FillRect(hdc, &rect, hBrush);

	// ��������� ���� ��������� ������  
	DeleteObject(hBrush);
}

void Bus2::DrawWindow(Color color)
{
	HBRUSH hBrush = CreateSolidBrush(RGB(color.x, color.y, color.z));//������ ����� ������ �����
	SelectObject(hdc, hBrush);

	// �������� ������������� ������������� ������

	int Midlcoor = point.GetY() + high / 2;//���������� �������� ������ ������� ��������
	for (int i = point.GetX() + lenght / 4; i < point.GetX() + lenght; i += lenght / 2)
	{
		RECT rect = { i - 45 ,Midlcoor - 40,i + 45,Midlcoor + 40 };
		FillRect(hdc, &rect, hBrush);
	}

	// ��������� ���� ��������� ������  
	DeleteObject(hBrush);
}

void Bus2::DrawWheel(Point WheelPoint, Color color)
{
	// ������� ���� ����� - ������ � ������� �����
	HPEN Pen = CreatePen(PS_SOLID, 20, RGB(color.x, color.y, color.z));

	SelectObject(hdc, Pen);	//������� ���� ��������

	// �������� ������ ������������� ������
	Ellipse(hdc, WheelPoint.GetX() - Radius, WheelPoint.GetY() - Radius, WheelPoint.GetX() + Radius, WheelPoint.GetY() + Radius);

	// ��������� ���� ��������� �������  
	DeleteObject(Pen);
}

void Bus2::MoveTo(int Key)
{
	Hide();
	switch (Key)
	{
	case 38://������ �����
		if (startPoint.GetY() > point.GetY() - high)//�������� �� ������� �������
		{
			point.SetY(startPoint.GetY());
		}
		else
		{
			point.SetY(point.GetY() - (high + 50));//50 - ����� ��� ��������������� "������" �������� � ����� ������ �� ������
		}
		Show();
		break;
	case 40://����� ����
		if (startPoint.GetY() + 2 * high + 100 < point.GetY() + high)//�������� �� ������ ��������, (2*high + 100) ������� 2 ������� � ��������
		{
			point.SetY(startPoint.GetY() + 2 * high + 100);
		}
		else
		{
			point.SetY(point.GetY() + (high + 50));

		}
		Show();
		break;
	case 37://�������� ������
		if (point.GetX() <= 0)
		{
			point.SetX(0);
		}
		else
		{
			point.SetX(point.GetX() - Speed);
		}
		Show();
		break;
	case 39://�������� �������
		if (point.GetX() + lenght >= 1920)
		{
			point.SetX(1920 - lenght);
		}
		else
		{
			point.SetX(point.GetX() + Speed);
		}
		Show();
		break;
	default:
		break;

	}
}

void Bus2::SetTo(int x, int y)
{
	point.SetX(x);
	point.SetY(y);
};

int Bus2::GetFloorCoor()//������� ���������� ����, ��� ����������� ��������� ������
{
	return startPoint.GetY() + high + Radius;
};

Point Bus2::GetCorrectPosition() const//������� ������� �������� �� ������ ������
{
	return point;
};

int Bus2::GetLenght() const//������� ����� ��������
{
	return lenght;
};

int Bus2::GetHigh() const//������� ������ ��������
{
	return high;
};