#pragma once
#include "TSomeThing.h"

extern HDC hdc;

SomeThing::SomeThing(int xfloorcoor)
{
	floorcoor = xfloorcoor;
};

void SomeThing::SetTo(int xfloorcoor)
{
	pointX = 1920;
	floorcoor = xfloorcoor;
};

void SomeThing::MoveTo()
{
	Hide();
	pointX -= 10;
	Show();
};

Point SomeThing::GetCorrectPoint() const
{
	return { pointX - lenght,floorcoor };
};

int SomeThing::GetLenght() const
{
	return lenght;
};