#include "Wall.h"



Wall::Wall()
{
	this->Bot.setx(70);
	this->Top.setx(70);
}


Wall::~Wall()
{
	this->Bot.setx(0);
	this->Bot.sety(0);
	this->Top.setx(0);
	this->Top.sety(0);
}


Wall::Wall(int a)
{
	this->Bot.setx(70);
	this->Top.setx(70);
	this->Bot.sety(a + 11);
	this->Top.sety(a);
}

Coord Wall::getTop()
{
	return this->Top;
}

Coord Wall::getBot()
{
	return this->Bot;
}

void Wall::setTop(Coord c)
{
	this->Top = c;
}

void Wall::setBot(Coord c)
{
	this->Bot = c;
}

void Wall::xDecrease()
{
	this->Top.setx(this->Top.getx() - 1);
	this->Bot.setx(this->Bot.getx() - 1);
}

void Wall::randWall()
{
	int tempY = 0;
	tempY = (rand() % 6) * 5 + 7;
	if (tempY > 31) tempY = 31;
	this->Top.sety(tempY);
	this->Bot.sety(tempY + 21);
}

void Wall::wallDraw()
{
	if (this->Bot.getx() >= 4 && this->Bot.getx() <= 74)
	{
		for (int j = this->Top.gety() - 1; j > 2; j--)
		{
			if (this->Bot.getx() - 5 >= 10)
			{
				gotoXY(this->Bot.getx() - 5, j);
				cout << '|';
			}
			if (this->Bot.getx() + 5 <= 69)
			{
				gotoXY(this->Bot.getx() + 5, j);
				cout << '|';
			}
		}

		for (int i = this->Bot.getx() + 5; i > this->Bot.getx() - 6; i--)
		{
			if (i < 70 && i > 9)
			{
				gotoXY(i, this->Top.gety());
				cout << "-";
			}
		}
		for (int j = this->Bot.gety() + 1; j < 57; j++)
		{
			if (this->Bot.getx() - 5 >= 10)
			{
				gotoXY(this->Bot.getx() - 5, j);
				cout << '|';
			}
			if (this->Bot.getx() + 5 <= 69)
			{
				gotoXY(this->Bot.getx() + 5, j);
				cout << '|';
			}
		}

		for (int i = this->Bot.getx() + 5; i > this->Bot.getx() - 6; i--)
		{
			if (i < 70 && i > 9)
			{
				gotoXY(i, this->Bot.gety());
				cout << "-";
			}
		}

	}
}

void Wall::wallErase()
{
	if (this->Bot.getx() >= 4 && this->Bot.getx() <= 74)
	{
		for (int j = this->Top.gety(); j > 2; j--)
		{
			if (this->Bot.getx() - 5 >= 10)
			{
				gotoXY(this->Bot.getx() - 5, j);
				cout << ' ';
			}
			if (this->Bot.getx() + 5 <= 69)
			{
				gotoXY(this->Bot.getx() + 5, j);
				cout << ' ';
			}
		}
		
		for (int i = this->Bot.getx() + 5; i > this->Bot.getx() - 6; i--)
		{
			if (i < 70 && i > 9)
			{
				gotoXY(i, this->Top.gety());
				cout << " ";
			}
		}

		for (int j = this->Bot.gety(); j < 57; j++)
		{
			if (this->Bot.getx() - 5 >= 10)
			{
				gotoXY(this->Bot.getx() - 5, j);
				cout << ' ';
			}
			if (this->Bot.getx() + 5 <= 69)
			{
				gotoXY(this->Bot.getx() + 5, j);
				cout << ' ';
			}
		}

		for (int i = this->Bot.getx() + 5; i > this->Bot.getx() - 6; i--)
		{
			if (i < 70 && i > 9)
			{
				gotoXY(i, this->Bot.gety());
				cout << " ";
			}
		}

	}
}

void BGDraw(vector<Wall> &vw)
{
	for (int i = 0; i < vw.size(); i++)
	{
		vw[i].wallDraw();
	}
}

void BGErase(vector<Wall> &vw)
{
	for (int i = 0; i < vw.size(); i++)
	{
		vw[i].wallErase();
	}
}

void BGxDecrease(vector<Wall> &vw)
{
	for (int i = 0; i < vw.size(); i++)
	{
		vw[i].xDecrease();
	}
}

void pop(vector<Wall> &vw)
{
	for (int i = 1; i < vw.size(); i++)
	{
		vw[i - 1] = vw[i];
	}
	vw.pop_back();
}

void BGMove(vector<Wall> &vw)
{
	Wall temp;
	BGErase(vw);
	BGxDecrease(vw);
	if (vw.front().getTop().getx() <= 4)
	{
		pop(vw);
		Coord ctemp;
		ctemp.setx(124);
		temp.setTop(ctemp);
		temp.setBot(ctemp);
		temp.randWall();
		vw.push_back(temp);
	}
	BGDraw(vw);	
}