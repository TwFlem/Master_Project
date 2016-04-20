#include "choosepet.h"
#include "ui_choosepet.h"
#include "mainmenu.h"
#include "shop.h"
#include "timegrab.h"

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

}

choosePet::choosePet(QVector<QString> & info, bool vis, QVector<QString> & pets) :
    //QDialog(parent),
    ui(new Ui::choosePet)
{
    ui->setupUi(this);
    bool visible = vis;

    this->playerName = info[0];
    this->tokens = info[1].toInt();

    setEverything(info.size(), info, visible, pets);

}

choosePet::choosePet(QVector<QString> & info, QVector<QString> & pets) :
    //QDialog(parent),
    ui(new Ui::choosePet)
{
    ui->setupUi(this);

    for(int i =0; i < pets.size(); i++)
    {
        petz.push_back(pets[i]);
    }

    this->playerName = info[0];
    this->tokens = info[1].toInt();

    setEverything(info.size(), info,  pets);

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

    ui->pushButton->setVisible(false);
    ui->chooseTimer1->setVisible(false);
    ui->chooseTimer2->setVisible(false);
    ui->chooseTimer3->setVisible(false);

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
        ui->label_4->setVisible(false);
        ui->label_5->setVisible(false);
        ui->label_6->setVisible(false);
        ui->HappinessLabel1->setVisible(false);
        ui->HungerLabel1->setVisible(false);
        ui->levelLabel1->setVisible(false);

        ui->happinessLabel2->setVisible(false);
        ui->HungerLabel2->setVisible(false);
        ui->levelLabel2->setVisible(false);
        ui->happLabel2->setVisible(false);
        ui->hungrLabel2->setVisible(false);
        ui->lvlLabel2->setVisible(false);
        ui->petName2Label->setVisible(false);
        ui->petPersLabel2->setVisible(false);
        ui->petType2Label->setVisible(false);
        ui->nameLabel2->setVisible(false);
        ui->persLabel2->setVisible(false);
        ui->typeLabel2->setVisible(false);


        ui->happinessLabel3->setVisible(false);
        ui->HungerLabel3->setVisible(false);
        ui->levelLabel3->setVisible(false);
        ui->happLabel3->setVisible(false);
        ui->hungrLabel3->setVisible(false);
        ui->lvlLabel3->setVisible(false);
        ui->petName3Label->setVisible(false);
        ui->petPersLabel3->setVisible(false);
        ui->petType3Label->setVisible(false);
        ui->nameLabel3->setVisible(false);
        ui->persLabel3->setVisible(false);
        ui->typeLabel3->setVisible(false);

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
        ui->label_4->setVisible(false);
        ui->label_5->setVisible(false);
        ui->label_6->setVisible(false);
        ui->HappinessLabel1->setVisible(false);
        ui->HungerLabel1->setVisible(false);
        ui->levelLabel1->setVisible(false);


        petPathBase = "c:/animations/";
        petSuffix2 = petType2 + ".gif";
        petPathBase.append(petSuffix2);


        gif2 = new QMovie(petPathBase);
        ui->pet2->setMovie(gif2);
        gif2->start();

        ui->happinessLabel2->setVisible(false);
        ui->HungerLabel2->setVisible(false);
        ui->levelLabel2->setVisible(false);
        ui->happLabel2->setVisible(false);
        ui->hungrLabel2->setVisible(false);
        ui->lvlLabel2->setVisible(false);
        ui->petName2Label->setText(petName2);
        ui->petPersLabel2->setText(petPers2);
        ui->petType2Label->setText(petType2);

        ui->happinessLabel3->setVisible(false);
        ui->HungerLabel3->setVisible(false);
        ui->levelLabel3->setVisible(false);
        ui->happLabel3->setVisible(false);
        ui->hungrLabel3->setVisible(false);
        ui->lvlLabel3->setVisible(false);
        ui->nameLabel3->setVisible(false);
        ui->persLabel3->setVisible(false);
        ui->typeLabel3->setVisible(false);
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
        ui->label_4->setVisible(false);
        ui->label_5->setVisible(false);
        ui->label_6->setVisible(false);
        ui->HappinessLabel1->setVisible(false);
        ui->HungerLabel1->setVisible(false);
        ui->levelLabel1->setVisible(false);


        petPathBase = "c:/animations/";
        petSuffix2 = petType2 + ".gif";
        petPathBase.append(petSuffix2);


        gif2 = new QMovie(petPathBase);
        ui->pet2->setMovie(gif2);
        gif2->start();

        ui->petName2Label->setText(petName2);
        ui->petPersLabel2->setText(petPers2);
        ui->petType2Label->setText(petType2);
        ui->happinessLabel2->setVisible(false);
        ui->HungerLabel2->setVisible(false);
        ui->levelLabel2->setVisible(false);
        ui->happLabel2->setVisible(false);
        ui->hungrLabel2->setVisible(false);
        ui->lvlLabel2->setVisible(false);

        petPathBase = "c:/animations/";
        petSuffix3 = petType3 + ".gif";
        petPathBase.append(petSuffix3);

        gif3 = new QMovie(petPathBase);
        ui->pet3->setMovie(gif3);
        gif3->start();

        ui->petName3Label->setText(petName3);
        ui->petPersLabel3->setText(petPers3);
        ui->petType3Label->setText(petType3);
        ui->happinessLabel3->setVisible(false);
        ui->HungerLabel3->setVisible(false);
        ui->levelLabel3->setVisible(false);
        ui->happLabel3->setVisible(false);
        ui->hungrLabel3->setVisible(false);
        ui->lvlLabel3->setVisible(false);





        break;


    }
}

void choosePet::on_pushButton1_clicked()
{
    this->chosenPet = getPetType(petType1);

    shop * petShop = new shop(tokens, playerName, 1, chosenPet);
    petShop->show();

    close();
}

void choosePet::on_pushButton2_clicked()
{

    this->chosenPet = getPetType(petType2);
    shop * petShop = new shop(tokens, playerName, 2, chosenPet);
    petShop->show();

    close();
}

void choosePet::on_pushButton3_clicked()
{

    this->chosenPet = getPetType(petType3);
    shop * petShop = new shop(tokens, playerName, 3, chosenPet);
    petShop->show();

    close();
}

int choosePet::getPetType(QString petType)
{
    if(petType.compare("Dog") == 0)
    {
        return 1;
    }
    else if(petType.compare("Cat") == 0)
    {
        return 2;
    }
    else if(petType.compare("Parrot") == 0)
    {
        return 3;
    }
    else if(petType.compare("Dolphin")== 0)
    {
        return 4;
    }
    else if(petType.compare("Nick") == 0)
    {
        return 5;
    }
    else if(petType.compare("Monkey") == 0)
    {
        return 6;
    }
    else if(petType.compare("Bunny") == 0)
    {
        return 7;
    }
    else if(petType.compare("Dragon") == 0)
    {
        return 8;
    }
    else if(petType.compare("Fish") == 0)
    {
        return 9;
    }
    else if(petType.compare("Gator") == 0)
    {
        return 10;
    }
    return 0;

}

void choosePet::setEverything(int size, QVector<QString> & info, bool vis,  QVector<QString> & petz)
{
    QString petPathBase = "c:/animations/";
    QString petSuffix1 = " ";
    QString petSuffix2 = " ";
    QString petSuffix3 = " ";

    ui->pushButton_2->setVisible(false);
    ui->chooseTimer1->setVisible(false);
    ui->chooseTimer2->setVisible(false);
    ui->chooseTimer3->setVisible(false);

    switch(size)
    {

    case 5:

        this->petName1 = info[2];
        this->petType1 = info[3];
        this->petPers1 = info[4];
        this->petHunger1 = petz[1];
        this->petHappiness1 = petz[2];
        this->petLevel1 = petz[3];



        petSuffix1 = petType1 + ".gif";
        petPathBase.append(petSuffix1);



        gif1 = new QMovie(petPathBase);
        ui->pet1->setMovie(gif1);
        gif1->start();

        ui->petName1Label->setText(petName1);
        ui->petPersLabel1->setText(petPers1);
        ui->petType1Label->setText(petType1);
        ui->HungerLabel1->setText(petHunger1);
        ui->HappinessLabel1->setText(petHappiness1);
        ui->levelLabel1->setText(petLevel1);

        ui->nameLabel2->setVisible(vis);
        ui->typeLabel2->setVisible(vis);
        ui->persLabel2->setVisible(vis);
        ui->happLabel2->setVisible(vis);
        ui->hungrLabel2->setVisible(vis);
        ui->lvlLabel2->setVisible(vis);
        ui->happinessLabel2->setVisible(vis);
        ui->HungerLabel2->setVisible(vis);
        ui->levelLabel2->setVisible(vis);
        ui->petName2Label->setVisible(false);
        ui->petPersLabel2->setVisible(false);
        ui->petType2Label->setVisible(false);


        ui->nameLabel3->setVisible(vis);
        ui->typeLabel3->setVisible(vis);
        ui->persLabel3->setVisible(vis);
        ui->happLabel3->setVisible(vis);
        ui->hungrLabel3->setVisible(vis);
        ui->lvlLabel3->setVisible(vis);
        ui->happinessLabel3->setVisible(vis);
        ui->HungerLabel3->setVisible(vis);
        ui->levelLabel3->setVisible(vis);
        ui->petName3Label->setVisible(false);
        ui->petPersLabel3->setVisible(false);
        ui->petType3Label->setVisible(false);

        ui->pet2->setVisible(false);
        ui->pet3->setVisible(false);

        ui->pushButton1->setVisible(vis);
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
        this->petHunger1 = petz[1];
        this->petHappiness1 = petz[2];
        this->petLevel1 = petz[3];
        this->petHunger2 = petz[5];
        this->petHappiness2 = petz[6];
        this->petLevel2 = petz[7];

        petSuffix1 = petType1 + ".gif";
        petPathBase.append(petSuffix1);



        gif1 = new QMovie(petPathBase);
        ui->pet1->setMovie(gif1);
        gif1->start();

        ui->HungerLabel1->setText(petHunger1);
        ui->HappinessLabel1->setText(petHappiness1);
        ui->levelLabel1->setText(petLevel1);
        ui->petName1Label->setText(petName1);
        ui->petPersLabel1->setText(petPers1);
        ui->petType1Label->setText(petType1);

        petPathBase = "c:/animations/";
        petSuffix2 = petType2 + ".gif";
        petPathBase.append(petSuffix2);


        gif2 = new QMovie(petPathBase);
        ui->pet2->setMovie(gif2);
        gif2->start();

        ui->HungerLabel2->setText(petHunger2);
        ui->happinessLabel2->setText(petHappiness2);
        ui->levelLabel2->setText(petLevel2);
        ui->petName2Label->setText(petName2);
        ui->petPersLabel2->setText(petPers2);
        ui->petType2Label->setText(petType2);

        ui->nameLabel3->setVisible(vis);
        ui->typeLabel3->setVisible(vis);
        ui->persLabel3->setVisible(vis);
        ui->happLabel3->setVisible(vis);
        ui->hungrLabel3->setVisible(vis);
        ui->lvlLabel3->setVisible(vis);
        ui->happinessLabel3->setVisible(vis);
        ui->HungerLabel3->setVisible(vis);
        ui->levelLabel3->setVisible(vis);
        ui->petName3Label->setVisible(false);
        ui->petPersLabel3->setVisible(false);
        ui->petType3Label->setVisible(false);

        ui->pushButton1->setVisible(vis);
        ui->pushButton2->setVisible(vis);
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
        this->petHunger1 = petz[1];
        this->petHappiness1 = petz[2];
        this->petLevel1 = petz[3];
        this->petHunger2 = petz[5];
        this->petHappiness2 = petz[6];
        this->petLevel2 = petz[7];
        this->petHunger3 = petz[9];
        this->petHappiness3 = petz[10];
        this->petLevel3 = petz[11];


        petSuffix1 = petType1 + ".gif";
        petPathBase.append(petSuffix1);



        gif1 = new QMovie(petPathBase);
        ui->pet1->setMovie(gif1);
        gif1->start();

        ui->HungerLabel1->setText(petHunger1);
        ui->HappinessLabel1->setText(petHappiness1);
        ui->levelLabel1->setText(petLevel1);
        ui->petName1Label->setText(petName1);
        ui->petPersLabel1->setText(petPers1);
        ui->petType1Label->setText(petType1);

        petPathBase = "c:/animations/";
        petSuffix2 = petType2 + ".gif";
        petPathBase.append(petSuffix2);


        gif2 = new QMovie(petPathBase);
        ui->pet2->setMovie(gif2);
        gif2->start();

        ui->HungerLabel2->setText(petHunger2);
        ui->happinessLabel2->setText(petHappiness2);
        ui->levelLabel2->setText(petLevel2);
        ui->petName2Label->setText(petName2);
        ui->petPersLabel2->setText(petPers2);
        ui->petType2Label->setText(petType2);

        petPathBase = "c:/animations/";
        petSuffix3 = petType3 + ".gif";
        petPathBase.append(petSuffix3);

        gif3 = new QMovie(petPathBase);
        ui->pet3->setMovie(gif3);
        gif3->start();

        ui->HungerLabel3->setText(petHunger3);
        ui->happinessLabel3->setText(petHappiness3);
        ui->levelLabel3->setText(petLevel3);
        ui->petName3Label->setText(petName3);
        ui->petPersLabel3->setText(petPers3);
        ui->petType3Label->setText(petType3);

        ui->pushButton1->setVisible(vis);
        ui->pushButton2->setVisible(vis);
        ui->pushButton3->setVisible(vis);




        break;


    }
}


void choosePet::on_pushButton_clicked()
{
    close();
}

void choosePet::on_pushButton_2_clicked()
{
    mainMenu * main = new mainMenu(playerName);
    main->show();
    close();
}


void choosePet::setEverything(int size, QVector<QString> & info, QVector<QString> & pets)
{
    QString petPathBase = "c:/animations/";
    QString petSuffix1 = " ";
    QString petSuffix2 = " ";
    QString petSuffix3 = " ";
    QString petLevelss = pets[1];
    petLevelss = 1;

    ui->pushButton->setVisible(false);
    ui->pushButton1->setVisible(false);
    ui->pushButton2->setVisible(false);
    ui->pushButton3->setVisible(false);

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
        ui->label_4->setVisible(false);
        ui->label_5->setVisible(false);
        ui->label_6->setVisible(false);
        ui->HappinessLabel1->setVisible(false);
        ui->HungerLabel1->setVisible(false);
        ui->levelLabel1->setVisible(false);

        ui->happinessLabel2->setVisible(false);
        ui->HungerLabel2->setVisible(false);
        ui->levelLabel2->setVisible(false);
        ui->happLabel2->setVisible(false);
        ui->hungrLabel2->setVisible(false);
        ui->lvlLabel2->setVisible(false);
        ui->petName2Label->setVisible(false);
        ui->petPersLabel2->setVisible(false);
        ui->petType2Label->setVisible(false);
        ui->nameLabel2->setVisible(false);
        ui->persLabel2->setVisible(false);
        ui->typeLabel2->setVisible(false);


        ui->happinessLabel3->setVisible(false);
        ui->HungerLabel3->setVisible(false);
        ui->levelLabel3->setVisible(false);
        ui->happLabel3->setVisible(false);
        ui->hungrLabel3->setVisible(false);
        ui->lvlLabel3->setVisible(false);
        ui->petName3Label->setVisible(false);
        ui->petPersLabel3->setVisible(false);
        ui->petType3Label->setVisible(false);
        ui->nameLabel3->setVisible(false);
        ui->persLabel3->setVisible(false);
        ui->typeLabel3->setVisible(false);

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
        ui->label_4->setVisible(false);
        ui->label_5->setVisible(false);
        ui->label_6->setVisible(false);
        ui->HappinessLabel1->setVisible(false);
        ui->HungerLabel1->setVisible(false);
        ui->levelLabel1->setVisible(false);


        petPathBase = "c:/animations/";
        petSuffix2 = petType2 + ".gif";
        petPathBase.append(petSuffix2);


        gif2 = new QMovie(petPathBase);
        ui->pet2->setMovie(gif2);
        gif2->start();

        ui->happinessLabel2->setVisible(false);
        ui->HungerLabel2->setVisible(false);
        ui->levelLabel2->setVisible(false);
        ui->happLabel2->setVisible(false);
        ui->hungrLabel2->setVisible(false);
        ui->lvlLabel2->setVisible(false);
        ui->petName2Label->setText(petName2);
        ui->petPersLabel2->setText(petPers2);
        ui->petType2Label->setText(petType2);

        ui->happinessLabel3->setVisible(false);
        ui->HungerLabel3->setVisible(false);
        ui->levelLabel3->setVisible(false);
        ui->happLabel3->setVisible(false);
        ui->hungrLabel3->setVisible(false);
        ui->lvlLabel3->setVisible(false);
        ui->nameLabel3->setVisible(false);
        ui->persLabel3->setVisible(false);
        ui->typeLabel3->setVisible(false);
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
        ui->label_4->setVisible(false);
        ui->label_5->setVisible(false);
        ui->label_6->setVisible(false);
        ui->HappinessLabel1->setVisible(false);
        ui->HungerLabel1->setVisible(false);
        ui->levelLabel1->setVisible(false);


        petPathBase = "c:/animations/";
        petSuffix2 = petType2 + ".gif";
        petPathBase.append(petSuffix2);


        gif2 = new QMovie(petPathBase);
        ui->pet2->setMovie(gif2);
        gif2->start();

        ui->petName2Label->setText(petName2);
        ui->petPersLabel2->setText(petPers2);
        ui->petType2Label->setText(petType2);
        ui->happinessLabel2->setVisible(false);
        ui->HungerLabel2->setVisible(false);
        ui->levelLabel2->setVisible(false);
        ui->happLabel2->setVisible(false);
        ui->hungrLabel2->setVisible(false);
        ui->lvlLabel2->setVisible(false);

        petPathBase = "c:/animations/";
        petSuffix3 = petType3 + ".gif";
        petPathBase.append(petSuffix3);

        gif3 = new QMovie(petPathBase);
        ui->pet3->setMovie(gif3);
        gif3->start();

        ui->petName3Label->setText(petName3);
        ui->petPersLabel3->setText(petPers3);
        ui->petType3Label->setText(petType3);
        ui->happinessLabel3->setVisible(false);
        ui->HungerLabel3->setVisible(false);
        ui->levelLabel3->setVisible(false);
        ui->happLabel3->setVisible(false);
        ui->hungrLabel3->setVisible(false);
        ui->lvlLabel3->setVisible(false);


        break;


    }
}

void choosePet::on_chooseTimer1_clicked()
{
    QString tokes = QString::number(tokens);
    TimeGrab * time = new TimeGrab(petz, 1, playerName, tokes);
    time->show();
    close();
}

void choosePet::on_chooseTimer2_clicked()
{
    QString tokes = QString::number(tokens);
    TimeGrab * time = new TimeGrab(petz, 2, playerName, tokes);
    time->show();
    close();
}

void choosePet::on_chooseTimer3_clicked()
{
    QString tokes = QString::number(tokens);
    TimeGrab * time = new TimeGrab(petz, 3, playerName, tokes);
    time->show();
    close();
}
