#include "Bank.h"


Bank::Bank()
{
}

Bank::Bank(string name, string adress, Date date) : balance(1000000000)
{
	this->name = name;
	this->adress = adress;
	this->date = date;
}

string Bank::GetName()
{
	return name;
}

string Bank::GetAdress()
{
	return adress;
}

long double Bank::GetBalance()
{
	return balance;
}

vector<Account*> & Bank::getAccs(){
    return accounts;
}

void Bank::SetBalance(long double balance)
{
	this->balance = balance;
}

Account * Bank::makeAccount(string name, string surn, int pusp)
{
	Account * newacc = new Account(name, surn, pusp, this);
	accounts.push_back(newacc);
	return newacc;
}

void Bank::DeleteAccount(int pusp)
{
	for (unsigned int i = 0; i < accounts.size(); i++) {
		if (accounts[i]->getPasp() == pusp) {
			accounts.erase(accounts.begin() + i);
			break;
		}
	}
}

Account * Bank::searchAccount(string name, string surn)
{
	for (int i = 0; i < accounts.size(); i++) {
		if (accounts[i]->getName() == name && accounts[i]->getSurn() == surn) {
			return accounts[i];
		}
	}
	return nullptr;
}

Account * Bank::searchAccount(int pasp)
{
	for (int i = 0; i < accounts.size(); i++) {
		if (accounts[i]->getPasp() == pasp) {
			return accounts[i];
		}
	}
	return nullptr;
}

Card * Bank::makeCard(Account * ac, string type, int curr)
{	
    qDebug() << "Bank make card";
	Card* newcard;
	if (type == "universal") {
		newcard = new UniversalCard(date.getMonth(), date.getYear() + 3, curr);
	}
	else {
		newcard = new SalaryCard(date.getMonth(), date.getYear() + 3, curr);
	}
	newcard->setOwner(ac);
	ac->newCard(newcard);
	cards.push_back(newcard);
	return newcard;
}

void Bank::showBankInfo(ostream & os)
{
	os << "--------------------------------------" << endl;
	os << "Name  " << name << endl;
	os << "Adress " << adress << endl;
	os << "--------------------------------------" << endl;
}

void Bank::showCardData(ostream & os)
{
	for (Card * item : cards) {
		item->showData(os);
		os << "/////////////////////////////////" << endl;
	}
}

void Bank::showAccountData(ostream & os)
{
	for (Account * item : accounts) {
		item->showData(os);
	}
	os << endl;
}

void Bank::removeCard(Card * card)
{
	for(unsigned int i = 0; i < cards.size(); i++)
		if (cards[i] == card) {
			cards.erase(cards.begin() + i);
		}
}

void Bank::removeCard(string id)
{
	for (Card * item : cards) {
		if (item->getID() == id) {
			this->removeCard(item);
		}
	}
}

Card * Bank::searchCard(string id)
{
	for (int i = 0; i < cards.size(); i++) {
		if (cards[i]->getID() == id)
			return cards[i];
	}
	return nullptr;
}

void Bank::saveAtFile(ofstream & os)
{
    os.flags(ios::app);
	os << "b," << name << "," << adress << "," << balance << endl;
	for (int i = 0; i < accounts.size(); i++) {
		os << accounts[i]->GetToFile();
		for (int j = 0; j < accounts[i]->getCount(); j++) {
			os << accounts[i]->cards[j]->GetToFile();
		}
	}
}


long double Bank::checkBal()
{
	return balance;
}

bool Bank::sub(double val)
{
	if (balance < val){
		return false;
	}
	else {
		balance -= val;
		return 1;
	}
}

bool Bank::add(double val)
{
	balance += val;
	return true;
}

Bank::~Bank()
{
}
