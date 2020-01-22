#ifndef BANKCHOICE_H
#define BANKCHOICE_H

#include "head.h"

#include "Account.h"
#include "Bank.h"
#include "Card.h"
#include "Date.h"
#include "Exchanger.h"
#include "SalaryCard.h"
#include "Transaction.h"
#include "UniversalCard.h"

#include "mainwindow.h"
#include "createform.h"

#include <QPushButton>
#include <QDebug>
#include <QString>
#include <QWidget>

namespace Ui {
class bankChoice;
}

class bankChoice : public QWidget
{
    Q_OBJECT

private:
    vector<Bank*> banks;
    Bank * currentBank = nullptr;
    Ui::bankChoice *ui;

public:
    Transaction * TranSys;

    explicit bankChoice(QWidget *parent = nullptr);
    ~bankChoice();
    void putBanks(vector<Bank*> & banks);
    Bank * getCurrentBank();

public slots:
    void setBank();
    void CreateFormAddBank();
    void addBank(Bank * bank);
    void showSlot(){ this->show();}
    void saveSlot();
    void deleteBank();


};

#endif // BANKCHOICE_H
