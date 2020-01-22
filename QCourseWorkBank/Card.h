 #pragma once
#include "head.h"
#include "Date.h"


class Card
{
private:
	static int id;
	string ID;
	Date expirationDate;
	int currency;
	Account *owner;
	Bank *main;
protected:
	double limit;
	double balance;
	string type;
public:
	Card(int m = 0, int y = 0, int cur = USD);
	~Card();

	void setOwner(Account *);
	void setCurren(int currency);
	void setID(string ID);
	void setBalanceLim(double limit, double balance);
	void setDate(int month, int year);

	Account * getOwner();
	string getID() { return ID; }
	string getType() { return type; }
	Date getDate() { return expirationDate; }
	double checkBal() const { return balance; }
	int GetCurren() { return currency; }

	string GetToFile();
	void setLimit(double lim);
	double getLimit();

	virtual void showData(ostream & os) = 0;
	virtual bool add(double);
	virtual bool SalaryAdd(double);
	bool sub(double);

};
