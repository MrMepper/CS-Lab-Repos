#include <iostream>
#include <cmath>

using namespace std;

void GetLoanAmt(float& loanAmount);
void GetRest (float& monthlyInterest, int & numberOfYears);
void GetInterest (float& monthlyInterest);
void DeterminePayment (float loanAmount, float monthlyInterest, int numberOfPayments, float& payment);
void PrintResults (float loanAmount, float monthlyInterest, int numberOfPayments, float payment, float totalInterest);

int main()
{
	float loanAmt=0;
	
	cout<<"Welcome to the Loan Amount Program!"<<endl;
	cout<<endl<<"Please remember that negative loan amounts will terminate the program."<<endl;

	GetLoanAmt(loanAmt);
	while (loanAmt > 0)
	{
		float monthlyInterest, numberOfPayments, payment, totalInterest;
		int numberOfYears;
		GetRest(monthlyInterest, numberOfYears);

		numberOfPayments = numberOfYears * 12;

		DeterminePayment(loanAmt, monthlyInterest, numberOfPayments, payment);

		totalInterest = payment * numberOfPayments - loanAmt;

		PrintResults(loanAmt, monthlyInterest, numberOfPayments, payment, totalInterest);
		GetLoanAmt(loanAmt);
	}
	cout <<"Thank you for your business. Goodbye!"<<endl;
	return 0;
}

void GetLoanAmt(float & loanAmount)
{
	cout << "Please enter a loan amount: "<<endl;
	cin >> loanAmount;
}

void GetRest (float& monthlyInterest, int & numberOfYears)
{
	GetInterest (monthlyInterest);

	cout << "Please enter number of years of the loan: " << endl;
	cin >> numberOfYears;
}

void GetInterest (float& monthlyInterest)
{
	cout << "Please enter an interest rate(decimal form): "<< endl;
	cin >> monthlyInterest;
}

void DeterminePayment (float loanAmount, float monthlyInterest, int numberOfPayments, float& payment)
{
	payment = loanAmount * ( monthlyInterest / (1 - pow(1 + monthlyInterest, -abs(numberOfPayments))));
}

void PrintResults (float loanAmount, float yearlyInterest, int numberOfPayments, float payment, float totalInterest)
{
	cout << "Here are the results: " <<endl;
	cout << "Loan Amount: "<< loanAmount<<endl;
	cout << "Interest Rate: "<<yearlyInterest*100<<"%"<<endl;
	cout << "Number of Payments: "<<numberOfPayments<<endl;
	cout << "Monthly Payments: "<<payment<<endl;
	cout << "Total Interest Paid: "<<totalInterest<<endl;
}