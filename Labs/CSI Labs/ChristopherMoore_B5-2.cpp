#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int number1, number2;

	for (int number1 = 1;number1++)
	{
		for (int number2 = 1; number2 <= 12; number2 ++)
		{
			cout<<setw(6)<< number1 * number2<<setw(6);
		}
		cout<<endl;
	}

	for (int number1 = 2; number1++)
	{
		for (int number2 = 1; number2 <= 12; number2 ++)
		{
			cout<<setw(6)<< number1 * number2<<setw(6);
		}
		cout<<endl;
	}
	return 0;
}