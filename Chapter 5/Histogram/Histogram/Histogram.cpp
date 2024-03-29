// Histogram.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	int histogram[101];
	int score;
	int numberOfStudents=0;

	for (int i = 0; i < 6; i++)
	{
		histogram[i] = 0;
	}
	cout << "Enter each grade or a -1 to stop " << endl;
	do
	{
		cin >> score;
		if ((score >= 0) && (score <= 100))
		{
			histogram[score]++;
			numberOfStudents++;
		}	
	}while (score != -1);

	for (int i = 0; i < 101 ; i++)
	{
		if (histogram[i] > 0)
		{
			cout << histogram[i] << " grades(s) of " << i << endl;
		}
		
	}

	cout << numberOfStudents << "processed " << endl;

}

