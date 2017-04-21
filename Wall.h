#pragma once
#include "Coord.h"

class Wall
{
private:
	Coord Top;
	Coord Bot;
public:
	Wall();
	~Wall();
	Wall(int);
	Coord getTop();
	Coord getBot();
	void setTop(Coord);
	void setBot(Coord);
	void xDecrease();
	void randWall();
	void wallDraw();
	void wallErase();
};

void BGDraw(vector<Wall>&);

void BGErase(vector<Wall>&);

void BGxDecrease(vector<Wall>&);

void pop(vector<Wall>&);

void BGMove(vector<Wall>&);

//Wall distance: x + 30