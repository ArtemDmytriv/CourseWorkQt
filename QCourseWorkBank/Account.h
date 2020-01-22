#pragma once
#include "Bank.h"
#include "Card.h"

class Account
{
private:
	friend class Bank;

	string name;
	string surname;
	int pasp;
	Bank * bank;
protected:
	vector<Card *> cards;
public:

	Account() : name("none"), surname("none") {}
	Account(string, string, int, Bank *);
	string GetToFile();
	
	// seters
	void setName(string);
	void setSurn(string);
	void setPasp(int);

	// geters
    int getCount() { return cards.size(); }
	string getName();
	string getSurn();
	int getPasp();
	vector<Card*> & getCards();

	// opperations with card
	Card * newCard(string type, int curr = USD);
	void newCard(Card*);
	void deleteCard(string);
	void deleteCard(Card*);
	Card * searchCard(string ID);
	
	double checkBalance(Card*);
	void Salary(Card*, double);
	bool DepositToCard(Card*, double);
	bool WithdrawFromCard(Card*, double);
	//
	void showData(ostream & os);

	virtual ~Account();
};

