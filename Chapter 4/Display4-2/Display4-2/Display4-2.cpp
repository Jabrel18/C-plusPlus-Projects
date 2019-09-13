// Display4-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

void getNumbers(int&, int&);

void swapValues(int&, int&);

void showResults(int, int);


int main()
{
	int firstNum = 0, secondNum = 0;
	cout << "Enter two numbers and I will swap them." << endl;

	getNumbers(firstNum, secondNum);


	showResults(firstNum, secondNum);

	//Swap the values of firstNum and secondNum

	swapValues(firstNum, secondNum);
	showResults(firstNum, secondNum); 


}
void getNumbers(int& input1, int& input2)
{
	cout << "Enter the first number: ";
	cin >> input1;

	cout << "Enter the second number: ";
	cin >> input2;

}

void swapValues(int& num1, int& num2)
{
	int temp;
	
	temp = num1;
	num1 = num2;
	num2 = temp;

	cout << "Inside the swap funtion. \n";
	showResults(num1, num2); 
}

void showResults(int output1, int output2)
{
	cout << "The two numbers are " << output1
		<< " and " << output2 << endl;
}