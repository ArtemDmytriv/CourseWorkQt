#include "bankchoice.h"
#include "ui_bankchoice.h"

bankChoice::bankChoice(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::bankChoice)
{
    ui->setupUi(this);

    this->setWindowTitle("Bank Sytem");
    connect(ui->ChooseBank, &QPushButton::clicked, this, &bankChoice::setBank, Qt::AutoConnection);
    connect(ui->CreateBank, &QPushButton::clicked, this, &bankChoice::CreateFormAddBank, Qt::AutoConnection);
    connect(ui->ButtonDelete, &QPushButton::clicked, this, &bankChoice::deleteBank, Qt::AutoConnection);
    connect(ui->ButtonSave, &QPushButton::clicked, this, &bankChoice::saveSlot, Qt::UniqueConnection);
}

bankChoice::~bankChoice()
{
    delete ui;
}

void bankChoice::putBanks(vector<Bank*> & banks){
    this->banks = banks;
    qDebug() << "Add banks";
    for (Bank * bank : this->banks){
        ui->BankList->addItem(QString::fromUtf8(bank->GetName().c_str()));
    }
}

void bankChoice::setBank(){
    uint i = static_cast<uint>(ui->BankList->currentRow());
    currentBank = banks[i];
    qDebug() << QString::fromUtf8(currentBank->GetName().c_str());
    this->hide();


    MainWindow * mw = new MainWindow(this, banks);
    mw->show();
    mw->setCurrentBank(currentBank);
    mw->update();
    mw->TranSys = TranSys;

    connect(mw, &MainWindow::CloseSignal, this, &bankChoice::showSlot, Qt::AutoConnection);

    qDebug() << "MainForm was created with " << QString::fromUtf8(currentBank->GetName().c_str());
}

Bank * bankChoice::getCurrentBank(){
    return currentBank;
}

void bankChoice::CreateFormAddBank(){

    createform * cf = new createform;
    cf->setWindowTitle("Створення банку");
    connect(cf, &createform::addSignal, this, &bankChoice::addBank, Qt::UniqueConnection);
    connect(cf, &createform::exit, this, &bankChoice::show, Qt::AutoConnection);
}

void bankChoice::addBank(Bank * bank){
    qDebug() << "Bank add starting";
    banks.push_back(bank);
    ui->BankList->addItem(QString::fromUtf8(bank->GetName().c_str()));
    saveSlot();
}

void bankChoice::saveSlot(){
    qDebug() << "Save banks";
    ofstream out("banks.csv", ios::trunc);
    for (auto bank : banks) {
        bank->saveAtFile(out);
    }
    out.close();
}

void bankChoice::deleteBank(){
    banks.erase(banks.begin() + ui->BankList->currentRow());
    ui->BankList->clear();
    qDebug() << "Add banks";
    for (Bank * bank : this->banks){
        ui->BankList->addItem(QString::fromUtf8(bank->GetName().c_str()));
    }
}
