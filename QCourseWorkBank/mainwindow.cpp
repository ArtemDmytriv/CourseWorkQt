#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, vector<Bank*> & banks) :
    QMainWindow(parent),
    banks(banks),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    this->setWindowTitle("Bank Main Window");

    connect(ui->ExitButton, &QPushButton::clicked, this, &MainWindow::exitMW, Qt::UniqueConnection);
    connect(ui->AccountList, &QListWidget::currentRowChanged, this, &MainWindow::chooseAcc, Qt::AutoConnection);
    connect(ui->listCard, &QListWidget::currentRowChanged, this, &MainWindow::chooseCard, Qt::AutoConnection);

    connect(ui->ButtonCreateAcc, &QPushButton::clicked, this, &MainWindow::createAcc, Qt::AutoConnection);
    connect(ui->ButtonDeleteAcc, &QPushButton::clicked, this, &MainWindow::deleteAcc, Qt::AutoConnection);
    connect(ui->ButtonAddCard, &QPushButton::clicked, this, &MainWindow::createCard, Qt::AutoConnection);
    connect(ui->ButtonDeleteCard, &QPushButton::clicked, this, &MainWindow::deleteCard, Qt::AutoConnection);

    connect(ui->ButtonDeposit, &QPushButton::clicked, this, &MainWindow::Deposit, Qt::AutoConnection);
    connect(ui->ButtonWithdraw, &QPushButton::clicked, this, &MainWindow::Withdraw, Qt::AutoConnection);
    connect(ui->ButtonTransfer, &QPushButton::clicked, this, &MainWindow::Transfer, Qt::AutoConnection);
}

MainWindow::~MainWindow()
{
    emit CloseSignal();
    qDebug() << "Destrutor";
    delete ui;
}

void MainWindow::printBanks(){
    for (auto bank : banks){
        qDebug() << QString::fromUtf8(bank->GetName().c_str());
    }
}

void MainWindow::exitMW(){
    qDebug() << "exit ";
    emit CloseSignal();
    this->close();
}

void MainWindow::saveData(){

}

void MainWindow::setCurrentBank(Bank *curr){
    currentBank = curr;
    for (Account * acc : currentBank->getAccs()){
        ui->AccountList->addItem(QString::number(acc->getPasp()) + " " + QString::fromUtf8(acc->getName().c_str()) +" "+ QString::fromUtf8(acc->getSurn().c_str()));
    }
}
void MainWindow::updateData(){


    ui->lineName->setText(QString::fromUtf8(currentAcc->getName().c_str()));
    ui->lineSurn->setText(QString::fromUtf8(currentAcc->getSurn().c_str()));
    ui->linePasp->setText(QString::number(currentAcc->getPasp()));
    ui->lineBank->setText(QString::fromUtf8(currentBank->GetName().c_str()));


    ui->listCard->clear();

    for (Card * card : currentAcc->getCards()){
        string balance = to_string(card->checkBal());
        balance = balance.substr(0, balance.find('.') + 2);

        string typestr = card->getType();
        while(typestr.size() < 9 ){
            typestr += "-";
        }

        string text = "/" + typestr + "/ " + card->getID() + " " + balance;
        ui->listCard->addItem(QString::fromUtf8(text.c_str()));
    }
}

void MainWindow::chooseAcc(int pos){

    currentAcc = currentBank->getAccs()[pos];
    updateData();
}

void MainWindow::chooseCard(int pos){
    if(pos < 0){
        currentCard = nullptr;
    }
    else{
        currentCard = currentAcc->getCards()[pos];
    }
}

void MainWindow::Deposit(){

    bool flag = 0;

    if(currentCard == nullptr){
        flag = 1;
        qDebug() << "Card was not choosen";
    }

    if(ui->lineDeposit->text().size() == 0){
        flag = 1;
        qDebug() << "Deposit line is empty";
    }
    double num = ui->lineDeposit->text().toDouble();

    if(!flag){
        QMessageBox::information(this, "Message", "Deposit was succesfull", QMessageBox::Ok);
        currentCard->add(num);
    }
    else{
        QMessageBox::information(this, "Message", "Deposit was denied", QMessageBox::Ok);
    }
    updateData();
}

void MainWindow::Withdraw(){

    bool flag = 0;

    if(currentCard == nullptr){
        flag = 1;
        qDebug() << "Card was not choosen";
    }

    if(ui->lineWithdraw->text().size() == 0){
        flag = 1;
        qDebug() << "Withdraw line is empty";
    }
    double num = ui->lineWithdraw->text().toDouble();

    if(!flag){
        QMessageBox::information(this, "Message", "Withdraw was succesfull", QMessageBox::Ok);
        currentCard->sub(num);
    }
    else{
        QMessageBox::information(this, "Message", "Withdraw was denied", QMessageBox::Ok);
    }
    updateData();
}

void MainWindow::Transfer(){
    bool flag = 1;

    if(currentCard == nullptr){
        flag = 1;
        qDebug() << "Card was not choosen";
        return;
    }

    if(ui->lineSum->text().size() == 0){
        flag = 1;
        qDebug() << "Transfer line is empty";
    }

    double num = ui->lineSum->text().toDouble();
    string ID = ui->lineNumCard->text().toStdString();


    for (int i = 0; i < banks.size(); i++) {
        if (banks[i]->searchCard(ID) != nullptr) {
            TranSys->Transfer(currentCard, banks[i]->searchCard(ID), num);
            flag = 0;
        }
    }

    if(!flag){
        QMessageBox::information(this, "Message", "Transfer was succesfull", QMessageBox::Ok);
    }
    else{
        QMessageBox::information(this, "Message", "Transfer was denied", QMessageBox::Ok);
    }
    updateData();
}

void MainWindow::createAcc(){
    CreateAcc * cf = new CreateAcc(currentBank, this);
    cf->setWindowTitle("Створення акаунта");
    cf->show();

    connect(cf, &CreateAcc::addSignal, this, &MainWindow::addAcc, Qt::AutoConnection);
}

void MainWindow::addAcc(Account * acc){
    qDebug() << QString::fromUtf8(acc->getName().c_str());
    currentBank->makeAccount(acc->getName(), acc->getSurn(), acc->getPasp());
    ui->AccountList->addItem(QString::number(acc->getPasp()) + " " + QString::fromUtf8(acc->getName().c_str()) +" "+ QString::fromUtf8(acc->getSurn().c_str()));
    //updateData();
}

void MainWindow::deleteAcc(){
    currentBank->DeleteAccount(currentAcc->getPasp());
}

void MainWindow::createCard(){
    CreateCard * cf = new CreateCard(currentAcc, this);
    cf->setWindowTitle("Створення картки");
    cf->show();

    connect(cf, &CreateCard::addSignal, this, &MainWindow::addCard, Qt::AutoConnection);
}

void MainWindow::addCard(Card * card){
    qDebug() << "Adding Card";
    currentBank->makeCard(currentAcc, card->getType(),card->GetCurren());
    updateData();
}

void MainWindow::deleteCard(){
    currentAcc->deleteCard(currentCard->getID());
    updateData();
}
