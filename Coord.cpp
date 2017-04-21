#include "Coord.h"


//Goto x y
void gotoXY(int x, int y)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { x, y };
	SetConsoleCursorPosition(hStdout, position);
}

Coord::Coord()
{
	this->x = 0;
	this->y = 0;
}


Coord::~Coord()
{
}

Coord::Coord(int a, int b)
{
	this->x = a;
	this->y = b;
}

int Coord::getx()
{
	return this->x;
}

int Coord::gety()
{
	return this->y;
}

void Coord::setx(int a)
{
	this->x = a;
}

void Coord::sety(int b)
{
	this->y = b;
}

void Coord::xDecrease()
{
	(this->x)--;
}

void Coord::yIncrease(int b)
{
	this->y += b;
}

void Coord::yDecrease(int b)
{
	this->y -= b;
}

double PT2(double h)
{
	double s = (-7 + sqrt(49 - 19.6 * h)) * 1.0 / (-9.8);
	return s;
}