#ifndef MAINMENU_H
#define MAINMENU_H

#include "createnewpet.h"
#include "seconddialog.h"
#include "shop.h"
#include <QDialog>
#include <QFile>
#include <QString>
#include <QVector>

namespace Ui {
class mainMenu;
}

class mainMenu : public QDialog
{
    Q_OBJECT

public:
    explicit mainMenu(QWidget *parent = 0); //main menu constructor
    mainMenu(QString user);                 //main menu with username inout
    mainMenu(QString user, QString token);  //main menu with username and token amount input
    ~mainMenu();

private slots:


    void on_createPetButton_clicked();  //open create pet gui

    void on_exitButton_clicked();       //exits program

    void on_SetTimerButton_clicked();   //opens study timer

    void on_bankButton_clicked();       //opens bank gui

    void on_shopButton_clicked();       //opens shop gui

    void on_viewPetStatsButtonB_clicked();//open pet stats gui

    void on_helpButton_clicked();       //opens help message box

private:
    Ui::mainMenu *ui;           //gui
    void readFile(QString name);//read file function
    QString username;           //username variable
    void setUsername(QString name);//sets the username
    QString getName();          //get's username
    void setTokens(QString tok);//updates current tokens
    int getTokens();            //get's user tokens
    int checkPets();            //checks pets
    void storeInfo(QString name);//gathers store info
    void updateFile(QString name);//updates text file
    QVector<QString> userInfoVector;//stores user info
    QVector<QString> petInfo;//stores pet info
    QString tokens;//represents user tokens



};

#endif // MAINMENU_H
