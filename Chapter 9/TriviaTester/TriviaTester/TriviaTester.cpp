// TriviaTester.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include "Trivia.h"

int main()
{
	vector<Trivia> triviaList;
	Trivia trivia;
	int winnings = 0;

	trivia.setQuestion("What is the 49th state admitted to the USA");
	trivia.setAnswer("alaska");
	trivia.setAmount(100);
	triviaList.push_back(trivia);

	cout << "Trivia Game!" << endl;
	for (int i = 0; i < triviaList.size(); i++)
	{
		cout << "You have $ " << winnings << endl;
		cout << triviaList[i].getQuestion() << endl;
		string answer;
		getline(cin, answer);

		if (answer == triviaList[i].getAnswer())
		{
			cout << "That's right! You win $" << 
				triviaList[i].getAmount() << endl;
			winnings += triviaList[i].getAmount();
		}
		else
			cout << "Sorry, the correct answer is " <<
			triviaList[i].getAnswer() << endl;
	}

	cout << "Game over." << endl <<
		"Your total winnigs are $" << winnings << endl;
}

