/*
Christopher Moore
Lab1outP1
Calculates sales stuff
*/



#include <iostream>
#include "graph1.h"

using namespace std;

//prototype initalization
int getNoMonths();
void getSales(int sales[], int no_months);
int getMax(int sales[], int no_months);
int getMin(int sales[], int no_months);
double getAverage(int sales[], int no_months);
void displayResults(int sales[], int no_months, int max, int min, double avg);

void main()
{
	//variable initialization
	int number_of_months=0;
	int sales[6]={}; //{} will initialize all values to zero.
	int no_months = 0;
	int max = 0;
	int min = 0;
	int avg = 0;


	number_of_months = getNoMonths();//assigning the return value of GetNoMonths(); to variable
	getSales(sales, number_of_months);
	max = getMax(sales, number_of_months);//assigning the return value of getMax to variable
	min = getMin(sales, number_of_months);//assigning the return value of getMin to variable
	avg = getAverage(sales, number_of_months);//assigning the return value of getAverage to variable
	displayResults(sales, number_of_months, max, min, avg);
}

int getNoMonths()
{
	int number_of_months=0;
	int placeholder=1;//placeholder variable for loop if incorrect input

	while(placeholder==1)
	{
		cout << "Please enter the number of months to process between the integers 3 and 6"<<endl;
		cin >> number_of_months;
		if(number_of_months <= 6 && number_of_months >=3)
		{
			placeholder=0;
			return number_of_months;//return value entered to function, which will then be passed to the variable "number_of_months"
		}
		else
		{
			cout<<"Incorrect input, please enter a number of months between integers 3 and 6"<<endl;
		}
	}
}
void getSales(int sales[], int number_of_months)
{
	cout <<"Please enter the sales amounts for each month:"<<endl;
	for (int i = 0; i<number_of_months; i++)
	{
		cout <<"Please enter sales for month #"<<i+1<<":"<<endl;
		cin>>sales[i];
	}
}
int getMax(int sales[], int number_of_months)
{
	int temp = 0;//temp for max assignment and return value
	for (int i = 0; i < number_of_months; i++)
	{
		if(temp < sales[i])
		{
			temp = sales[i];
		}
	}
	return temp;
}
int getMin(int sales[], int number_of_months)
{
	int temp = 999999999;//need a large number for comparison
	for (int i = 0; i < number_of_months; i++)
	{
		if(temp > sales[i])
		{
			temp = sales[i];
		}
	}
	return temp;
}
double getAverage(int sales[], int number_of_months)
{
	double total = 0;
	double average = 0;
	for (int i = 0; i < number_of_months; i++)
	{
		total = total + sales[i];
	}
	average = total / number_of_months;

	return average;
}
void displayResults(int sales[], int no_months, int max, int min, double avg)
{
	int rect1=0;//rect declarations for setColor assignment
	int rect2=0;
	int rect3=0;
	int rect4=0;
	int rect5=0;
	int rect6=0;

	displayGraphics();
	gout<< setPos(200,345)<<setColor(0,250,0)<<"Sales Statistics"<< endg;
	gout<< setPos(205,380)<<setColor(0,250,0)<<"Max Sales: "<< max<< endg;
	gout<< setPos(205,400)<<setColor(0,250,0)<<"Min Sales: "<< min<< endg;
	gout<< setPos(205,420)<<setColor(0,250,0)<<"Avg Sales: "<< avg<< endg;
	gout<< setPos(375,26) <<setColor(0,250,0)<<"Sales for "<<no_months<<" months"<<endg;
	displayBMP("sales1.bmp",250, 25);
	drawLine(200,150,200,280,1);
	drawLine(200,280,575,280,1);
	for(int i = 0; i < no_months; i++)
	{
		int distance_between = 200 + (i*75);
		int height = ((double)sales[i]/max)*100.0;
		if (i == 0)
		{
			gout<<setPos(200,270-height)<<setColor(0,255,0)<<"Jan"<<endg;
			rect1 = drawRect(distance_between, 280,50, 0 - height);
			setColor(rect1, 100, 88 , 80);
		}
		if (i == 1)
		{
			gout<<setPos(275,270-height)<<setColor(0,255,0)<<"Feb"<<endg;
			rect2 = drawRect(distance_between,280,50,0 - height);
			setColor(rect2, 0, 255, 0);
		}
		if (i == 2)
		{
			gout<<setPos(350,270-height)<<setColor(0,255,0)<<"Mar"<<endg;
			rect3 = drawRect(distance_between,280,50,0 - height);
			setColor(rect3, 0, 0, 255);
		}
		if (i == 3)
		{
			gout<<setPos(425,270-height)<<setColor(0,255,0)<<"Apr"<<endg;
			rect4 = drawRect(distance_between,280,50,0 - height);
			setColor(rect4, 255,255,0);
		}
		if (i == 4)
		{
			gout<<setPos(500,270-height)<<setColor(0,255,0)<<"May"<<endg;
			rect5 = drawRect(distance_between, 280,50,0 - height);
			setColor(rect5, 255, 0, 255);
		}
		if (i == 5)
		{
			gout<<setPos(575,270-height)<<setColor(0,255,0)<<"June"<<endg;
			rect6 = drawRect(distance_between, 280,50,0 - height);
			setColor(rect6, 0, 255, 255);
		}
	}
}