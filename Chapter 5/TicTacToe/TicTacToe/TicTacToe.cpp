// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void displayGameBoard(char game[]);
void newGame(char game[]);
char score(char game[]);
char play(char playerMark, char game[]);
void playGame(char game[]);

int main()
{
	char game[10];
	newGame(game);
	playGame(game);

}

void newGame(char game[])
{
	for (int i = 0; i <= 9; i++)
	{
		game[i] = static_cast<char> (i + '0');
	}
}

void displayGameBoard(char game[])
{
	cout << "  ";
	for (int i = 1; i <= 9; i++)
	{
		cout << game[i] << "  ";
		if (i % 3 == 0)
			cout << endl << "  ";
	}
}

char score(char game[])
{
	if ((game[1] == game[2]) && (game[2] == game[3]))
		return game[1];
	if ((game[4] == game[5]) && (game[5] == game[6]))
		return game[4];
	if ((game[7] == game[8]) && (game[8] == game[9]))
		return game[7];


	if ((game[0] == game[3]) && (game[3] == game[6]))
		return game[1];
	if ((game[2] == game[5]) && (game[5] == game[8]))
		return game[2];
	if ((game[3] == game[6]) && (game[6] == game[9]))
		return game[3];


	if ((game[1] == game[5]) && (game[5] == game[9]))
		return game[0];
	if ((game[3] == game[5]) && (game[5] == game[7]))
		return game[3];


	int playsRemaining = 0;
	for (int i = 1; i <= 9; i++)
	{
		if (game[i] == static_cast<char>(i + '0'))
			playsRemaining++;
	}

	cout << "\n\nThere are " << playsRemaining << " plays remaining. " << endl;

	if (playsRemaining == 0)
	{
		return 'T';
	}

	return '\0';
}

char play(char playerMark, char game[])
{
	char charMark;
	int arrayLocation;
	char winner;

	cout << "Player " << playerMark << ", please enter the number in " 
		<< "display (1-9) where you wish to make you mark. " << endl;
	
	cin >> charMark; 
	cout << charMark << endl;
	cout << charMark - '0' << endl;
	arrayLocation = static_cast<int>(charMark - '0');
	cout << "You entered " << game[arrayLocation];
	while (!isdigit(game[arrayLocation]))
	{
		cout << "Illegal move " << arrayLocation << " is occupied."
			<< "\nMake another move. " << endl;
		
		cin >> charMark;
		arrayLocation = static_cast<int>(charMark - '0');
	}

	game[arrayLocation] = playerMark;

	system("cls");
	displayGameBoard(game);

	winner = score(game);

	if (winner == 'X' || winner == '0')
	{
		cout << "Player " << winner << " WINS!" << endl;
	} 
	else if (winner == 'T')
	{
		cout << "It is a CAT Game. " << endl;
	}

	return winner;

}

void playGame(char game[])
{
	char score = '\0'; 

	system("cls");
	cout << "Tic Tac Toe " << endl;
	displayGameBoard(game);

	while (score == '\0')
	{
		score = play('X', game);
		if (score == 'X' || score == 'T')
			break;
		score = play('O', game);
		if (score == 'O' || score == 'T')
			break;
	}

}