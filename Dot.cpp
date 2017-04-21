#include "Dot.h"

clock_t f;
clock_t l;
int Score = 0;

Dot::Dot()
{
	this->Pos.setx(38);
	this->Pos.sety(28);
}


Dot::~Dot()
{
}

Coord Dot::getPos()
{
	return this->Pos;
}

void Dot::setPosx(int a)
{
	this->Pos.setx(a);
}

void Dot::setPosy(int b)
{
	this->Pos.sety(b);
}

bool Dot::fall(vector<Wall> &vW)
{
	f = clock();
	l = clock();
	double s = 0;
	double ssum = 0;
	double h = 0.1;
	while (1)
	{
		gotoXY(this->Pos.getx(), this->Pos.gety());
		cout << 'O';
		if (l - f >= 90)
		{
			for (int i = 0; i < 4; i++)
				if (this->getPos().getx() == vW[i].getBot().getx())
				{
					gotoXY(44, 2);
					Score++;
					cout << Score;
				}

			f = clock();
			if (wallHit(vW, (*this)))
			{
				return true;
			}
			BGMove(vW);
			if (wallHit(vW, (*this)))
			{
				return true;
			}
		}

		gotoXY(this->Pos.getx(), this->Pos.gety());
		cout << 'O' ;
		s = abs(sqrt(h * 2 * 1.0 / 9.8)) - ssum;
		h += 0.1;
		ssum += s;
		Sleep(s * 600);

		gotoXY(this->Pos.getx(), this->Pos.gety());
		cout << ' ';

		if (kbhit())
		{
			char c = getch();
			if (c == ' ')
			{
				if (this->hit(vW))
				{
					return true;
				}
				h = 0.1;
				s = 0;
				ssum = 0;
			}
		}
		this->Pos.yIncrease(1);
		if (wallHit(vW, (*this)))
		{
			return true;
		}
		l = clock();
	}
	return false;
}

bool Dot::hit(vector<Wall> &vW)
{
	f = clock();
	l = clock();
	int* s1 = new int[17];
	for (int i = 0; i < 17; i++)
	{
		s1[i] = i + i * i * 1.5;
	}
	for (int i = 0; i < 17 && this->Pos.gety() >= 3; i++)
	{
		
		gotoXY(this->Pos.getx(), this->Pos.gety());
		cout << 'O';
		if (l - f >= 90)
		{
			for (int i = 0; i < 4; i++)
				if (this->getPos().getx() == vW[i].getBot().getx())
				{
					gotoXY(44, 2);
					Score++;
					cout << Score;
				}
			f = clock();
			if (wallHit(vW, (*this)))
			{
				return true;
			}
			BGMove(vW);
			if (wallHit(vW, (*this)))
			{
				return true;
			}
		}

		gotoXY(this->Pos.getx(), this->Pos.gety());
		cout << 'O';
		Sleep(i);

		gotoXY(this->Pos.getx(), this->Pos.gety());
		cout << ' ';

		this->Pos.yDecrease(1);
		if (wallHit(vW, (*this)))
		{
			delete[] s1;
			return true;
		}
		l = clock();
	}
	return false;
}

bool wallHit(vector<Wall> vW, Dot d)
{
	if (d.getPos().gety() >= 57)
		return true;
	for (int i = 0; i < vW.size(); i++)
	{
		if (d.getPos().getx() <= vW[i].getBot().getx() + 5 && d.getPos().getx() >= vW[i].getBot().getx() - 5)
		{
			if (d.getPos().gety() <= vW[i].getTop().gety() || d.getPos().gety() >= vW[i].getBot().gety())
				return true;
		}
	}
	return false;
}