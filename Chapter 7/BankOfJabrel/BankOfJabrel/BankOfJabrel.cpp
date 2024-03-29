// BankOfJabrel.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
class BankAccount
{
public:
	BankAccount(double balance, double rate);
	BankAccount(int dollars, int cents, double rate);
	BankAccount(int dollars, double rate);
	BankAccount();
	
	void update();
	void input();
	void output() const;
	double getBalance() const;
	int getDollars() const;
	int getCents() const;
	double getRate() const;

	void setBalance(double balance);
	void setBalance(int dollars, int cents);

	void setRate(double newRate);

private:
	int accountDollars;
	int accountCents;
	double rate;

	int dollarsPart(double amount) const;
	int centsPart(double amount) const;
	int round(double number) const;

	double fraction(double percent) const;

};

bool isLarger(const BankAccount& account1, const BankAccount& account2);

int main()
{
	BankAccount account1(6543.21, 4.5);
	BankAccount account2;
	welcome(account1);
	cout << "Enter data for account 2:" << endl;
	account2.input();
	welcome(account2);

	if (isLarger(account1, account2))
	{
		cout << "Account 1 us larger." << endl;
	}
	else
	{
		cout << "Account 2  is at least as large as Account1." << endl;
	}
	account2.update();
	//account2.setBalance(20);
	welcome(account2);
	return 0;

	
}
bool isLarger(const BankAccount& account1, const BankAccount& account2)
{
	return (account1.getBalance() > account2.getBalance());
}
void welcome(const BankAccount& yourAccount)
{
	cout << "Welcome to the bank of Jabrel.\n"
		<< "The status of your account is: " << endl;
	yourAccount.output();
}

void BankAccount::output() const
{
	int absDollars = abs(accountDollars);
	int absCents = abs(accountCents);
	cout << "Acount baance: $";
	if (accountDollars < 0)
	{
		cout << "-";
	}
	cout << absDollars;
	if (absCents >= 10)
	{
		cout << " . " << absCents << endl;
	}
	else
	{
		cout << " . " << '0' << absCents << endl;
	}
}

BankAccount::BankAccount(double balance, double rate) :
	accountDollars(dollarsPart(balance)), accountCents(centsPart(balance))
{
	setRate(rate);
}

BankAccount::BankAccount(int dollars, double rate) :
	accountDollars(dollars), accountCents(0)
{
	setRate(rate);
}

BankAccount::BankAccount(int dollars, double rate)
	: accountDollars(dollars), accountCents(0)
{
	setRate(rate);
}

BankAccount::BankAccount() :accountDollars(0), accountCents(0), rate(0.0)
{

}

void BankAccount::update()
{
	double balance = accountDollars + accountCents * 0.01;
	balance = balance + fraction(rate)*balance;
	accountDollars = dollarsPart(balance);
	accountCents = centsPart(balance);

}

void BankAccount::input()
{
	double balanceAsDouble;
	cout << "Enter account balance $";
	cin >> balanceAsDouble;
	accountDollars = dollarsPart(balanceAsDouble);
	accountCents = centsPart(balanceAsDouble);
	cout << "Enter interet rate (NO percent sign): ";
	cin >> rate;
	setRate(rate);
}

double BankAccount::getBalance() const
{
	return (accountDollars + accountCents * 0.01);
}

int BankAccount::getDollars() const
{
	return accountDollars;
}

int BankAccount::getCents() const
{
	return accountCents;
}

void BankAccount::setBalance(double balance)
{
	accountDollars = dollarsPart(balance);
	accountCents = centsPart(balance);
}

void BankAccount::setBalance(int dollars, int cents)
{
	if ((dollars < 0 && cents > 0) || (dollars > 0 && cents < 0))
	{
		cout << "Inconsistent account data.\n";
		exit(1);
	}
	accountDollars = dollars;
	accountCents = cents;
}

double BankAccount::getRate()const
{
	return rate;
}

void BankAccount::setRate(double newRate)
{
	if (newRate >= 0.0)
		rate = newRate;
	else
	{
		cout << "Cannot have a negative interest rate.\n";
		exit(1);
	}
}

int BankAccount::dollarsPart(double amount) const
{
	return static_cast<int>(amount);
}

int BankAccount::centsPart(double amount) const
{
	double doubleCents = amount * 100;
	int intCents = (round(fabs(doubleCents))) % 100;
	if (amount < 0)
	{
		intCents = -intCents;
	}
	return intCents;
}

int BankAccount::round(double number) const
{
	return floor(number + 0.5);
}

double BankAccount::fraction(double percent) const
{
	return (percent / 100.0);
}