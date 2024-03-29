// project 3-5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

double hatSize(int height, int weight)
{
	return 2.9 * double(weight) / height;
 }

double jacketSize(int height, int weight, int age)
{
	double jacket = double(height) * weight / 288;

	if (age > 40)
		jacket = jacket + (age - 30) / 10 * 0.125;
	
	return jacket;
}

double waistSize(int height, int weight, int age)
{
	double size = weight / 5.7;
	if (age >= 30)
		size = size + (age - 28) / 2 * 0.1;

	return size;
}

int main()
{
	int height, weight, age;
    
	cout << "Enter your height in inches: ";
	cin >> height;

	cout << "Enter your weight: ";
	cin >> weight;

	cout << "Enter your age: ";
	cin >> age;

	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);
	cout.precision(2);

	cout << "Your hat size is: " << hatSize(height, weight) << endl;
	cout << "Your jacket size is: " << jacketSize(height, weight, age) << endl;
	cout << "Your waist size is: " << waistSize(height, weight, age) << endl;

	return 0;
}
