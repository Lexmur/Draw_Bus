/**************************************************************************
*                      �  �  �  �      �  �  �                            *
*-------------------------------------------------------------------------*
*                                                                         *
* Project Name  : Laboratornaya_Draw_Bus                                  *
* Project Type  : Win32 Console application                               *
* File Name     : main.cpp                                                *
* Language      : Visual C++           MS VS 2022                         *
* Programmer(s) : ���������� �.�.                     
* Modified By   : ������� �.�.                                            *
* Created       : 23 / 03 / 2024                                          *
* Last Revision : 05 / 06 / 2024                                          *
* Comment(s)    :						                                  *
 *                                                                        *\
 **************************************************************************/

#pragma once 
#include <iostream>
#include <windows.h>
#include "Point.h"
#include "GetConlWin.h"		//��������� �� ���������� ����
#include "TBus.h"	//���������� ���� ��������
#include "TLongBus.h"	//���������� ���� �������� ��������
#include "TDamageBus.h" //��������� ���� �������� � ������������ �������
#include "THighBus.h" //����������� ���� �������� ��������
#include "TBusWindow.h" //���������� ����������� �������
#include <ctime>	//���������� ���������� ������� ��� ���������� ���������������� �����
 //������ ��� ����������� ���� ������� �������
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*   � � � � � � � � � �   � � � � � � � � � �  �  � � � � � � � � �   */
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

HDC hdc;	// ������� �������� ����������
// �������� ���������� �� ���� ��� ���������,
// ���������� �������� ���������� �� ����� ����������
// � ���� ����������� ����������� ���������

//��������� ������� ��������� ������
void DrawRoad();
bool CheckHit(Bus2* pbus,SomeThing* pSomething);

Point startpoint(200,200);

/***********************************************************************/
/*               � � � � � � � �    � � � � � � � � �                  */
/***********************************************************************/
int main()
{
	srand(time(0));
	system("color 70");//������ ������� � ����� ����
	
	//������� ���������� ����������� ����
	HWND hwnd = GetConcolWindow();

	//������ ��������
	Bus2 bus(200, 300, {255,0,0},startpoint);
	ModifyLongBus2 longbus2(200, 600, {0,255,0},startpoint);
	LongBus longbus(200, 600, { 0,255,0 }, startpoint);
	DamageBus2 damagebus(200, 300, { 255,0,0 }, startpoint);
	HighBus2 highbus(400, 300, { 255,0,0 }, Point(startpoint.GetX(),startpoint.GetY() + 50));

	//���� ���������� ���������� - ����� ��������
	if (hwnd != NULL)
	{
		//������� �������� ���������� ��� ����������� ����
		hdc = GetWindowDC(hwnd);

		//���� �������� ���������� - ����� ��������
		if (hdc != 0)
		{
			//	� � � � �    � � � � � � � 	

			DrawRoad();//������ ������

			bus.Show();
			while (1)
				if (KEY_DOWN(49)) // ����� 1
					break;
			bus.Hide();

			longbus2.Show();
			while (1)
				if (KEY_DOWN(50)) // ����� 2
					break;
			longbus2.Hide();

			damagebus.Show();
			while (1)
				if (KEY_DOWN(51)) // ����� 3
					break;
			damagebus.Hide();

			highbus.Show();
			while (1)
				if (KEY_DOWN(52)) // ����� 3
					break;
			highbus.Hide();


			Bus2* pBus = &bus;

			DrawRoad();//������ ������ ��������

			BusWindow buswindow(bus.GetFloorCoor(),{0,0,255});
			BusBody busbody(bus.GetFloorCoor() + 245 , { 255,0,0 });
			BusWheel buswheel(bus.GetFloorCoor() + 500, { 0,0,0 });

			//�������� ������ �������� ���������

			SomeThing* trash[3] = { &busbody,&buswindow,&buswheel};
			int locations[3] = { 0,255,475 };



			//C������� ������� ����������� ��������

			Bus2* conflicttable[3][3] =
			{
				{&bus,&longbus2,&damagebus},
				{&bus,&longbus2,&damagebus},
				{&bus,&longbus2,&damagebus}
			};

			int i = 0;//�������� �� ����� ��������
			int j = 0;//�������� �� ����� ������������ �������

			
			j = rand() % 3;//�������� ����� ��������� ������������ �������
			SomeThing* pSomeThing = trash[j];//������ ��������� ���������� ������
			i = rand() % 3;//�������� ����� ��������� ��������
			pBus = conflicttable[0][i];//������ ��������� �������

			pSomeThing -> Show();
			pBus -> Show();
			while (1)
			{
				//������������ ��������
				if (CheckHit(pBus, pSomeThing) == 1)
				{
					pBus->Hide();
					pSomeThing->Hide();

					Point nowBusPosition = pBus->GetCorrectPosition();
					pBus = conflicttable[i][j];
					pBus->SetTo(nowBusPosition.GetX(), nowBusPosition.GetY());
					i = j;//���������� ����� ���������� ���� �������
					
					//�������� �������� ������� ������
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


				if (KEY_DOWN(38))//���������� ������� �����
				{
					pBus->MoveTo(38);
					DrawRoad();
				}

				if (KEY_DOWN(40))//���������� ������� ����
				{
					pBus->MoveTo(40);
					DrawRoad();
				
				}

				if (KEY_DOWN(37))//���������� ������� ������
				{
					pBus->MoveTo(37);
					DrawRoad();
				}

				if (KEY_DOWN(39))//���������� ������� �������
				{
					pBus->MoveTo(39);
					DrawRoad();
				}
				if (KEY_DOWN(27))//�����
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
	//������ ������
	HPEN Pen = CreatePen(PS_SOLID, 15, RGB(0, 0, 0));
	SelectObject(hdc, Pen);	//������� ���� ��������
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
		&& pbus->GetCorrectPosition().GetY() <= pSth->GetCorrectPoint().GetY() - 50)//������� 50 ��� �����������, ��� ������ ��������� �� ������ ��������
		return true;
	else
		return false;
}