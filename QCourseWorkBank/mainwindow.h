#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "head.h"

#include "Account.h"
#include "Bank.h"
#include "Card.h"
#include "Date.h"
#include "Exchanger.h"
#include "SalaryCard.h"
#include "Transaction.h"
#include "UniversalCard.h"

#include "createacc.h"
#include "createcard.h"

#include <QMessageBox>
#include <QMainWindow>
#include <QPushButton>
#include <QDebug>
#include <QDialog>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    vector<Bank*> banks;
    Bank * currentBank = nullptr;
    Account * currentAcc = nullptr;
    Card * currentCard = nullptr;
    Ui::MainWindow *ui;

public:
    Transaction * TranSys;

    explicit MainWindow(QWidget *parent, vector<Bank*> & banks);
    ~MainWindow();
    void printBanks();
    void setCurrentBank(Bank * curr);
    void updateData();

public slots:
    void exitMW();
    void saveData();


    void createAcc();
    void addAcc(Account *);

    void deleteAcc();

    void createCard();
    void addCard(Card *);

    void deleteCard();

    void chooseAcc(int pos);
    void chooseCard(int pos);

    void Deposit();
    void Withdraw();
    void Transfer();
signals:

    void CloseSignal();
};

#endif // MAINWINDOW_H
