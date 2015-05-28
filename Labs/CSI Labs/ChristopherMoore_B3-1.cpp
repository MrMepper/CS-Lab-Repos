#include <iostream>
#include <string>
using namespace std;

int main()
{
	char beverage_choice, size_choice, additional_soda;
	double price, total_price, beverage_helpme, coke, pepsi, mtdew, drpepp;
	string coke;
	
	total_price = 0;
	price = 0;
	coke = 0;
	pepsi = 0;
	mtdew = 0;
	drpepp = 0;
	do {
	cout << "Please input the type of beverage wish to have: "<<endl;
	cout << "A: Coke\nB: Pepsi\nC: Mt. Dew\nD: Dr. Pepper\n";
	cin >> beverage_choice;
	switch (beverage_choice)
	{
	case 'A':
		cout<< "You have chosen Coke as your beverage."<<endl;
		cout<< "Please input the size of beverage you wish to have: "<<endl;
		cout<< "A: 20oz $1.50\nB: 2 Liter $1.75" << endl;
		cin >> size_choice;
		if (size_choice == 'A')
		{
			price = 1.50;
			cout<<"You currently owe $1.50."<<endl;
			total += "Coke 20oz, ";
		}
		else if (size_choice == 'B')
		{
			price = 1.75;
			cout<<"You currently owe $1.75."<<endl;
			total += "Coke 2 Liter, ";
		}
		else
			cout<<"You have entered an incorrect input. Please enter the character A or B relevant to your size choice."<<endl;
		coke = coke + 1;
		break;
	case 'B':
		cout<< "You have chosen Pepsi as your beverage."<<endl;
		cout<< "Please input the size of beverage you wish to have: "<<endl;
		cout<< "A: 20oz $1.00\nB: 2 Liter $2.00" << endl;
		cin >> size_choice;
		if (size_choice == 'A')
		{
			price = 1.00;
			cout<<"You currently owe $1.00."<<endl;
			total += "Pepsi 20oz, ";
		}
		else if (size_choice == 'B')
		{
			price = 2.00;
			cout<<"You currently owe $2.00."<<endl;
			total += "Pepsi 2 Liter, ";
		}
		else
			cout<<"You have entered an incorrect input. Please enter the character A or B relevant to your size choice."<<endl;
		pepsi = pepsi + 1;
		break;
	case 'C':
		cout<< "You have chosen Mt. Dew as your beverage."<<endl;
		cout<< "Please input the size of beverage you wish to have: "<<endl;
		cout<< "A: 20oz $.75\nB: 2 Liter $1.90" << endl;
		cin >> size_choice;
		if (size_choice == 'A')
		{
			price = .75;
			cout<<"You currently owe $.75."<<endl;
			total += "Mt. Dew 20oz, ";
		}
		else if (size_choice == 'B')
		{
			price = 1.90;
			cout<<"You currently owe $1.90."<<endl;
			total += "Mt. Dew 2 Liter, "
		}
		else
			cout<<"You have entered an incorrect input. Please enter the character A or B relevant to your size choice."<<endl;
		mtdew = mtdew + 1;
		break;
	case 'D':
		cout<< "You have chosen Dr. Pepper as your beverage."<<endl;
		cout<< "Please input the size of beverage you wish to have: "<<endl;
		cout<< "A: 20oz $1.25\nB: 2 Liter $2.25" << endl;
		cin >> size_choice;
		if (size_choice == 'A')
		{
			price = 1.25;
			cout<<"You currently owe $1.25."<<endl;
			total += "Dr. Pepper 20oz, ";
		}
		else if (size_choice == 'B')
		{
			price = 2.25;
			cout<<"You currently owe $2.25."<<endl;
			total += "Dr. Pepper 2 Liter, ";
		}
		else
			cout<<"You have entered an incorrect input. Please enter the character A or B relevant to your size choice."<<endl;
		drpepp = drpepp + 1;
		break;
	default :
		cout<< "Incorrect input, please input A, B, C, or D corresponding to your beverage of choice."<<endl;
	}

		cout <<"Would you like to have another beverage? Please enter Y for yes and N for no."<<endl;
		cin >> additional_soda;
		total_price = total_price + price;
	} while (additional_soda == 'Y' || additional_soda == 'y');
	cout << "Your order is as follows: "<<endl;
	cout << "-------------------------" <<endl;
	cout << "Beverages: "<<endl;
	cout << total<<endl;
	/*switch (beverage_choice)
	{
	case 'A':
		cout<< "Coke"<<endl;
		cout << "The size for your beverage:"<<endl;
		if (size_choice== 'A')
		{
			cout<< "20oz"<<endl;
			cout<< "Price: $1.50"<<endl;
		}
		else if (size_choice== 'B')
		{	
			cout<< "2 Liter"<<endl;
			cout<< "Price: $1.75"<<endl;
		}
		break;
	case 'B':
		cout<< "Pepsi"<<endl;
		cout << "The size for your beverage:"<<endl;
		if (size_choice== 'A')
		{	
			cout<< "20oz"<<endl;
			cout<< "Price: $1.00"<<endl;
		}
		else if (size_choice== 'B')
		{
			cout<< "2 Liter"<<endl;
			cout<< "Price: $2.00"<<endl;
		}
		break;
	case 'C':
		cout<< "Mt.Dew"<<endl;
		cout << "The size for your beverage:"<<endl;
		if (size_choice== 'A')
			{
				cout<< "20oz"<<endl;
				cout<< "Price: $.75"<<endl;
			}
		else if (size_choice== 'B')
		{
			cout<< "2 Liter"<<endl;
			cout<< "Price: $1.90"<<endl;
		}
		break;
	case 'D':
		cout<< "Dr.Pepper"<<endl;
		cout << "The size for your beverage:"<<endl;
		if (size_choice== 'A')
		{
			cout<< "20oz"<<endl;
			cout<< "Price: $1.25";
		}
		else if (size_choice== 'B')
		{
			cout<< "2 Liter"<<endl;
			cout<< "Price: $2.25"<<endl;
		}
		break;
	}*/
	cout<<"Total Price: $"<<total_price<<endl;

	return 0;
}
