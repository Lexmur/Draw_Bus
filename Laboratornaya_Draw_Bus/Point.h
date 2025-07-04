#pragma once
#include <windows.h>

using namespace std;

// ������ ��� �������� ��������� ���������� � �� �������
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

extern HDC hdc;      // �������  �������� ����������

class Location
{
protected:		//������������� ����������� �������� (������������ 
	//������) ����� ������ � ������� ������
	int X;		//���������� X
	int Y;		//���������� Y
public:   //��� ������ �������� ����� ���� � ���������
	Location(int InitX, int InitY); //�����������
	~Location();                    //����������
	int GetX();						//�������� X ���������� �����
	void SetX(int nX);                     //���������� X ����������
	int GetY();						//�������� Y ���������� �����
	void SetY(int nY);                     //����������� Y ����������
};//end class Location


class Point : public Location
{
public:
	Point(int InitX, int InitY);	//����������� ������
	Point() : Location(0, 0) {}; //����������� �� ���������
	~Point();						//����������
	virtual void MoveTo(int NewX, int NewY);//����������� ������	
	//����������� �������
	virtual void Show();              //�������� ������ �����
	virtual void Hide();              //�������� ������ �����

};//end class Point
