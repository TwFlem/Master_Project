#include "thebank.h"
#include "ui_thebank.h"
#include "mainmenu.h"
#include <QMovie>
#include <QDebug>
#include <QMessageBox>

theBank::theBank(QWidget *parent) ://bank constructor
    QDialog(parent),
    ui(new Ui::theBank)
{
    ui->setupUi(this);

}

theBank::theBank(int token, QString name) ://bank constructor with token input
    //QDialog(parent),
    ui(new Ui::theBank)
{
    ui->setupUi(this);

    //set gui title
     setWindowTitle(tr("The Bank"));

    /set's user username in gui
    setName(name);
    //bank gif animation and display
    movie = new QMovie("c:/animations/Safe-done.gif");
    qDebug() << movie->isValid();
    ui->theSafe->setMovie(movie);
    movie->start();
    setNumTokens(token);
    ui->numberofTokens->setNum(getNumTokens());

}

theBank::~theBank()
{
    delete ui;
}

//When button is pshed
void theBank::on_pushButton_clicked()
{

    //displays number of tokens
    QString tokenz = convertToString(getNumTokens());
    mainMenu * main = new mainMenu(getName(), tokenz);
    main->show();
    close();
}

//returns number of otkens
int theBank::getNumTokens()
{
    return tokenNumber;
}

//sets number of tokens
void theBank::setNumTokens(int newNumTokens)
{
    this->tokenNumber = newNumTokens;
}

//adds number of tokens
void theBank::addNumTokens(int newNumTokens)
{
    this->tokenNumber += newNumTokens;
}

//determines if there are enough toekns for a request
bool theBank::enoughTokens(int numNeeded)
{
    if(tokenNumber >= numNeeded)
        {
          //std::cout << "Purchase successful!" << std::endl;
         // std::cout << "You current have " << (tokenNumber-numNeeded) << " tokens left!" << std::endl;
          return true;
        }
        //if you do not you will not be able to make a purchase
        else
        {
          //std::cout << "Purchase unsuccessful! You do not have enough tokens!" << std::endl;
          //std::cout << "To make this purchase you need " << (-1)*(tokenNumber-numNeeded) << " more tokens!" << std::endl;
          return false;
        }
}

//subtract token from bank
void theBank::subtractNumTokens(int numNeeded)
{
    tokenNumber -= numNeeded;
}

//converts int to string
QString theBank::convertToString(int x)
{
    QString converted = QString::number(x);

    return converted;
}

//set's gui username
void theBank::setName(QString user)
{
    this->name = user;
}

//returns username
QString theBank::getName()
{
    return name;
}
