// Trivia.cpp
#include "pch.h"
#include <string>
#include <iostream>
#include <vector>
#include "Trivia.h"

Trivia::Trivia()
{
	question = "";
	answer = "";
	amount = 0;
}

Trivia::Trivia(string question, string answer, int amount)
{
	this->question = question;
	this->answer = answer;
	this->amount = amount;
}

string Trivia::getQuestion()
{
	return question;
}

void Trivia::setQuestion(string newQuestion)
{
	question = newQuestion;
}

string Trivia::getAnswer()
{
	return answer;
}

void Trivia::setAnswer(string newAnswer)
{
	answer = newAnswer;
}

int Trivia::getAmount()
{
	return amount;
}

void Trivia::setAmount(int newAmount)
{
	amount = newAmount;
}

