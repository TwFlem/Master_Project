#include "createnewpet.h"
#include "ui_createnewpet.h"
#include "createnewplayer.h"
#include "seconddialog.h"
#include "mainmenu.h"
#include <QMessageBox>
#include <QMovie>
#include <QLabel>
#include <QDebug>
#include <QFile>
#include <QChar>


createNewPet::createNewPet(QWidget *parent) :   //create pet constructor
    QDialog(parent),
    ui(new Ui::createNewPet)
{
    ui->setupUi(this);  //create new pet gui

    this->cycle = 0;    //cycle of pets to choose from


    movie = new QMovie("c:/animations/Bunny.gif");  //bunny gif instantiation and display
    qDebug() << movie->isValid();
    ui->gifLabel->setMovie(movie);
    movie->start();
}

createNewPet::createNewPet(QString name) :  //creates new pet object with name as desired
    //QDialog(parent),
    ui(new Ui::createNewPet)
{
    ui->setupUi(this);  //gui setup

    setWindowFlags(Qt::WindowTitleHint);    //sets window title

    setWindowTitle(tr("Fantastic Pet Creator"));
    setPlayerName(name);
    this->cycle = 0;

    //bunny gif instantiation and display
    movie = new QMovie("c:/animations/Bunny.gif");
    setPetType("Bunny");
    qDebug() << movie->isValid();
    ui->gifLabel->setMovie(movie);
    movie->start();
}


createNewPet::~createNewPet()//deconstructor
{
    delete ui;
}

void createNewPet::setPetName(QString name)//sets pet's name
{
    //get's name from gui and set's the pet's name
    name = ui->petName->text();
    this->petName = name;
}

QString createNewPet::getPetName()//returns pet's name
{
    return petName;
}

void createNewPet::viewPets(int x)//view pets to choose from

{
    //path to get pet animations
    QString petPath;

    //the cycle of choosing a pet
    x = cycle;

    //the cycle is: Bunny, Cat, Dog, Dolphin, Dragon, Fish, Dragon, Gator, Monkey, Nick, Parrot
    if(x == 0)
    {
        setPetType("Bunny");
        petPath = "c:/animations/Bunny.gif";

    }
    else if(x == 1)
    {
        setPetType("Cat");
        petPath = "c:/animations/Cat.gif";
    }
    else if(x == 2)
    {
        setPetType("Dog");
        petPath ="c:/animations/Dog.gif";
    }
    else if(x == 3)
    {
        setPetType("Dolphin");
        petPath ="c:/animations/Dolphin.gif";
    }
    else if(x == 4)
    {
        setPetType("Dragon");
        petPath ="c:/animations/Dragon.gif";
    }
    else if(x == 5)
    {
        setPetType("Fish");
        petPath ="c:/animations/Fish.gif";
    }
    else if(x == 6)
    {
        setPetType("Gator");
        petPath ="c:/animations/Gator.gif";
    }
    else if(x == 7)
    {
        setPetType("Monkey");
        petPath ="c:/animations/Monkey.gif";
    }
    else if(x == 8)
    {
        setPetType("Nick");
        petPath ="c:/animations/Nick.gif";
    }
    else if(x == 9)
    {
        setPetType("Parrot");
        petPath ="c:/animations/Parrot.gif";
    }

    movie = new QMovie(petPath);
    ui->gifLabel->setMovie(movie);
    movie->start();

}

void createNewPet::on_pushButton_clicked()      //next button
{

    this->cycle += 1;
    if(cycle > 9)
        cycle = 0;

    viewPets(cycle);
}


void createNewPet::on_pushButton_2_clicked()    //back button
{
    this->cycle -= 1;
    if(cycle < 0)
        cycle = 9;


    viewPets(cycle);
}

void createNewPet::setPetType(QString type) //Set pet types
{
    this->petType = type;
}

QString createNewPet::getPetType() //returns pet types
{
    return petType;
}

void createNewPet::on_confirmButton_clicked() //when clicked, confirms pet creation
{

    writeHappyHungerLevel();

    setPetName(ui->petName->text());
    QString petPersonality = getPetPersonality(getPetName());
    QString playerName = getPlayerName();

    QFile playerFile(playerName+".txt");


    //if file exists
    if(playerFile.open(QIODevice::Append | QIODevice::Text))
    {

        QTextStream text(&playerFile);

        text << getPetName() << "\n" << getPetType() << "\n" << petPersonality << "\n";

        text.flush();
        playerFile.close();

        QMessageBox::information(this, tr("Pet Creation Successful!"), tr("Your pet has been created!"));


        mainMenu * main = new mainMenu(getPlayerName());
        main->show();

        close();

    }
}


void createNewPet::setPlayerName(QString name)//set player name
{
    this->playerName = name;
}

QString createNewPet::getPlayerName()//returns player name
{
    return playerName;
}

QString createNewPet::getPetPersonality(QString petName)//returns personality
{
    QString personality;
    int lengthName = petName.length();
    QChar firstLetter = 'a';
    if(lengthName >= 1)
    {
        firstLetter = petName.at(0);
    }


    //Randomly generated personalit of pet based on number
    int difference = (firstLetter.toLatin1() - 'A');

    if(difference > 25)
    {
        difference = difference + 'A';
        difference = difference - 'a';
    }

    if(difference % 10 == 0)
    {
        personality = "Adventurous";
    }

    else if(difference % 10 == 1)
    {
        personality = "Affectionate";
    }

    else if(difference % 10 == 2)
    {
        personality = "Aggresive";
    }

    else if(difference % 10 == 3)
    {
        personality = "Anxious";
    }

    else if(difference % 10 == 4)
    {
        personality = "Calm";
    }

    else if(difference%10 == 5)
    {
        personality= "Cautious";
    }

    else if(difference%10 == 6)
    {
        personality= "Charming";
    }

    else if(difference%10 == 7)
    {
        personality= "Cheerful";
    }
    else if(difference%10 == 8)
    {
        personality= "Easygoing";
    }
    else if(difference%10 == 9)
    {
        personality= "Enthusiastic";
    }

       return personality;
}

//Allows pet to be created
void createNewPet::on_pushButton_3_clicked()
{
    petNumber-= 1;

    mainMenu * main = new mainMenu(getPlayerName());
    main->show();

    close();
}

//Writes current hunger level to pet
void createNewPet::writeHappyHungerLevel()
{
    QString playerName = getPlayerName();

    QFile playerFile(playerName +"PetHHL"+".txt");

    setPetName(ui->petName->text());




    if(playerFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {

        playerFile.close();


        if(playerFile.open(QIODevice::Append | QIODevice::Text))
        {

            QTextStream text(&playerFile);

            text << petName << "\n" << "70" << "\n" << "70" << "\n" << "1" << "\n";

            text.flush();
            playerFile.close();


        }

    }
    else
    {

    if(playerFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {

        QTextStream text(&playerFile);

        text << petName << "\n" << "70" << "\n" << "70" << "\n" << "1" << "\n";

        text.flush();
        playerFile.close();

    }
   }
}
