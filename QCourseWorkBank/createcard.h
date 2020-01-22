#ifndef CREATECARD_H
#define CREATECARD_H


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
class CreateCard;
}

class CreateCard : public QDialog
{
    Q_OBJECT

public:
    explicit CreateCard(Account * acc, QWidget *parent = nullptr);
    ~CreateCard();

private:
    Ui::CreateCard *ui;
    Account * currentAcc;
public slots:
    void addSlot();

signals:
    void addSignal(Card * acc);
};

#endif // CREATEACC_H
