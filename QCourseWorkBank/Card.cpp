#include "Card.h"

int Card::id = 1000000;

Card::Card(int m, int y, int cur) : expirationDate(m, y), balance(0), currency(cur), limit(50000.0)
{
	id++;
	ID = to_string(id);
}

void Card::setOwner(Account * ac)
{
	owner = ac;
}

void Card::setCurren(int currency)
{
	this->currency = currency;
}

void Card::setID(string ID)
{
	this->ID = ID;
	id = stoi(ID);
}

void Card::setBalanceLim(double limit, double balance)
{
	this->limit = limit;
	this->balance = balance;
}

void Card::setDate(int month, int year)
{
	this->expirationDate.SetDate(month, year);
}

Account * Card::getOwner()
{
	return owner;
}


string Card::GetToFile()
{
	string str = "c," + ID + "," + expirationDate.GetDateStr() + "," + to_string(currency) + "," + to_string(limit) + ",";
	str += to_string(balance) + "," + type +"\n";
	return str;
}

void Card::setLimit(double lim)
{
	limit = lim;
}

double Card::getLimit()
{
	return limit;
}

void Card::showData(ostream & os)
{
	os << "\n//////////////////////////////////////////////////" << endl;
	os << "Card ID: " << ID << endl;
	os << "ExpitationDate: " << expirationDate.GetDateStr() << endl;
	os << "Type: " << type << endl;
	os << "Balance: " << balance << " "<< currStr[this->GetCurren()] << endl;
}

bool Card::add(double val)
{
	if (balance + val > limit) {
		cout << "Operation don't allow (Card Limit) " << endl;
		return 0;
	}
	else {
		balance += val;
		return 1;
	}
}

bool Card::SalaryAdd(double val)
{
	if (balance + val < limit) {
		balance += val;
		return 1;
	}
	return 0;
}

bool Card::sub(double val)
{
	if (balance <= val) {
		cout << "Not enough money" << endl;
		return 0;
	}
	else {
		cout << "Withdrawal was successful" << endl;
		balance -= val;
		return 1;
	}
}

Card::~Card()
{
}
