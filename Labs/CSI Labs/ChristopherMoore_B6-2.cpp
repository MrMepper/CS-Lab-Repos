#include <iostream>

using namespace std;

void swap (int &a, int &b);

int main()
{
	int a, b;

	cout <<"Please input an integer value for a: "<<endl;
	cin >> a;

	cout <<"Please input an integer value for b: "<<endl;
	cin >> b;

	swap (a, b);

	cout << a;
	cout << endl;
	cout << b;
	cout << endl;
}

void swap (int &a, int&b)
{
	int temp;

	temp = a;
	a = b;
	b = temp;
}