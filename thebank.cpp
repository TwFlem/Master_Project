#include "thebank.h"
#include "ui_thebank.h"
#include "mainmenu.h"
#include <QMovie>
#include <QDebug>
#include <QMessageBox>

theBank::theBank(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::theBank)
{
    ui->setupUi(this);

}

theBank::theBank(int token, QString name) :
    //QDialog(parent),
    ui(new Ui::theBank)
{
    ui->setupUi(this);

     setWindowTitle(tr("The Bank"));

    setName(name);
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

void theBank::on_pushButton_clicked()
{

    QString tokenz = convertToString(getNumTokens());
    mainMenu * main = new mainMenu(getName(), tokenz);
    main->show();
    close();
}

int theBank::getNumTokens()
{
    return tokenNumber;
}

void theBank::setNumTokens(int newNumTokens)
{
    this->tokenNumber = newNumTokens;
}

void theBank::addNumTokens(int newNumTokens)
{
    this->tokenNumber += newNumTokens;
}

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

void theBank::subtractNumTokens(int numNeeded)
{
    tokenNumber -= numNeeded;
}

QString theBank::convertToString(int x)
{
    QString converted = QString::number(x);

    return converted;
}

void theBank::setName(QString user)
{
    this->name = user;
}

QString theBank::getName()
{
    return name;
}
