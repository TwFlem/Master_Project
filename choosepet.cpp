#include "choosepet.h"
#include "ui_choosepet.h"
#include "mainmenu.h"
#include "shop.h"

#include <QString>
#include <QVector>
#include <QDebug>
#include <QMovie>

choosePet::choosePet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::choosePet)
{
    ui->setupUi(this);
}

choosePet::choosePet(QVector<QString> & info) :
    //QDialog(parent),
    ui(new Ui::choosePet)
{
    ui->setupUi(this);

    this->playerName = info[0];
    this->tokens = info[1].toInt();

    setEverything(info.size(), info);
    qDebug() << petName1;
}

choosePet::~choosePet()
{
    delete ui;
}

void choosePet::setEverything(int size, QVector<QString> & info)
{
    QString petPathBase = "c:/animations/";
    QString petSuffix1 = " ";
    QString petSuffix2 = " ";
    QString petSuffix3 = " ";


    switch(size)
    {

    case 5:

        this->petName1 = info[2];
        this->petType1 = info[3];
        this->petPers1 = info[4];


        petSuffix1 = petType1 + ".gif";
        petPathBase.append(petSuffix1);

        //qDebug() << petPath1;

        //if(petName1.compare)
        gif1 = new QMovie(petPathBase);
        ui->pet1->setMovie(gif1);
        gif1->start();

        ui->petName1Label->setText(petName1);
        ui->petPersLabel1->setText(petPers1);
        ui->petType1Label->setText(petType1);

        ui->petName2Label->setVisible(false);
        ui->petPersLabel2->setVisible(false);
        ui->petType2Label->setVisible(false);

        ui->petName3Label->setVisible(false);
        ui->petPersLabel3->setVisible(false);
        ui->petType3Label->setVisible(false);

        ui->pet2->setVisible(false);
        ui->pet3->setVisible(false);

        ui->pushButton2->setVisible(false);
        ui->pushButton3->setVisible(false);

        break;

    case 8:

        this->petName1 = info[2];
        this->petType1 = info[3];
        this->petPers1 = info[4];
        this->petName2 = info[5];
        this->petType2 = info[6];
        this->petPers2 = info[7];

        petSuffix1 = petType1 + ".gif";
        petPathBase.append(petSuffix1);



        gif1 = new QMovie(petPathBase);
        ui->pet1->setMovie(gif1);
        gif1->start();

        ui->petName1Label->setText(petName1);
        ui->petPersLabel1->setText(petPers1);
        ui->petType1Label->setText(petType1);

        petPathBase = "c:/animations/";
        petSuffix2 = petType2 + ".gif";
        petPathBase.append(petSuffix2);


        gif2 = new QMovie(petPathBase);
        ui->pet2->setMovie(gif2);
        gif2->start();

        ui->petName2Label->setText(petName2);
        ui->petPersLabel2->setText(petPers2);
        ui->petType2Label->setText(petType2);

        ui->petName3Label->setVisible(false);
        ui->petPersLabel3->setVisible(false);
        ui->petType3Label->setVisible(false);

        ui->pushButton3->setVisible(false);
        ui->pet3->setVisible(false);

        break;

    case 11:

        this->petName1 = info[2];
        this->petType1 = info[3];
        this->petPers1 = info[4];
        this->petName2 = info[5];
        this->petType2 = info[6];
        this->petPers2 = info[7];
        this->petName3 = info[8];
        this->petType3 = info[9];
        this->petPers3 = info[10];


        petSuffix1 = petType1 + ".gif";
        petPathBase.append(petSuffix1);



        gif1 = new QMovie(petPathBase);
        ui->pet1->setMovie(gif1);
        gif1->start();

        ui->petName1Label->setText(petName1);
        ui->petPersLabel1->setText(petPers1);
        ui->petType1Label->setText(petType1);

        petPathBase = "c:/animations/";
        petSuffix2 = petType2 + ".gif";
        petPathBase.append(petSuffix2);


        gif2 = new QMovie(petPathBase);
        ui->pet2->setMovie(gif2);
        gif2->start();

        ui->petName2Label->setText(petName2);
        ui->petPersLabel2->setText(petPers2);
        ui->petType2Label->setText(petType2);

        petPathBase = "c:/animations/";
        petSuffix3 = petType3 + ".gif";
        petPathBase.append(petSuffix3);

        gif3 = new QMovie(petPathBase);
        ui->pet3->setMovie(gif3);
        gif3->start();

        ui->petName3Label->setText(petName3);
        ui->petPersLabel3->setText(petPers3);
        ui->petType3Label->setText(petType3);




        break;


    }
}

void choosePet::on_pushButton1_clicked()
{
    this->chosenPet = 1;
    shop * petShop = new shop(tokens, playerName, chosenPet);
    petShop->show();

    close();
}

void choosePet::on_pushButton2_clicked()
{

    this->chosenPet = 2;
    shop * petShop = new shop(tokens, playerName, chosenPet);
    petShop->show();

    close();
}

void choosePet::on_pushButton3_clicked()
{

    this->chosenPet = 3;
    shop * petShop = new shop(tokens, playerName, chosenPet);
    petShop->show();

    close();
}
