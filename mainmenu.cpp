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

mainMenu::mainMenu(QWidget *parent) :   //initial constructor
    QDialog(parent),
    ui(new Ui::mainMenu)
{
    ui->setupUi(this);
}

mainMenu::mainMenu(QString name) : //constructor with username arguement
    //QDialog(parent),
    ui(new Ui::mainMenu)
{


    ui->setupUi(this);  //sets up gui

    setWindowTitle(tr("Study Pet Adventures")); //title of gui



    setUsername(name);  //change username as dersired
    storeInfo(name);    //gather information of particular user
    qDebug () << petInfo[1];    //debug info
    setTokens(userInfoVector[1]);//set's up user's tokens
    qDebug() << tokens.length();
    ui->userDataLabel->setText("User Data");//set's data label
    ui->tokens->setText(userInfoVector[1]);//set's token label
    ui->petNumberLabel->setNum(checkPets());//set's pet type
    readFile(name);//reads file of designated user

}

mainMenu::mainMenu(QString name, QString token) :
    //QDialog(parent),
    ui(new Ui::mainMenu)
{

    //sets up main menu
    ui->setupUi(this);

    //main window title
    setWindowTitle(tr("Study Pet Adventures"));


    //sets current user
    setUsername(name);

    //clears out old user data
    userInfoVector.clear();

    //read's user's store info and pet info. updates text file with current info
    storeInfo(name);
    petInfo.clear();
    userInfoVector[1] = token;
    updateFile(name);

    //clears temporary data
    userInfoVector.clear();

    //gathers current store info
    storeInfo(name);

    //sets user tokens as current read tokens
    qDebug() << petInfo[1];
    setTokens(userInfoVector[1]);



    //updates tokens in gui
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

//reads user text file
void mainMenu::readFile(QString name)
{
    //opens file
    QFile myFile("C:\\Users\\Byron\\Desktop\\C++\\QT Stuff\\build-QT_APP-Desktop_Qt_5_6_0_MSVC2015_64bit-Debug\\" + name + ".txt");
    if(!myFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::information(0, "File error", myFile.errorString());
    }

    //input stream
    QTextStream textStream(&myFile);

    //reads from line of file and sets dersired data in gui
    ui->userName->setText(textStream.readLine());

    /*for(int i = 0; i < 1; i++)
    {
        ui->tokens->setText(textStream.readLine());
    }*/


    //close buffer
    myFile.close();

}

//sets username
void mainMenu::setUsername(QString name)
{
    this->username = name;
}

//gets username
QString mainMenu::getName()
{
    return username;
}

//when create pet button is clicked on gui...
void mainMenu::on_createPetButton_clicked()
{
    //if less than 3 pets
    if(checkPets() != 3)
    {
        //create new pet
    createNewPet * newPet = new createNewPet(getName());
    newPet->show();

    close();
    }
    //else, not allowed to make a 4th pet
    else
        QMessageBox::information(this, tr("Pet creation info") , tr("You may only have three pets at a time!"));
}

//checks pet information
int mainMenu::checkPets()
{
    //data of pet types
     QString petTypes[10] = {"Bunny" , "Cat" , "Dog" , "Dolphin" , "Nick" , "Dragon" , "Parrot" , "Monkey", "Fish" , "Gator"};
     int petTracker = 0;
    //returns types of pet
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

//closes gui
void mainMenu::on_exitButton_clicked()
{
    close();
}

//opens timer gui
void mainMenu::on_SetTimerButton_clicked()
{
    TimeGrab grabTime;
    grabTime.setModal(true);
    grabTime.exec();

}

//rewrites updated info to text file
void mainMenu::storeInfo(QString name)
{
    QFile myFile("C:\\Users\\Byron\\Desktop\\C++\\QT Stuff\\build-QT_APP-Desktop_Qt_5_6_0_MSVC2015_64bit-Debug\\" + name + ".txt");
    if(!myFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::information(0, "File error", myFile.errorString());
    }

    //writes to text file
    QTextStream textStream(&myFile);
    QString line;

    while(!textStream.atEnd())
    {
        line = textStream.readLine();
        this->userInfoVector.push_back(line);
    }

    myFile.close();

    //opens master text file
    QFile myOtherFile("C:\\Users\\Byron\\Desktop\\C++\\QT Stuff\\build-QT_APP-Desktop_Qt_5_6_0_MSVC2015_64bit-Debug\\" + name + "PetHHL.txt");
    if(!myOtherFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::information(0, "File error", myOtherFile.errorString());
    }

    //reads master text file
    QTextStream text(&myOtherFile);
    QString lne;

    while(!text.atEnd())
    {
        lne = text.readLine();
        this->petInfo.push_back(lne);
    }

    myOtherFile.close();

}

//set's user token count
void mainMenu::setTokens(QString tok)
{
    this->tokens = tok;
}

//get's user token count
int mainMenu::getTokens()
{
    QString convert = tokens;
    int converted = convert.toInt();


    return converted;

}

//opens up bank gui
void mainMenu::on_bankButton_clicked()
{
    theBank * bank = new theBank(getTokens(), getName());
    bank->show();
    close();

}

//opens up shop
void mainMenu::on_shopButton_clicked()
{
    choosePet * choose = new choosePet(userInfoVector);
    choose->show();

    close();
}

//updates text file
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

//veiws pet;s current happiness, hunger, and experience.
void mainMenu::on_viewPetStatsButtonB_clicked()
{
    choosePet * choose = new choosePet(userInfoVector, false, petInfo);
    choose -> show();

}

//displays help for user
void mainMenu::on_helpButton_clicked()
{
    help * helpp = new help(this);
    helpp->show();

}
