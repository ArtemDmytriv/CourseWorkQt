#pragma once
#include "head.h"
#include "Account.h"
#include "Date.h"   // for Date
#include "SalaryCard.h"
#include "UniversalCard.h"

class Bank
{
private:
	Date date;
	string name;
	string adress;
	// currency USD
	long double balance;
	vector<Card*> cards;
	vector<Account*> accounts;
public:
	Bank();
	Bank(string name, string adress, Date date);

	string GetName();
	string GetAdress();
	long double GetBalance();
    vector<Account*> & getAccs();

	void SetBalance(long double balance);

	Account * makeAccount(string, string, int);
	void DeleteAccount(int);
	Account * searchAccount(string, string);
	Account * searchAccount(int);

	void showBankInfo(ostream & os);
	void showCardData(ostream & os);
	void showAccountData(ostream & os);
	
	Card * makeCard(Account * ac, string type, int curr = USD);
	void removeCard(Card * card);
	void removeCard(string);
	Card * searchCard(string id);
	
	void saveAtFile(ofstream& os);

	long double checkBal();
	bool sub(double val);
	bool add(double val);
	~Bank();
};

