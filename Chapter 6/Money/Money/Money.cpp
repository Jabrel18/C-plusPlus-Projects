// Money.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

class Money 
{
public:
	int getDollars();
	int getCents();
	double getAmount();
	void setDollars(int d);
	void setCents(int c);



private:
	int dollars;
	int cents;

};

int Money::getDollars()
{
	return dollars;
}

Money myMoney;
myMoney.getDollars();

int Money::getCents()
{
	return cents;
}

void Money::setDollars(int d)
{
	dollars = d;
}

Money myMoney;
myMoney.setDollars(200);

void Money::setCents(int c)
{
	cents = c;
}

Money myMoney;
myMoney.setCents(10);

double Money::getAmount()
{
	return static.cast<double>(dollars) +
		static.cast<double>(cents) / 100.0;

	myMoney.setCents(301);

}

int main()
{
     
}

