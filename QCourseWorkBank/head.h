#pragma once

#include <iomanip>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include <QDebug>



using namespace std;
class Date;
class Card;
class Account;
class Bank;
class UniversalCard;
class SalaryCard;
class Transaction;
class Exchanger;

enum curr { UAH, USD, EUR, CNY };
extern string currStr[];

Bank * addingBank(Date date);
void mainMenu(vector<Bank*> & banks, Exchanger * exch, Transaction * tran, Date date);
void bankMenu(vector<Bank*> & banks, Bank * bank, Exchanger * exch, Transaction * tran);
void AccountMenu(vector<Bank*> & banks, Bank * bank, Transaction * tran);
void CardMenu(Bank * bank);
void CardMenu(Account * acc, Transaction * tran);
void ExchangerMenu(Exchanger * exch);
void CardOper(vector<Bank*> & banks, Account * acc, Card * card, Transaction * tran);
void AccountOper(vector<Bank*> & banks, Account * acc, Transaction * tran);

void ReadFromFile(vector<Bank*> & banks, ifstream & infile, Date date, string & line);
Account * ReadFromFile(ifstream & infile, Bank * bank, string & line);
Card * ReadFromFile(ifstream & infile, Account * acc, string & line);
