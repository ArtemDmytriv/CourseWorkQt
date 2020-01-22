#pragma once
#include "head.h"
#include "Card.h"

class UniversalCard : public Card
{
public:
	UniversalCard(int m = 0, int y = 0, int cur = USD);
	UniversalCard();

	virtual void showData(ostream & os);
	bool SalaryAdd(double val);

	~UniversalCard();
};

