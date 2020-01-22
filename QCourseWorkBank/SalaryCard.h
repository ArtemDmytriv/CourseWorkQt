#pragma once
#include "head.h"
#include "Card.h"

class SalaryCard : public Card
{
public:
	SalaryCard(int m = 0, int y = 0, int cur = USD);
	SalaryCard();

	virtual void showData(ostream & os);
	bool add(double val);

	~SalaryCard();
};
