// PlayableGameShow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

int playSwap();

int playSwap()
{
	int prizeDoor;

	cout << "Choose a Prize Door? ";
	cin	>> prizeDoor;



	//Choose the door to reveal
	if (prizeDoor = 1)
		cout << "You Won " << endl;
	else

		//Choose another door
		if (prizeDoor = 2)
			cout << "You win dishwashing detergant " << endl;
	else

	//Choose another door
	if (prizeDoor = 3)
		cout << "You Lose " << endl;
	else


	if (prizeDoor >= 4)
		cout << "Error " << endl;
	else

		
	 return 0;
	

}


int main()
{
	int numberOfGames = 0;
	int numWinsSwap = 0;
	

	
	cout << "Number of simulations to play ";
	cin >> numberOfGames;

	for (int i = 0; i < numberOfGames; i++)
	{
		
		numWinsSwap += playSwap();
	}

	cout << "In the Swap version we won " << numWinsSwap << " of "
		<< numberOfGames << endl;

}


