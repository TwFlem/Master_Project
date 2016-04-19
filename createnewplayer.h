#ifndef CREATENEWPLAYER_H
#define CREATENEWPLAYER_H

#include <QDialog>
#include <QFile>
#include <QLineEdit>
#include "seconddialog.h"
#include "createnewpet.h"

namespace Ui {
class createNewPlayer;
}

class createNewPlayer : public QDialog
{
    Q_OBJECT

public:
    explicit createNewPlayer(QWidget *parent = 0); //create new player gui
    ~createNewPlayer();



private slots:
    void on_pushButton_clicked();//Corresponding button when clicked


private:
    Ui::createNewPlayer *ui;
    createNewPet * newPetWindow ;           //pointer to acess newpetwindow gui
    void createPlayerFile(QString name);    //writes player information to text file
    bool checkifFileExists(QString player); //checks of a txt file containing data exists
    void setPlayerName(QString name);       //set's player's name
    QString getPlayerName();                //gets player's name
    QString player;                         //player name


};

#endif // CREATENEWPLAYER_H
