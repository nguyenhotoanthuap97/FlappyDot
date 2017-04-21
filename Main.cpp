//
//Project Name: FlappyDot
//Author: Nguyen Ho Toan Thu
//Main.cpp
//

#include "Header.h"

//Macro set text's colors
#define setTextColor() HANDLE Color; Color = GetStdHandle(STD_OUTPUT_HANDLE);
#define textColor(...) SetConsoleTextAttribute(Color, __VA_ARGS__);

extern int Score;

int main()
{
	vector<Wall> vW;
	Wall temp;
	Dot a;
	setTextColor();
	
	a.setPosx(38);
	a.setPosy(27);

	srand((int)time(NULL));
	backGround();

	gotoXY(33, 27);
	cout << "Play in Fullscreen";
	gotoXY(30, 28);
	cout << "Press SPACEBAR to play !";
	getch();
	gotoXY(33, 27);
	cout << "                  ";
	gotoXY(30, 28);
	cout << "                        ";

	gotoXY(33, 2);
	cout << "    SCORE: 0    ";

	for (int i = 0; i < 4; i++)
	{
		Coord ctemp;
		ctemp.setx(70 + i * 30);
		temp.setTop(ctemp);
		temp.setBot(ctemp);
		temp.randWall();
		vW.push_back(temp);
	}
	if (a.fall(vW))
	{
		textColor(12);
		gotoXY(32, 28);
		cout << "    GAME OVER    ";
		textColor(10);
		gotoXY(30, 29);
		cout << "    Your Score: " << Score << "    ";
		textColor(14);
		gotoXY(25, 30);
		cout << "    Press any key to exit...    ";
		getch();
	}
	return 0;
}