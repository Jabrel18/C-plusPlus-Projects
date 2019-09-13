#pragma once
#include <string>
using namespace std;

class Trivia
{
public:
	Trivia();
	Trivia(string question, string answer, int amount);

	string getQuestion();
	void setQuestion(string newQuestion);
	string getAnswer();
	void setAnswer(string newAnser);

	int getAmount();
	void setAmount(int newAmount);

private:
	string question;
	string answer;
	int amount;

};

