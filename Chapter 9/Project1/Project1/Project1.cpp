// Project1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void getSenctence(char sentence[], int& size);
//void process(char str[], int size);

int main()
{
	char sentence[100];
	int size;

	cout << "Enter one sentence. The period is the signal to quit." << endl;
	getSenctence(sentence, size);
	cout << endl;
	cout << sentence << endl;
}

void getSenctence(char sentence[], int& size)
{
	bool haveBlank = false;
	int isFirstLetter = true;
	int i = 0;

	for (i = 0; '.' != (sentence[i] = cin.get()) && i < 100; i++)
	{
		// Check for a carriage retrun and give a space instead
		if (sentence[i] == '\n')
			sentence[i] = ' ';

		//convert input to lower case
		if(isalpha(sentence[i]))
			sentence[i] = tolower(sentence[i]);

		//check for an extra space
		if (sentence[i] == ' ' && !haveBlank)
			haveBlank = true;
		else if (sentence[i] == ' ' && haveBlank)
			i--;
		else if (sentence[i] != ' ' && haveBlank)
			haveBlank = false;
	}
	sentence[0] = toupper(sentence[0]);
	if (i < 99)
		sentence[i + 1] = '\0';
	else
	{
		sentence[98] = '.';
		sentence[99] = '\0';
	}

	size = i;


}