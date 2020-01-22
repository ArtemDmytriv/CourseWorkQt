#ifndef CREATEFORM_H
#define CREATEFORM_H

#include "head.h"

#include "Account.h"
#include "Bank.h"
#include "Card.h"
#include "Date.h"
#include "Exchanger.h"
#include "SalaryCard.h"
#include "Transaction.h"
#include "UniversalCard.h"

#include "bankchoice.h"

#include <QPushButton>
#include <QLineEdit>
#include <QDebug>
#include <QString>
#include <QWidget>

class createform : public QWidget{
    Q_OBJECT

private:
    Bank * currentBank = nullptr;
    QLineEdit * line1;
    QLineEdit * line2;


public:

    QPushButton * ApplyButton;
    QPushButton * ExitButton;

    explicit createform(QWidget *parent = nullptr)
        : QWidget(parent)
    {
        this->setFixedSize(240, 200);
        this->setWindowFlags(Qt::CustomizeWindowHint);

        ApplyButton = new QPushButton(this);
        ApplyButton->setText("Додати");
        ApplyButton->move(20, 10);
        ApplyButton->resize(100,50);

        ExitButton = new QPushButton(this);
        ExitButton->setText("Відміна");
        ExitButton->move(140, 10);
        ExitButton->resize(80,50);

        line1 = new QLineEdit(this);
        line1->resize(200, 40);
        line1->move(20, 70);
        line1->setText("Назва банку");
        connect(line1, &QLineEdit::returnPressed, this, &createform::clear1);

        line2 = new QLineEdit(this);
        line2->resize(200, 40);
        line2->move(20, 120);
        line2->setText("Адрес банку");
        connect(line2, &QLineEdit::returnPressed, this, &createform::clear2);

        connect(ApplyButton, &QPushButton::clicked, this, &createform::add, Qt::AutoConnection);
        connect(ExitButton, &QPushButton::clicked, this, &createform::close, Qt::AutoConnection);
        this->show();
    }

    ~createform(){
        delete ApplyButton;
    }



public slots:
    void add(){
        Bank * b = nullptr;
        if(line1 != nullptr && line2 != nullptr){
            Date * d = new Date(21, 5, 2019);
            b = new Bank(line1->text().toStdString(), line2->text().toStdString(), *d);
        }
        qDebug() << "Slot add starting";
        emit addSignal(b);
        this->close();
    }
    void clear1(){
        line1->setText("");
    }
    void clear2(){
        line2->setText("");
    }
signals:
    void addSignal(Bank * bank);
    void exit();
};

#endif // CREATEFORM_H
