#include <iostream>
#include <iomanip>
using namespace std;

void priceAndQuantity(double price[], double total[], double quantity[]);
void displayResults(double price[], double total[], double quantity[]);
void main()
{
	double price[8];
	double total[8];
	double quantity[8];

	priceAndQuantity(price, total, quantity);
	displayResults(price, total, quantity);

}

void priceAndQuantity(double price[], double total[], double quantity[])
{
	cout <<"Please enter the price and quantity of 8 items."<<endl;
	for(int i = 0; i < 8; i++)
	{
		cout <<"Price of item "<< i+1 << " = ?";
		cin>>price[i];
		cout <<"Quantity of item "<< i+1 << " = ?";
		cin>>quantity[i];

		total[i] = price[i] * quantity[i];
	}
}
void displayResults(double price[], double total[], double quantity[])
{
	cout<< "Price       Quantity       Total"<<endl;
	cout<< "-----       --------       -----"<<endl;
	for(int i = 0; i < 8; i++)
	{
		cout <<setprecision(2)<<fixed<<price[i]<<"          "<<quantity[i]<<"         "<<total[i]<<endl;
	}


}
