#include "SalaryCard.h"


SalaryCard::SalaryCard(int m, int y, int cur) : Card(m, y, cur)
{
	type = "salary";
}


SalaryCard::SalaryCard() : Card()
{
	type = "salary";
}

void SalaryCard::showData(ostream & os)
{
		os << "----------------------------------------------" << endl;
		os << "Salary Card ID: " << this->getID() << endl;
		os << "ExpitationDate: " << this->getDate().GetDateStr() << endl;
		os << "Type: " << type << endl;
		os << "Balance: " << balance << " " << currStr[this->GetCurren()] << endl;
}

bool SalaryCard::add(double val) {
	cout << "Operation do not allow (SalaryCard)" << endl;
	return 0;
}


SalaryCard::~SalaryCard()
{
}
