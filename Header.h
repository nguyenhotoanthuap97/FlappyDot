//Header File


#include "Dot.h"
#include <time.h>

//BackGround
void backGround()
{
	gotoXY(10, 2);
	for (int i = 0; i < 60; i++)
		cout << (char)176;
	gotoXY(10, 57);
	for (int i = 0; i < 60; i++)
		cout << (char)178;
}