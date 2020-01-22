#include "createcard.h"
#include "ui_createcard.h"

CreateCard::CreateCard(Account * acc, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateCard),
    currentAcc(acc)
{
    ui->setupUi(this);

    ui->comboBox->addItem("universal");
    ui->comboBox->addItem("salary");

    for(int i = 0; i < 4; i++){
    ui->comboBox_2->addItem(QString::fromUtf8(currStr[i].c_str()));
    }

    connect(ui->pushButton, &QPushButton::clicked, this, &CreateCard::addSlot, Qt::UniqueConnection);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &CreateCard::close, Qt::AutoConnection);
}

CreateCard::~CreateCard()
{
    delete ui;
}

void CreateCard::addSlot(){
    Card * c = nullptr;
    c = currentAcc->newCard(ui->comboBox->currentText().toStdString(), ui->comboBox_2->currentIndex());
    emit addSignal(c);
    this->close();
}
