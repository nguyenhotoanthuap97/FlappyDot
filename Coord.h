#pragma once
#include <iostream>
using namespace std;
#include <Windows.h>
#include <conio.h>
#include <vector>
#include <time.h>

class Coord
{
private:
	int x;
	int y;
public:
	Coord();
	~Coord();
	Coord(int, int);
	int getx();
	int gety();
	void setx(int);
	void sety(int);
	void xDecrease();
	void yIncrease(int);
	void yDecrease(int);
};

//Goto x y
void gotoXY(int x, int y);

double PT2(double h);