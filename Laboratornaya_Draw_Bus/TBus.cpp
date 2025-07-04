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
	int bottomCoor = point.GetY() + high;//Координата дна автобуса
	Point leftWheelCoor = { (int)(point.GetX() + lenght / 4.0) , bottomCoor};//Определим координату левого колеса
	Point RightWheelCoor = { (int)(point.GetX() + lenght * 3.0 / 4.0) , bottomCoor,};//Определим координату правого колеса
	
	DrawBody({255,0,0});//Рисуем корпус автобуса
	DrawWheel(leftWheelCoor,{0,0,0});//Рисуем левое колесо
	DrawWheel(RightWheelCoor,{0,0,0});//Рисуем правое колесо
	DrawWindow({0,0,255});//Рисуем окна

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
	//system("color 70");//Красим консоль в белый цвет
}

void Bus::DrawBody(Color color)
{
	HBRUSH hBrush = CreateSolidBrush(RGB(color.x, color.y, color.z));//Создаём кисть красного цвета
	SelectObject(hdc, hBrush);

	// Нарисуем прямоугольник установленным цветом
	
	RECT rect = {point.GetX(),point.GetY(),point.GetX() + lenght,point.GetY() + high};
	FillRect(hdc, &rect, hBrush);

	// Уничтожим нами созданные объект  
	DeleteObject(hBrush);
}

void Bus::DrawWindow(Color color)
{
	HBRUSH hBrush = CreateSolidBrush(RGB(color.x,color.y,color.z));//Создаём кисть синего цвета
	SelectObject(hdc, hBrush);

	// Нарисуем прямоугольник установленным цветом

	int Midlcoor = point.GetY() + high / 2;//Координата середины высоты корпуса автобуса
	for (int i = point.GetX() + lenght / 4; i < point.GetX() + lenght; i += lenght / 2)
	{
		RECT rect = { i - 45 ,Midlcoor-40,i + 45,Midlcoor+40};
		FillRect(hdc, &rect, hBrush);
	}

	// Уничтожим нами созданные объект  
	DeleteObject(hBrush);
}

void Bus::DrawWheel(Point WheelPoint,Color color)
{
	// Зададим цвет ручки - чёрный и ТОЛЩИНУ ручки
	HPEN Pen = CreatePen(PS_SOLID, 20, RGB(color.x, color.y, color.z));

	SelectObject(hdc, Pen);	//сделаем перо активным

	// Нарисуем кольцо установленным цветом
	Ellipse(hdc, WheelPoint.GetX() - Radius, WheelPoint.GetY() - Radius, WheelPoint.GetX() + Radius, WheelPoint.GetY() + Radius);

	// Уничтожим нами созданные объекты  
	DeleteObject(Pen);
}

void Bus::MoveTo(int Key)
{
	Hide();
	switch (Key)
	{
	case 38://Подъём вверх
		if (startPoint.GetY() > point.GetY() - high)//Проверка на верхнюю границу
		{
			point.SetY(startPoint.GetY());
		}
		else
		{
			point.SetY(point.GetY() - (high + 50));//50 - отсуп для визуализального "скачка" автобуса с одной дороги на другую
		}
		Show();
		break;
	case 40://Спуск вниз
		if (startPoint.GetY() + 2 * high + 100 < point.GetY() + high)//Проверка на нижнюю графницу, (2*high + 100) просчёт 2 прыжков с отсутпом
		{
			point.SetY( startPoint.GetY() + 2*high + 100);
		}
		else
		{
			point.SetY(point.GetY() + (high + 50));
			
		}
		Show();
		break;
	case 37://Движение налево
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
	case 39://Движение направо
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

int Bus::GetFloorCoor()//Получим координату пола, для корректного рисвоания дороги
{
	return startPoint.GetY() + high + Radius;
};

Point Bus::GetCorrectPosition() const//Получим позицию автобуса на данный момент
{
	return point;
};

int Bus::GetLenght() const//Получим длину автобуса
{
	return lenght;
};

int Bus::GetHigh() const//Получим высоту автобуса
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
	int bottomCoor = point.GetY() + high;//Координата дна автобуса
	Point leftWheelCoor = { (int)(point.GetX() + lenght / 4.0) , bottomCoor };//Определим координату левого колеса
	Point RightWheelCoor = { (int)(point.GetX() + lenght * 3.0 / 4.0) , bottomCoor, };//Определим координату правого колеса

	DrawBody({ 255,0,0 });//Рисуем корпус автобуса
	DrawWheel(leftWheelCoor, { 0,0,0 });//Рисуем левое колесо
	DrawWheel(RightWheelCoor, { 0,0,0 });//Рисуем правое колесо
	DrawWindow({ 0,0,255 });//Рисуем окна

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
	//system("color 70");//Красим консоль в белый цвет
}

void Bus2::DrawBody(Color color)
{
	HBRUSH hBrush = CreateSolidBrush(RGB(color.x, color.y, color.z));//Создаём кисть красного цвета
	SelectObject(hdc, hBrush);

	// Нарисуем прямоугольник установленным цветом

	RECT rect = { point.GetX(),point.GetY(),point.GetX() + lenght,point.GetY() + high };
	FillRect(hdc, &rect, hBrush);

	// Уничтожим нами созданные объект  
	DeleteObject(hBrush);
}

void Bus2::DrawWindow(Color color)
{
	HBRUSH hBrush = CreateSolidBrush(RGB(color.x, color.y, color.z));//Создаём кисть синего цвета
	SelectObject(hdc, hBrush);

	// Нарисуем прямоугольник установленным цветом

	int Midlcoor = point.GetY() + high / 2;//Координата середины высоты корпуса автобуса
	for (int i = point.GetX() + lenght / 4; i < point.GetX() + lenght; i += lenght / 2)
	{
		RECT rect = { i - 45 ,Midlcoor - 40,i + 45,Midlcoor + 40 };
		FillRect(hdc, &rect, hBrush);
	}

	// Уничтожим нами созданные объект  
	DeleteObject(hBrush);
}

void Bus2::DrawWheel(Point WheelPoint, Color color)
{
	// Зададим цвет ручки - чёрный и ТОЛЩИНУ ручки
	HPEN Pen = CreatePen(PS_SOLID, 20, RGB(color.x, color.y, color.z));

	SelectObject(hdc, Pen);	//сделаем перо активным

	// Нарисуем кольцо установленным цветом
	Ellipse(hdc, WheelPoint.GetX() - Radius, WheelPoint.GetY() - Radius, WheelPoint.GetX() + Radius, WheelPoint.GetY() + Radius);

	// Уничтожим нами созданные объекты  
	DeleteObject(Pen);
}

void Bus2::MoveTo(int Key)
{
	Hide();
	switch (Key)
	{
	case 38://Подъём вверх
		if (startPoint.GetY() > point.GetY() - high)//Проверка на верхнюю границу
		{
			point.SetY(startPoint.GetY());
		}
		else
		{
			point.SetY(point.GetY() - (high + 50));//50 - отсуп для визуализального "скачка" автобуса с одной дороги на другую
		}
		Show();
		break;
	case 40://Спуск вниз
		if (startPoint.GetY() + 2 * high + 100 < point.GetY() + high)//Проверка на нижнюю графницу, (2*high + 100) просчёт 2 прыжков с отсутпом
		{
			point.SetY(startPoint.GetY() + 2 * high + 100);
		}
		else
		{
			point.SetY(point.GetY() + (high + 50));

		}
		Show();
		break;
	case 37://Движение налево
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
	case 39://Движение направо
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

int Bus2::GetFloorCoor()//Получим координату пола, для корректного рисвоания дороги
{
	return startPoint.GetY() + high + Radius;
};

Point Bus2::GetCorrectPosition() const//Получим позицию автобуса на данный момент
{
	return point;
};

int Bus2::GetLenght() const//Получим длину автобуса
{
	return lenght;
};

int Bus2::GetHigh() const//Получим высоту автобуса
{
	return high;
};