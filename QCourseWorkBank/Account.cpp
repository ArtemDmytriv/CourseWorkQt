#include "Account.h"

Account::Account(string n, string s, int p, Bank * bank)
{
	this->bank = bank;
	name = n;
	surname = s;
	pasp = p;
}

string Account::GetToFile()
{
	string str = "a," + name + "," + surname + "," + to_string(pasp) + "\n";
	return str;
}

void Account::setName(string s)
{
	name = s;
}

void Account::setSurn(string s)
{
	surname = s;
}

void Account::setPasp(int a)
{
	pasp = a;
}

string Account::getName()
{
	return name;
}

string Account::getSurn()
{
	return surname;
}

int Account::getPasp()
{
	return pasp;
}

vector<Card*> & Account::getCards()
{
	return this->cards;
}


Card * Account::newCard(string type, int curr)
{
	Card * card = bank->makeCard(this, type, curr);
	return card;
}

void Account::newCard(Card * ob)
{
	cards.push_back(ob);
}

void Account::deleteCard(string id)
{
	for (auto it = cards.begin(); cards.begin() != cards.end(); it++) {
		if ((*it)->getID() == id) {
			cards.erase(it);
			return;
		}
	}
}

void Account::deleteCard(Card * card)
{
	for (unsigned int i = 0; i < cards.size(); i++) {
		if (card == cards[i]) {
			cards.erase(cards.begin() + i);
			break;
		}
	}
}

Card * Account::searchCard(string ID)
{
	for (auto item : cards) {
		if (item->getID() == ID)
			return item;
	}
	return nullptr;
}

double Account::checkBalance(Card * card)
{
	return card->checkBal();
}

void Account::Salary(Card* card, double val) 
{
	card->SalaryAdd(val);
}

bool Account::DepositToCard(Card * c, double val)
{
	if (c->add(val)) {
		cout << " Deposit (" << val << ") was successful" << endl;
		return 1;
	}
	cout << " Deposit (" << val << ") not allow" << endl;
	return 0;
}

bool Account::WithdrawFromCard(Card * c, double val)
{
	if (c->sub(val)) {
		cout << " Withdraw (" << val << ") was successful" << endl;
		return 1;
	}
	cout << " Withdraw (" << val << ") not allow" << endl;
	return 0;
}

void Account::showData(ostream & os)
{
	os << "\n // Account info // " << endl;
	os << "FullName: " << name << " " << surname << endl;
	os << "Pasp:     " << pasp << endl;
	os << "Bank:     " << bank->GetName() << endl;
}

Account::~Account()
{
}
