#pragma once
#include <iostream>
using namespace std;
#include "Wall.h"


class Dot
{
private:
	Coord Pos;
public:
	Dot();
	~Dot();
	Coord getPos();
	void setPosx(int);
	void setPosy(int);
	bool fall(vector<Wall>&);
	bool hit(vector<Wall>&);
};

bool wallHit(vector<Wall>, Dot);