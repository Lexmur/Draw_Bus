/**************************************************************************
*                      К  У  Р  С      О  О  П                            *
*-------------------------------------------------------------------------*
*                                                                         *
* Project Name  : Laboratornaya_Draw_Bus                                  *
* Project Type  : Win32 Console application                               *
* File Name     : main.cpp                                                *
* Language      : Visual C++           MS VS 2022                         *
* Programmer(s) : Алксандрин Т.В.                     
* Modified By   : Чечиков Ю.Б.                                            *
* Created       : 23 / 03 / 2024                                          *
* Last Revision : 05 / 06 / 2024                                          *
* Comment(s)    :						                                  *
 *                                                                        *\
 **************************************************************************/

#pragma once 
#include <iostream>
#include <windows.h>
#include "Point.h"
#include "GetConlWin.h"		//указатель на консольное окно
#include "TBus.h"	//Подключаем файл автобуса
#include "TLongBus.h"	//Подключаем файл длинного автобуса
#include "TDamageBus.h" //Подключем файл автобуса с треугольными колёсами
#include "THighBus.h" //Подклюячаем файл высокого автобуса
#include "TBusWindow.h" //Подключаем конфликтные объекты
#include <ctime>	//Подключаем библиотеку времени для исключения псевдворандомных чисел
 //макрос для определения кода нажатой клавиши
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*   Г Л О Б А Л Ь Н Ы Е   П Е Р Е М Е Н Н Ы Е  И  К О Н С Т А Н Т Ы   */
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

HDC hdc;	// Объявим контекст устройства
// Контекст устройства по сути это структура,
// содержащая описание видеокарты на вашем компьютере
// и всех необходимых графических элементов

//Объявляем функцию рисования дороги
void DrawRoad();
bool CheckHit(Bus2* pbus,SomeThing* pSomething);

Point startpoint(200,200);

/***********************************************************************/
/*               О С Н О В Н А Я    П Р О Г Р А М М А                  */
/***********************************************************************/
int main()
{
	srand(time(0));
	system("color 70");//Красим консоль в белый цвет
	
	//получим дескриптор консольного окна
	HWND hwnd = GetConcolWindow();

	//Создаём автобусы
	Bus2 bus(200, 300, {255,0,0},startpoint);
	ModifyLongBus2 longbus2(200, 600, {0,255,0},startpoint);
	LongBus longbus(200, 600, { 0,255,0 }, startpoint);
	DamageBus2 damagebus(200, 300, { 255,0,0 }, startpoint);
	HighBus2 highbus(400, 300, { 255,0,0 }, Point(startpoint.GetX(),startpoint.GetY() + 50));

	//если дескриптор существует - можем работать
	if (hwnd != NULL)
	{
		//получим контекст устройства для консольного окна
		hdc = GetWindowDC(hwnd);

		//если контекст существует - можем работать
		if (hdc != 0)
		{
			//	М Е С Т О    В С Т А В К И 	

			DrawRoad();//Рисуем дорогу

			bus.Show();
			while (1)
				if (KEY_DOWN(49)) // цифра 1
					break;
			bus.Hide();

			longbus2.Show();
			while (1)
				if (KEY_DOWN(50)) // цифра 2
					break;
			longbus2.Hide();

			damagebus.Show();
			while (1)
				if (KEY_DOWN(51)) // цифра 3
					break;
			damagebus.Hide();

			highbus.Show();
			while (1)
				if (KEY_DOWN(52)) // цифра 3
					break;
			highbus.Hide();


			Bus2* pBus = &bus;

			DrawRoad();//Рисуем дорогу повторно

			BusWindow buswindow(bus.GetFloorCoor(),{0,0,255});
			BusBody busbody(bus.GetFloorCoor() + 245 , { 255,0,0 });
			BusWheel buswheel(bus.GetFloorCoor() + 500, { 0,0,0 });

			//Создадим массив объектов конфликта

			SomeThing* trash[3] = { &busbody,&buswindow,&buswheel};
			int locations[3] = { 0,255,475 };



			//Cоздадим матрицу конфдиктнух объектов

			Bus2* conflicttable[3][3] =
			{
				{&bus,&longbus2,&damagebus},
				{&bus,&longbus2,&damagebus},
				{&bus,&longbus2,&damagebus}
			};

			int i = 0;//Отвечает за выбор автобуса
			int j = 0;//Отвечает за выбор конфтиктного объекта

			
			j = rand() % 3;//Выбираем номер случайого конфликтного объекта
			SomeThing* pSomeThing = trash[j];//Создаём случайный конфиктный объект
			i = rand() % 3;//Выбираем номер случайого автобуса
			pBus = conflicttable[0][i];//Создаём случайный автобус

			pSomeThing -> Show();
			pBus -> Show();
			while (1)
			{
				//Осуществляем проверку
				if (CheckHit(pBus, pSomeThing) == 1)
				{
					pBus->Hide();
					pSomeThing->Hide();

					Point nowBusPosition = pBus->GetCorrectPosition();
					pBus = conflicttable[i][j];
					pBus->SetTo(nowBusPosition.GetX(), nowBusPosition.GetY());
					i = j;//Запоминаем какое устройство было вызвано
					
					//Добавить создание объекта заново
					j = rand() % 3;
					pSomeThing->SetTo(bus.GetFloorCoor()+locations[rand()%3]);
					pSomeThing = trash[j];


					pSomeThing->Show();
					pBus->Show();
				}

				if (pSomeThing->GetCorrectPoint().GetX() <= 0)
				{
					pSomeThing->Hide();
					j = rand() % 3;
					pSomeThing->SetTo(bus.GetFloorCoor() + locations[rand() % 3]);
					pSomeThing = trash[j];
					pSomeThing->Show();
				}

				pSomeThing->MoveTo();


				if (KEY_DOWN(38))//Считывание клавиши вверх
				{
					pBus->MoveTo(38);
					DrawRoad();
				}

				if (KEY_DOWN(40))//Считывание клавиши вниз
				{
					pBus->MoveTo(40);
					DrawRoad();
				
				}

				if (KEY_DOWN(37))//Считывание клавиши налево
				{
					pBus->MoveTo(37);
					DrawRoad();
				}

				if (KEY_DOWN(39))//Считывание клавиши направо
				{
					pBus->MoveTo(39);
					DrawRoad();
				}
				if (KEY_DOWN(27))//Выход
					break;

				Sleep(100);
			}

			//===================================================================
		}// end if
	}// end if

	return 0;
}//end main()

void DrawRoad()
{
	//Рисуем дорогу
	HPEN Pen = CreatePen(PS_SOLID, 15, RGB(0, 0, 0));
	SelectObject(hdc, Pen);	//сделаем перо активным
	for (int i = 1; i < 4; i++)
	{
		MoveToEx(hdc, 1920, i * startpoint.GetY() + 245 + (i - 1) * 50, NULL);
		LineTo(hdc, 0, i * startpoint.GetY() + 245 + (i - 1) * 50);
	}
	DeleteObject(Pen);
}

bool CheckHit(Bus2 * pbus, SomeThing* pSth)
{
	if (pbus->GetCorrectPosition().GetX() + pbus->GetLenght() >= pSth->GetCorrectPoint().GetX()
		&& pSth->GetLenght()+ pSth->GetCorrectPoint().GetX() >= pbus->GetCorrectPosition().GetX()
		&& pbus->GetCorrectPosition().GetY() + pbus->GetHigh() >= pSth->GetCorrectPoint().GetY() - 50
		&& pbus->GetCorrectPosition().GetY() <= pSth->GetCorrectPoint().GetY() - 50)//Вычитаю 50 для уверенности, что объект находится на уровне автобуса
		return true;
	else
		return false;
}