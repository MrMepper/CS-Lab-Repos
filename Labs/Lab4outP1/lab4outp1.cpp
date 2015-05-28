#include <iostream>
#include <cstring>
#include <cctype>
#include "graph1.h"
#include <string>

using namespace std;

char* getString(char* prompt);
bool validateName(char* name);
bool validateAddress(char* address);
bool validateCity(char* city);
bool validateState(char* state);
bool validateZip(char* zip);
char* convertToUpper(char* string);
void displayLetter(char* fn, char* ln, char* addr, char* city, char* state, char* zip, int weight);

void main()
{
	char* First_name;
	char* Last_name;
	char* address;
	char* city;
	char* state;
	char* zip;
	int weight;

	bool res = false;

	displayGraphics();

	do{
		First_name = getString("Enter First Name:");
		res = validateName(First_name);
	}while(!res);

	do{
		Last_name = getString("Enter Last Name: ");
		res = validateName(Last_name);
	}while(!res);

	do{
		address = getString("Enter Street Address: ");
		res = validateAddress(address);
	}while(!res);

	do{
		city = getString("Enter City: ");
		res = validateCity(city);
	}while(!res);

	do{
		state = getString("Enter State: ");
		res = validateState(state);
	}while(!res);
	do{
		zip = getString("Enter Zip: ");
		res = validateZip(zip);
	}while(!res);
	
	do{
		cout<<"Enter Weight(in ounces): "<<endl;
		cin>>weight;
	}while(weight < 1 || weight > 6);

	state = convertToUpper(state);

	displayLetter(First_name, Last_name, address, city, state, zip, weight);

}
char* getString(char* prompt)
{
	cout << prompt;
	char* string = NULL;
	char buffer[255];
	cin.get(buffer,sizeof(buffer));
	cin.ignore();
	string = new char[strlen(buffer)+1];
	strcpy(string, buffer);
	return string;
}
bool validateName(char* name){
	int i = 0;
	for (i=0; name[i] != NULL; i++)
	{
		if (isalpha(name[i]) == 0)
		{
				return (false);
		}
	}
	return (true);
}
bool validateAddress(char* address)
{

	int i = 0;
	for (i = 0; address[i] !=NULL; i++)
	{
		if(isalnum(address[i]) == 0)
		{
			if(isspace(address[i]) == 0)
			{
				return (false);
			}
		}
	}
	return (true);
	}
bool validateCity(char* city)
{
	int i = 0;
	for (i=0; city[i] != NULL; i++)
	{
		if(isupper(city[0]) == 0)
			{
				if(isalnum(city[i]) == 0)
				{
					return (false);
				}
			}	
	}
	return (true);
}
bool validateState(char* state)
{
	int i = 0;
	for (i=0; state[i] != NULL; i++)
	{
		if (strlen(state) != 2)
		{
			if(isalpha(state[i]) == 0)
			{
				return (false);
			}
		}
	}
	return (true);
}
bool validateZip(char* zip)
{
	int i = 0;
	for (i = 0; zip[i] != NULL; i++)
	{
		if (isdigit(zip[i])==0)
		{
			if(strlen(zip) != 5)
			{
				return (false);
			}
		}
	}
	return (true);
}
char* convertToUpper(char* string)
{
	char* buffer = new char[strlen(string) + 1];
	for(int i = 0; string[i]!=NULL; i++)
	{
		buffer[i] = toupper(string[i]);
	}
	return buffer;
}
void displayLetter(char* fn, char* ln, char* addr, char* city, char* state, char* zip, int weight)
{
	displayBMP("envelope.bmp", 0,0);



}
