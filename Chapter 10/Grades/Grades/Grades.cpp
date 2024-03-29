// Grades.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> grades;
	int max = 1;
	int score;
	//int i;

	cout << "Enter grades. Enter a -1 to quit. " << endl;
	do
	{
		cout << "Grade ";
		cin >> score;
		if (score > 0)
		{
			grades.push_back(score);
			if (score > max)
			{
				max = score;
			}
		}	
	} while (score != -1);

	int *histogram = new int[max + 1];

	for (int i = 0; i <= max; i++)
	{
		histogram[i] = 0;
	}

	for (int i = 0; i < grades.size(); i++)
	{
		histogram[grades[i]]++;
	}

	for (int i = 0; i<= max; i++)
	{
		cout << histogram[i] << " grade(s) of " << i << endl;
	}
	cout << endl;

	cout << "Enter a character to exit " << endl;
	char wait;
	cin >> wait;
	return 0;
 }

