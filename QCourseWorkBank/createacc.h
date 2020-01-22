#ifndef CREATEACC_H
#define CREATEACC_H

#include "head.h"

#include "Account.h"
#include "Bank.h"
#include "Card.h"
#include "Date.h"
#include "Exchanger.h"
#include "SalaryCard.h"
#include "Transaction.h"
#include "UniversalCard.h"

#include <QPushButton>
#include <QLineEdit>
#include <QDebug>
#include <QString>
#include <QWidget>

#include <QDialog>

namespace Ui {
class CreateAcc;
}

class CreateAcc : public QDialog
{
    Q_OBJECT

public:
    explicit CreateAcc(Bank * bank, QWidget *parent = nullptr);
    ~CreateAcc();

private:
    Ui::CreateAcc *ui;
    Bank * currentBank;
public slots:
    void addSlot();

signals:
    void addSignal(Account * acc);
};

#endif // CREATEACC_H
