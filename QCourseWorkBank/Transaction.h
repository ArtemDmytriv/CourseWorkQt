#pragma once
#include "head.h"
#include "Bank.h"
#include "Card.h"
#include "Exchanger.h"

class Transaction
{
private:
	Exchanger * exch;
public:
	Transaction(Exchanger * exch);

	bool Transfer(Card* from, Card* to, double val);
	bool Transfer(Bank* bank, Card* to, double val);
	bool Transfer(Card* from, Bank* bank, double val);

	~Transaction();
};

