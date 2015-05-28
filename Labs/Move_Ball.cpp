#include "graph1.h"
#include <iostream>

using namespace std;

void main()
{
	displayGraphics();
	int circle;
	float x, y;
	x = 150;
	y = 0;

	circle = drawCircle(10, x, y);
	setColor(circle, 0, 250, 0);

	while(y + 10 <= 479)
	{
		Sleep(5);
		moveObject(circle, x, y);
		y++;
	}
	while(y - 10 >= 239)
	{
		Sleep(5);
		moveObject(circle, x, y);
		y--;
	}
}
