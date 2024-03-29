// HighScores.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void getHighScore(string&, int&);

void getHighScore(string &highName, int &highScore)
{
	string currentName;
	int currentScore;
	bool firstRead = true;
	fstream inputStream;

	inputStream.open("scores.txt");

	while (inputStream >> currentName)
	{
		inputStream >> currentScore;
		//cout << "current name and score " << currentName << "  " << currentScore;
		if (firstRead)
		{
			highName = currentName;
			highScore = currentScore;
			firstRead = false;
		}
		else
		{
			if (currentScore > highScore)
			{
				highName = currentName;
				highScore = currentScore;
			}
		}
	}
	inputStream.close();

}

int main()
{
	string highName;
	int highScore;

	getHighScore(highName, highScore);
	cout << "The high score is " << highScore << " by " << highName 
		<< endl;

	return 0;

}
