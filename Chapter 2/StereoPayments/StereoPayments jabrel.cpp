// StereoPayments.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

const double PAYMENT = 50.00;

int main()
{
	double principle = 1000.00;
	double interest, rate = 0.015;

	int months = 0;
	cout << "Months\tInterest\tPrinciple" << endl;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	while (principle > 0)
	{
		months++;
		interest = principle * rate;
		principle = principle - (PAYMENT - interest);

		if (principle > 0)
		{
			cout << months << "\t" << interest << "\t\t"<< principle << endl;
		}
	}

	cout << "Number of payments: " << months << endl;
	cout << "Principle: " << principle;
	principle = principle + (PAYMENT - interest);
	cout << "Principle: " << principle << endl;

	interest = principle * rate;
	double lastPayment = principle + interest;

	cout << "Interest for last payment: " << interest << endl; 
	cout << "Last payment amount $ " << lastPayment;

	return 0;

}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
