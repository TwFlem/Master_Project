#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "createnewpet.h"
#include "seconddialog.h"
#include "mainwindow.h"
#include "timegrab.h"
#include "thebank.h"
#include "shop.h"
#include "help.h"
#include "choosepet.h"
#include <QFile>
#include <QVector>
#include <QString>
#include <QDebug>
#include <QMessageBox>

mainMenu::mainMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainMenu)
{
    ui->setupUi(this);
}

mainMenu::mainMenu(QString name) :
    //QDialog(parent),
    ui(new Ui::mainMenu)
{


    ui->setupUi(this);

    setWindowTitle(tr("Study Pet Adventures"));



    setUsername(name);
    storeInfo(name);
    qDebug () << petInfo[1];
    setTokens(userInfoVector[1]);
    qDebug() << tokens.length();
    ui->userDataLabel->setText("User Data");
    ui->tokens->setText(userInfoVector[1]);
    ui->petNumberLabel->setNum(checkPets());
    readFile(name);

}

mainMenu::mainMenu(QString name, QString token) :
    //QDialog(parent),
    ui(new Ui::mainMenu)
{


    ui->setupUi(this);

    setWindowTitle(tr("Study Pet Adventures"));



    setUsername(name);

    userInfoVector.clear();


    storeInfo(name);
    petInfo.clear();
    userInfoVector[1] = token;
    updateFile(name);

    userInfoVector.clear();

    storeInfo(name);

    qDebug() << petInfo[1];
    setTokens(userInfoVector[1]);




    qDebug() << tokens.length();
    ui->userDataLabel->setText("User Data");
    ui->tokens->setText(userInfoVector[1]);
    ui->petNumberLabel->setNum(checkPets());
    readFile(name);

}



mainMenu::~mainMenu()
{
    delete ui;
}

void mainMenu::readFile(QString name)
{

    QFile myFile("C:\\Users\\Byron\\Desktop\\C++\\QT Stuff\\build-QT_APP-Desktop_Qt_5_6_0_MSVC2015_64bit-Debug\\" + name + ".txt");
    if(!myFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::information(0, "File error", myFile.errorString());
    }


    QTextStream textStream(&myFile);


    ui->userName->setText(textStream.readLine());

    /*for(int i = 0; i < 1; i++)
    {
        ui->tokens->setText(textStream.readLine());
    }*/



    myFile.close();

}

void mainMenu::setUsername(QString name)
{
    this->username = name;
}

QString mainMenu::getName()
{
    return username;
}


void mainMenu::on_createPetButton_clicked()
{
    if(checkPets() != 3)
    {
    createNewPet * newPet = new createNewPet(getName());
    newPet->show();

    close();
    }
    else
        QMessageBox::information(this, tr("Pet creation info") , tr("You may only have three pets at a time!"));
}

int mainMenu::checkPets()
{
     QString petTypes[10] = {"Bunny" , "Cat" , "Dog" , "Dolphin" , "Nick" , "Dragon" , "Parrot" , "Monkey", "Fish" , "Gator"};
     int petTracker = 0;

     for(int i = 0; i < userInfoVector.size(); i++)
     {
         for(int j = 0; j < 10; j++)
         {
             if(userInfoVector[i].compare(petTypes[j]) == 0)
             {

                    petTracker++;

             }
         }
     }


return petTracker;
}

void mainMenu::on_exitButton_clicked()
{
    close();
}

void mainMenu::on_SetTimerButton_clicked()
{
    TimeGrab grabTime;
    grabTime.setModal(true);
    grabTime.exec();

}

void mainMenu::storeInfo(QString name)
{
    QFile myFile("C:\\Users\\Byron\\Desktop\\C++\\QT Stuff\\build-QT_APP-Desktop_Qt_5_6_0_MSVC2015_64bit-Debug\\" + name + ".txt");
    if(!myFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::information(0, "File error", myFile.errorString());
    }


    QTextStream textStream(&myFile);
    QString line;

    while(!textStream.atEnd())
    {
        line = textStream.readLine();
        this->userInfoVector.push_back(line);
    }

    myFile.close();


    QFile myOtherFile("C:\\Users\\Byron\\Desktop\\C++\\QT Stuff\\build-QT_APP-Desktop_Qt_5_6_0_MSVC2015_64bit-Debug\\" + name + "PetHHL.txt");
    if(!myOtherFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::information(0, "File error", myOtherFile.errorString());
    }


    QTextStream text(&myOtherFile);
    QString lne;

    while(!text.atEnd())
    {
        lne = text.readLine();
        this->petInfo.push_back(lne);
    }

    myOtherFile.close();

}

void mainMenu::setTokens(QString tok)
{
    this->tokens = tok;
}

int mainMenu::getTokens()
{
    QString convert = tokens;
    int converted = convert.toInt();


    return converted;

}

void mainMenu::on_bankButton_clicked()
{
    theBank * bank = new theBank(getTokens(), getName());
    bank->show();
    close();

}

void mainMenu::on_shopButton_clicked()
{
    choosePet * choose = new choosePet(userInfoVector);
    choose->show();

    close();
}

void mainMenu::updateFile(QString name)
{
    QFile playerFile(name+".txt");
    qDebug() << name;

    if(playerFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {

        QTextStream text(&playerFile);

        for(int i = 0; i < userInfoVector.size(); i++)
        {
            text << userInfoVector[i] << "\n";
        }
        text.flush();
        playerFile.close();

}

}

void mainMenu::on_viewPetStatsButtonB_clicked()
{
    choosePet * choose = new choosePet(userInfoVector, false, petInfo);
    choose -> show();

}

void mainMenu::on_helpButton_clicked()
{
    help * helpp = new help(this);
    helpp->show();

}
