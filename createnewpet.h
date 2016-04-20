#ifndef CREATENEWPET_H
#define CREATENEWPET_H

#include "seconddialog.h"    //reuses classes from seconddialog.h
#include <QDialog>          //One of Qt's built in gui libraries
#include <QMovie>
#include <QFile>


namespace Ui {              //creates new ui for createNewPet class
class createNewPet;
}

class createNewPet : public QDialog //create new pet is a child class of Qt's QDialog parent class
{
    Q_OBJECT

public:
    explicit createNewPet(QWidget *parent = 0); //creates ui
    createNewPet(QString name);                 //constructor
    ~createNewPet();                            //destructor



private slots:  //the methods that involve user-gui interation

    void on_pushButton_clicked();   //push button one on gui when clicked

    void on_pushButton_2_clicked(); //push button two on gui when clicked

    void on_confirmButton_clicked();//push button "confimButton" on gui when clicked

    void on_pushButton_3_clicked(); //push button 3 on gui when clicked

private:
    Ui::createNewPet *ui;   //ui pointer object
    QString petName;        //new pet's name
    QMovie * movie;         //current pet's type's correesponding animation object
    void setPetName(QString name);  //set's user input as new pet name
    QString getPetName();           //get's pet name
    void setPetType(QString type);  //set's dersired pet's type
    QString getPetType();           //get's pet type
    void setPlayerName(QString name);//set's player's username
    QString getPlayerName();        //get's player's username
    void viewPets(int x);           //displays pets
    void writeHappyHungerLevel();   //Set's happiness and hunger
    int cycle;                      //cycle
    int petNumber;                  //Number corresponding to pet
    QString petType;                //pet's type
    QString playerName;             //user's username
    QString takeText();             //text
    QString getPetPersonality(QString petName); //get's pet's personality



};

#endif // CREATENEWPET_H
