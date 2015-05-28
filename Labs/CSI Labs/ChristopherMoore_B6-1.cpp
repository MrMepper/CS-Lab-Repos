#include <iostream>
#include <string>

using namespace std;

string getStudentName();
int getNumberExams();
double getScoresAndCalculateTotal(int a);
double calculateAverage(double a, double b);
char determineLetterGrade(double a);
void displayAverageGrade(string name, double average, char lettergrade);

int main()
{
	string studentname;
	int numberofExams;
	double gradeaverage, examtotal;
	char lettergrade, choice;
	do 
	{

	studentname = getStudentName();

	numberofExams = getNumberExams();

	examtotal = getScoresAndCalculateTotal(numberofExams);

	gradeaverage = calculateAverage(examtotal, numberofExams);

	lettergrade = determineLetterGrade(gradeaverage);

	displayAverageGrade(studentname, gradeaverage, lettergrade);

	cout<<"Would you like to calculate another student's grade? <Y or N>"<<endl;
	cin>>choice;
	}while(choice == 'Y');

	return 0;
}

string getStudentName()
{
	string studentname;

	cout<<"Please enter the student's name: "<<endl;
	cin>>studentname;

	return studentname;
}

int getNumberExams()
{
	int examnumber, counter = 1;
	while (counter == 1)
	{
		cout<<"Please enter the number of exams taken by the student in the course: "<<endl;
		cin>>examnumber;

		if (examnumber < 1)
		{
			cout<<"Incorrect output, please enter a value greater than or equal to one for the number of exams."<<endl;
			cin>>examnumber;
		}
		else
		{
			counter = 2;
		}


	}
	return examnumber;
}
double getScoresAndCalculateTotal(int a)
{
	double examscores, examtotal = 0;
	int counter = 1;
	while (counter <= a)
	{		
		cout<<"Enter the exam scores:"<<endl;
		cin>>examscores;

		examtotal = examtotal + examscores;

		counter++;
	}
	
	return examtotal;
}

double calculateAverage(double examtotal, double numberofExams)
{
	double gradeaverage;
	gradeaverage = examtotal / numberofExams;

	return gradeaverage;
}

char determineLetterGrade(double gradeaverage)
{
	char lettergrade;
	if (gradeaverage > 90)
	{
		lettergrade = 'A';
	}
	else if (gradeaverage > 80)
	{
		lettergrade = 'B';
	}
	else if (gradeaverage > 70)
	{
		lettergrade = 'C';
	}
	else if (gradeaverage > 60)
	{
		lettergrade = 'D';
	}
	else if (gradeaverage >= 0)
	{
		lettergrade = 'F';
	}
	else
	{
		cout << "Grade average is a negative number, incorrect input in exam scores."<<endl;
	}
	return lettergrade;
}

void displayAverageGrade(string name, double average, char lettergrade)
{
	cout<<"Student Name: "<<name<<endl;
	cout<<"Average: "<<average<<endl;
	cout<<"Letter Grade Earned: "<<lettergrade<<endl;
}