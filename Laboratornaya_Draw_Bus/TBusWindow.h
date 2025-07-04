#pragma once
#include "TSomeThing.h"
#include "Color.h"

class BusWindow : public SomeThing
{
public:
	BusWindow(int xfloorcoor, Color xColor) : SomeThing(xfloorcoor) { color = xColor; lenght = 100; };
	void Show();
	void Hide();

private:
	Color color;
};

class BusWheel : public SomeThing
{
public:
	BusWheel(int xfloorcoor, Color xColor) : SomeThing(xfloorcoor) { color = xColor; lenght = 45; };
	void Show();
	void Hide();

private:
	Color color;
};

class BusBody : public SomeThing
{
public:
	BusBody(int xfloorcoor, Color xColor) : SomeThing(xfloorcoor) { color = xColor; lenght = 150; };
	void Show();
	void Hide();

private:
	Color color;
};