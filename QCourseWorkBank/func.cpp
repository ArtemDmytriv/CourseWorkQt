#include "head.h"
#include "Account.h"
#include "Bank.h"
#include "Card.h"
#include "Date.h"
#include "Exchanger.h"
#include "SalaryCard.h"
#include "Transaction.h"
#include "UniversalCard.h"

string currStr[] = { "UAH", "USD", "EUR", "CNY" };


Card * ReadFromFile(ifstream & infile, Account * acc, string & line) {
	Card * card = nullptr;
	if (line.size() == 0) {
		getline(infile, line);
	}
	if (line[0] == 'c') {

		string word, ID, type;
		int month, year, curr;
		double balance, limit;
		istringstream lineStream(line);

		getline(lineStream, word, ',');
		getline(lineStream, ID, ',');
		getline(lineStream, word, '/');
		month = stoi(word);
		getline(lineStream, word, ',');
		year = stoi(word);
		getline(lineStream, word, ',');
		curr = stoi(word);

		getline(lineStream, word, ',');
		limit = stod(word);
		getline(lineStream, word, ',');
		balance = stod(word);
		getline(lineStream, type, '\n');

		card = acc->newCard(type, curr);
		card->setID(ID);
		card->setDate(month, year);
		card->setBalanceLim(limit, balance);

		line = "";
	}
	return card;
}
Account * ReadFromFile(ifstream & infile, Bank * bank, string & line) {
	Account * acc = nullptr;
	if (line.size() == 0) {
		getline(infile, line);
	}
	if (line[0] == 'a') {
		string word, name, surname;
		int pusp;
		istringstream lineStream(line);

		getline(lineStream, word, ',');
		getline(lineStream, name, ',');
		getline(lineStream, surname, ',');
		getline(lineStream, word, '\n');
		pusp = stoi(word);

		acc = bank->makeAccount(name, surname, pusp);
		line = "";
	}
	return acc;
}

Bank * addingBank(Date date)
{
	string name, adress;
	cout << "Enter name of bank:\n";
	cin.get();
	getline(cin, name);
	cout << "Enter adress of bank:\n";
	getline(cin, adress);
	Bank * bank = new Bank(name, adress, date);
	return bank;
}

void mainMenu(vector<Bank*> & banks, Exchanger * exch, Transaction * tran, Date date)
{
	system("cls");
	while (1) {
		cout << "\n--Welcome to my Bank system--\n";
		cout << "\n List of avaliable banks (Enter 0 to add new bank, 'e' to exit):\n";
		for (int i = 0; i < banks.size(); i++) {
			cout << i + 1 << ") " << banks[i]->GetName() << endl;
		}
		string ch;
		cin >> ch;
		if (ch[0] == 'e') return;
		int choice = stoi(ch);
		while (choice < 0 || choice > banks.size()) {
			cout << "Incorrect num, try again\n";
			cout << "\n List of avaliable banks (Enter 0 to add new bank, 'e' to exit):\n";
			for (int i = 0; i < banks.size(); i++) {
				cout << i + 1 << " ) " << banks[i]->GetName() << endl;
			}
			cin >> choice;
		}
		if (choice == 0) {
			banks.push_back(addingBank(date));
		}
		else {
			bankMenu(banks, banks[choice - 1], exch, tran);
		}
	}
}

void bankMenu(vector<Bank*> & banks, Bank * bank, Exchanger * exch, Transaction * tran)
{
	system("cls");
	while(1)
	{
	int choice;

	cout << "\n--Bank \"" << bank->GetName() << "\" Menu--\n\n";
	cout << "List of operations:\n";
	cout << "1) Accounts \n" << "2) Cards \n" << "3) Exchanger settings \n" << "4) BankInfo\n" << "5) Return to main menu\n";
	std::cin >> choice;
	while (choice < 1 || choice > 5) {
		cout << "Incorrect input, try again\n";
		cout << "List of operations:\n";
		cout << "1) Accounts \n" << "2) Cards \n" << "3) Exchanger settings \n" << "4) BankInfo\n"<<"5) Return to main menu\n";
		std::cin >> choice;
	}
	switch (choice) {
	case 1:
		AccountMenu(banks, bank, tran);
		break;
	case 2:
		CardMenu(bank);
		break;
	case 3:
		ExchangerMenu(exch);
		break;
	case 4:
		bank->showBankInfo(cout);
		break;
	case 5: return;
	}

    }
}

void AccountMenu(vector<Bank*> & banks, Bank * bank, Transaction * tran)
{
	system("cls");
	while (1){
	int choice;


	cout << "\n--Bank \"" << bank->GetName() << "\" Menu--\n\n";
	cout << "List of operations:\n";
	cout << "1) List of accounts \n" << "2) Search account \n" << "3) Add account \n" << "4) Delete account\n" << "5) return to bank menu\n";
	cin >> choice;
	while (choice < 1 || choice > 5) {
		cout << "Incorrect input, try again\n";
		cout << "List of operations:\n";
		cout << "1) List of accounts \n" << "2) Search account \n" << "3) Add account \n" << "4) Delete account\n" << "5) return to bank menu\n";
		cin >> choice;
	}
	string name, surn;
	int pusp;
	Account * acc;

	switch (choice) {
	case 1:
		bank->showAccountData(cout);
		break;
	case 2:
		cout << "Enter full name: ";
		cin >> name >> surn;
		acc = bank->searchAccount(name, surn);
		if (acc != nullptr) {
			cout << "User was found\n";
			AccountOper(banks, acc, tran);
		}
		else {
			cout << "User do not found\n";
		}
		break;
	case 3:
		cout << "Creating new account\nEnter Full name: ";
		cin >> name >> surn;
		cout << "Enter pusp code: ";
		cin >> pusp;
		bank->makeAccount(name, surn, pusp);
		break;
	case 4:
		cout << "Enter pasp code for account deleting:";
		cin >> pusp;
		if (bank->searchAccount(pusp) != nullptr) {
			bank->DeleteAccount(pusp);
		}
		else {
			cout << "Account was not found\n";
		}
		break;
	case 5:
		return;
	}
}
}

void CardMenu(Bank * bank)
{
	int choice;
}

void CardMenu(Account * acc, Transaction * tran)
{
}

void ExchangerMenu(Exchanger * exch)
{
	cout << "\n--Exchanger--\n";

	vector<double> curr(exch->getCourses());
	for (int i = 0; i < curr.size(); i++) {
		cout << i + 1 << ". " << currStr[i] << "  " << curr[i] << endl;
	}
	cout << "Change course y/n \n";
	char ch;
	cin >> ch;
	while (ch != 'n') {
		cout << "Choose currency (";
		for (auto item : currStr) {
			cout << item << "/";
		}
		cout << ")\n";
		string str;
		cin >> str;
        string * ptr = find(currStr, currStr + 4, str);
		if (ptr != currStr + 4) {
			cout << "Enter new value: ";
			double val;
			cin >> val;
			exch->AddVolume(ptr - currStr, val);
			vector<double> curr(exch->getCourses());
			for (int i = 0; i < curr.size(); i++) {
				cout << i + 1 << ". " << currStr[i] << "  " << curr[i] << endl;
			}
		}
		else {
			cout << "incorrect input\n";
		}
	
		cout << "Change course y/n \n";
		cin >> ch;
	}
	return;
}

void CardOper(vector<Bank*> & banks, Account * acc, Card * card, Transaction * tran)
{
	system("cls");
	while (1) {
		int choice;


		cout << "List of operations:\n";
		cout << "1) Balance\n" << "2) Deposit \n" << "3) Withdraw \n" << "4) Salary \n" << "5) Transf to card \n" << "6) return \n";
		cin >> choice;
		while (choice < 1 || choice > 6) {
			cout << "Incorrect input, try again\n";
			cout << "List of operations:\n";
			cout << "1) Balance\n" << "2) Deposit \n" << "3) Withdraw \n" << "4) Salary \n" << "5) Transf to card \n" << "6) return \n";
			cin >> choice;
		}
		int i;
		double val;
		string ID;
		switch (choice) {
		case 1:
			cout << "\nBalance: ";
			cout << acc->checkBalance(card) << " " << currStr[card->GetCurren()] << endl;
			break;
		case 2:
			cout << "Enter deposit value: ";
			cin >> val;
			acc->DepositToCard(card, val);
			break;
		case 3:
			cout << "Withdraw value: ";
			cin >> val;
			acc->WithdrawFromCard(card, val);
			break;
		case 4:
			cout << "Salary value: ";
			cin >> val;
			acc->Salary(card, val);
			break;
		case 5:
			cout << "ID of recieving card: ";
			cin >> ID;
			cout << "Value: ";
			cin >> val;
			for (i = 0; i < banks.size(); i++) {
				if (banks[i]->searchCard(ID) != nullptr) {
					tran->Transfer(card, banks[i]->searchCard(ID), val);
				}
			}
			break;
		case 6: return;
		}
	}
}

void AccountOper(vector<Bank*> & banks, Account * acc, Transaction * tran)
{

	system("cls");
	while (1) {

		int choice;

		cout << "List of operations:\n";
		cout << "1) List of cards \n" << "2) Add card \n" << "3) Delete card \n" << "4) Choose card \n" << "5) return \n";
		cin >> choice;
		while (choice < 1 || choice > 5) {
			cout << "Incorrect input, try again\n";
			cout << "List of operations:\n";
			cout << "1) List of cards \n" << "2) Add card \n" << "3) Delete card \n" << "4) Choose card \n" << "5) return \n";
			cin >> choice;
		}
		int val, i;
		string type, curr, ID;
		switch (choice) {
		case 1:
			for (auto item : acc->getCards()) {
				item->showData(cout);
			}
			break;
		case 2:
			cout << "Enter type of card: ";
			cin >> type;
			cout << "Enter currency of card: ";
			cin >> curr;
			for (i = 0; i < 4; i++) {
				if (currStr[i] == curr)
					break;
			}
			if (i > 3) {
				cout << "something is wrong, try again\n";
			}
			else {
				acc->newCard(type, i);
			}
			break;

		case 3:
			cout << "Enter ID for deleting card: ";
			cin >> ID;
			acc->deleteCard(ID);
		case 4:
			cout << "Choose card: \n";
			i = 1;
			for (auto item : acc->getCards()) {
				cout << i++ <<") "<< item->getID() << " " << item->getType() << endl;
			}
			cin >> i;
			CardOper(banks, acc, acc->getCards()[i - 1], tran);
		case 5:
			return;
		}
	}
}

void ReadFromFile(vector<Bank*> & banks, ifstream & infile, Date date, string & line) {
	
	string name, adress;
	long double balance;

	Bank * bank;

	if (line[0] == 'b') {
		string word;
		istringstream lineStream(line);

		getline(lineStream, word, ',');
		getline(lineStream, name, ',');
		getline(lineStream, adress, ',');
		getline(lineStream, word, '\n');
		balance = stold(word);

		bank = new Bank(name, adress, date);
		Account * acc;
		Card * card;
		string line;
		while ((acc = ReadFromFile(infile, bank, line)) != nullptr) {

			while ((card = ReadFromFile(infile, acc, line)) != nullptr);
		}
		banks.push_back(bank);
		bank->SetBalance(balance);
		ReadFromFile(banks, infile, date, line);
	}

}
