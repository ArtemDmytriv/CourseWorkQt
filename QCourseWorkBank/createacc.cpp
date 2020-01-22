#include "createacc.h"
#include "ui_createacc.h"

CreateAcc::CreateAcc(Bank * bank, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateAcc),
    currentBank(bank)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &CreateAcc::addSlot, Qt::AutoConnection);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &CreateAcc::close, Qt::AutoConnection);
}

CreateAcc::~CreateAcc()
{
    delete ui;
}

void CreateAcc::addSlot(){
    Account * a = nullptr;
    qDebug() << "Slot add acc";
    if (ui->lineName->text() != nullptr && ui->lineSurn->text() != nullptr && ui->linePasp->text() != nullptr){
        a = new Account(ui->lineName->text().toStdString(),
                        ui->lineSurn->text().toStdString(),
                        ui->linePasp->text().toInt(),
                        currentBank);
        emit addSignal(a);
        this->close();
    }
}
