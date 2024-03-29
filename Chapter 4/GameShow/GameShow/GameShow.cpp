// GameShow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



// with our oringinal selection
//
//Doors are represented with the integers 0,1, or 2.
// To select a door with a prize, we 



#include "pch.h"
#include <iostream>
#include <time.h>

using namespace std;

int playNoSwap();
int playSwap();
//const int NUM_GAMES = 10;

int playNoSwap()
{
	int prizeDoor;
	int playerGuest;

	prizeDoor = rand() % 3;
	playerGuest = rand() % 3;

	if (prizeDoor == playerGuest)
		return 1;

	return 0;
}

int playSwap()
{
	int prizeDoor;
	int playerGuest;
	int revealDoor;
	int newGuestDoor;

	prizeDoor = rand() % 3;
	playerGuest = rand() % 3;

	//Choose the door to reveal
	for (int i = 0; i < 3; i++)
	{
		if ((i != prizeDoor) && (i != playerGuest))
			revealDoor = i;
	}

	//Choose another door
	for (int i = 0; i < 3; i++)
	{
		if((i != revealDoor) && (i != playerGuest))
			newGuestDoor = i;
	}

	if (prizeDoor == newGuestDoor)
		return 1;

	return 0;

}


int main()
{
	int numberOfGames = 0;
	int numWinsSwap = 0;
	int numWinsNoSwap = 0;

	srand(time(NULL));
	
	cout << "Number of simulations to play ";
	cin >> numberOfGames;

	for (int i = 0; i < numberOfGames; i++)
	{
		numWinsNoSwap += playNoSwap();
		numWinsSwap += playSwap();
	}

	cout << "In the No Swap version we won " << numWinsNoSwap << " of "
		<< numberOfGames << endl;

	cout << "In the Swap version we won " << numWinsSwap << " of "
		<< numberOfGames << endl;

}

