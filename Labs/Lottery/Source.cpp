#include "graph1.h"
#include <iostream>
#include "Lottery.h"
using namespace std;

void main()
{
	Lottery player_obj;
	int numballs;
	int yourNumber;
	bool res = false;
	cout << "How many lottery balls do you want to play: "<<endl;
	cin >> numballs;
	

	player_obj.setNoBalls(numballs);
	for(int i = 0; i < numballs; i++)
	{
		cout<<"Enter lottery # "<<i<<" (between 1 and 40): "<<endl;
		cin >> yourNumber;
		res = player_obj.addNumber(yourNumber);
		while(!res)
		{
			cout<<"Incorrect input, please put in a number between 1 and 40"<<endl;
			cin>>yourNumber;
			res = player_obj.addNumber(yourNumber);
		}
	}
	player_obj.displayYourNumbers();
	player_obj.processWinningNumbers();

	gout<<setPos(100,100)<<"Score: "<<	player_obj.computeWinnings();



}