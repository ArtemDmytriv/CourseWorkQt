#include "head.h"

#include "Account.h"
#include "Bank.h"
#include "Card.h"
#include "Date.h"
#include "Exchanger.h"
#include "SalaryCard.h"
#include "Transaction.h"
#include "UniversalCard.h"

#include <QApplication>
#include <QString>
#include <QThread>
#include "bankchoice.h"
#include "mainwindow.h"

int main(int argc, char* argv[]) {

    QApplication a(argc, argv);

    ifstream infile("banks.csv");

    if(!infile.is_open()){
        qDebug() << "Fail opening File";
    }
    else{
        qDebug() << "File is open";
    }

    Date todayDay(26, 3, 2019);
    Exchanger * exchPtr = new Exchanger();
    Exchanger & exchSys = *exchPtr;
    exchSys.AddVolume(USD, 26.5);
    exchSys.AddVolume(EUR, 30.5);
    exchSys.AddVolume(CNY, 6.1);
    exchSys.AddVolume(UAH, 1.0);

    Transaction * TransSys = new Transaction(&exchSys);

    string line;
    vector<Bank *> banks;
    getline(infile, line);
    ReadFromFile(banks, infile, todayDay, line);

    infile.close();

    vector<Account*> allAccs;

    Bank * currentBank = nullptr;


    bankChoice * bw = new bankChoice;
    bw->show();
    bw->putBanks(banks);
    bw->TranSys = TransSys;

    if(currentBank == nullptr){
        currentBank = bw->getCurrentBank();
    }



    //qDebug() << banks.size();
    //for(int i = 0; i < banks.size(); i++){
    //    for(int j = 0; j < banks[i]->getAccs().size(); j++){
    //        allAccs.push_back(banks[i]->getAccs()[j]);
    //    }
    //}
    // qDebug() << allAccs.size();

    // mwU->addData(allAccs);

    // mainMenu(banks, &exchSys, TransSys, todayDay);

    ofstream out("banks.csv", ios::trunc);
    for (auto bank : banks) {
        bank->saveAtFile(out);
    }
    out.close();

    delete TransSys;
    delete exchPtr;

    return a.exec();
}
