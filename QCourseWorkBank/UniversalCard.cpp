#include "UniversalCard.h"

UniversalCard::UniversalCard(int m, int y, int cur) : Card(m, y, cur) {
	type = "universal";
}

UniversalCard::UniversalCard() : Card()
{
	type = "universal";
}


void UniversalCard::showData(ostream & os)
{
	os << "----------------------------------------------" << endl;
	os << "Universal Card ID: " << this->getID() << endl;
	os << "ExpitationDate: " << this->getDate().GetDateStr() << endl;
	os << "Type: " << type << endl;
	os << "Balance: " << balance << " " << currStr[this->GetCurren()] << endl;
}

bool UniversalCard::SalaryAdd(double val)
{
	cout << "Operation (Salary add) don't allow" << endl;
	return 0;
}

UniversalCard::~UniversalCard()
{
}
