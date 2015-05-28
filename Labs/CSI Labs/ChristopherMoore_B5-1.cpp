#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>

using namespace std;

int main()
{
	double angle = 0, sideA, sideB, sideCsquared, sideC;
	
	sideA = 10;
	sideB = 20;

	cout << "Side A     Side B     Side C     Cos" << endl;
	cout << "------------------------------------" << endl;

	for (angle; angle <= 90; angle = angle + 5)
	{
		sideCsquared = pow(sideA, 2) + pow(sideB, 2) - 2 * sideA * sideB * cos(angle);
		sideC = sqrt(sideCsquared);
		cout <<sideA<<setw(10)<<sideB<<setw(10)
			 <<sideC<<setw(10)<<angle<<endl;

	}

	return 0;
}

