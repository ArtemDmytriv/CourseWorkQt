#include "Transaction.h"



Transaction::Transaction(Exchanger * exch)
{
	this->exch = exch;
}

bool Transaction::Transfer(Card * from, Card * to, double val)
{
	if (to->getType() == "salary" || from->checkBal() <= val) {
		cout << "Transfer are canceled (" << val << ")" << endl;
		return 0;
	}
	else {
		to->add(exch->Change(from->GetCurren(), to->GetCurren(), val));
		from->sub(val);
		return 1;
	}
}


bool Transaction::Transfer(Bank * bank, Card * to, double val)
{
	if (to->getType() == "salary" || bank->checkBal() <= val) {
		cout << "Transfer are canceled (" << val << ")" << endl;
		return 0;
	}
	else {
		to->add(exch->Change(UAH, to->GetCurren(), val));
		bank->sub(val);
		return 1;
	}
}

bool Transaction::Transfer(Card * from, Bank * bank, double val)
{
	if (from->checkBal() <= val) {
		cout << "Transfer are canceled (" << val << ")" << endl;
		return 0;
	}
	else {
		bank->add(exch->Change(from->GetCurren(), UAH, val));
		from->sub(val);
		return 1;
	}
}


Transaction::~Transaction()
{
}
