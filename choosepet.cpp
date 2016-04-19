#include "choosepet.h"      //header file
#include "ui_choosepet.h"   //ui header file for gui
#include "mainmenu.h"       //main menu header file to connect the guis
#include "shop.h"           //shop header to display shop

#include <QString>          //Qt's version of string
#include <QVector>          //Qt's built in vector
#include <QDebug>           //Aids in debugging
#include <QMovie>           //Qt's animation class

choosePet::choosePet(QWidget *parent) : //Window that allows the user to choose which type of pet they'd like to choose
    QDialog(parent),
    ui(new Ui::choosePet)
{
    ui->setupUi(this);
}

choosePet::choosePet(QVector<QString> & info) ://Chose from existing pets
    //QDialog(parent),
    ui(new Ui::choosePet)
{
    ui->setupUi(this);

    this->playerName = info[0];     //player username
    this->tokens = info[1].toInt(); //user's tokens

    setEverything(info.size(), info);   //Set's the correct corresponding pet
    qDebug() << petName1;               //debug information
}

choosePet::~choosePet()//Destructor
{
    delete ui;
}

void choosePet::setEverything(int size, QVector<QString> & info)
{
    QString petPathBase = "c:/animations/"; //animations directory
    QString petSuffix1 = " ";               //initializers
    QString petSuffix2 = " ";
    QString petSuffix3 = " ";


    switch(size)
    {

    case 5:

        this->petName1 = info[2];   //pet's name
        this->petType1 = info[3];   //pet type
        this->petPers1 = info[4];   //personality of pet


        petSuffix1 = petType1 + ".gif"; //corresponding pet animation
        petPathBase.append(petSuffix1); //directory of pet animation

        //qDebug() << petPath1;

        //if(petName1.compare)
        gif1 = new QMovie(petPathBase); //Animation object with directory to corresponding animation
        ui->pet1->setMovie(gif1);       //Sets current animation object to display on gui
        gif1->start();                  //Begins animation

        ui->petName1Label->setText(petName1);   //sets corresponding label to pet name
        ui->petPersLabel1->setText(petPers1);   //sets corresponding label to pet personality
        ui->petType1Label->setText(petType1);   //sets corresponding label to pet type

        ui->petName2Label->setVisible(false); //WOLG, sets all widgets bellow to invisible, since there is only one
        ui->petPersLabel2->setVisible(false); //existing pet at the given time
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

        this->petName1 = info[2];   //similarly to case 5, reinstantiates pet1's name, personality, and type- animation path and
        this->petType1 = info[3];   // object- and set's widgets to corresponding values.
        this->petPers1 = info[4];
        this->petName2 = info[5];   //WLOG, creates instance of new pet similarly to case 5
        this->petType2 = info[6];
        this->petPers2 = info[7];

        //creates file path for gif of pet 1
        petSuffix1 = petType1 + ".gif"; 
        petPathBase.append(petSuffix1);


        //pet 1 gif object creation and display
        gif1 = new QMovie(petPathBase); 
        ui->pet1->setMovie(gif1);
        gif1->start();

        //displays pet's traits to ui
        ui->petName1Label->setText(petName1);
        ui->petPersLabel1->setText(petPers1);
        ui->petType1Label->setText(petType1);

        //file path for pet 2's animation
        petPathBase = "c:/animations/";
        petSuffix2 = petType2 + ".gif";
        petPathBase.append(petSuffix2);

        //pet 2's animation object creation and display
        gif2 = new QMovie(petPathBase);
        ui->pet2->setMovie(gif2);
        gif2->start();

        //displays pet 2's name, type, and personality
        ui->petName2Label->setText(petName2);
        ui->petPersLabel2->setText(petPers2);
        ui->petType2Label->setText(petType2);
        
        //sets these widgets as invisible becuase there is no pet three in this case
        ui->petName3Label->setVisible(false);
        ui->petPersLabel3->setVisible(false);
        ui->petType3Label->setVisible(false);

        ui->pushButton3->setVisible(false);
        ui->pet3->setVisible(false);

        break;

    case 11:
    
        /*
            Just like cases 5 and 8, this method takes pet's 1, 2, and 3 names, types, and personalities and creates a file
            path for their corresponding gif animations. After that, the gif file paths are made into animation objects that are
            then displayed on the gui. Finally, all three pet's traits are displayed on the screen and are visible.
        */

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

//when corresponding the corresponding button is pushed for each pet, creates and displays that particular pet's "shop"
void choosePet::on_pushButton1_clicked()
{
    //pet one's shop
    this->chosenPet = 1;
    shop * petShop = new shop(tokens, playerName, chosenPet);
    petShop->show();

    close();
}

void choosePet::on_pushButton2_clicked()
{
    //pet 2's shop
    this->chosenPet = 2;
    shop * petShop = new shop(tokens, playerName, chosenPet);
    petShop->show();

    close();
}

void choosePet::on_pushButton3_clicked()
{
    //pet 3's shop
    this->chosenPet = 3;
    shop * petShop = new shop(tokens, playerName, chosenPet);
    petShop->show();

    close();
}
