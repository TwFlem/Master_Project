#include "createnewplayer.h"
#include "ui_createnewplayer.h"
#include <QMessageBox>
#include <QFile>
#include <QtCore/QTextStream>
#include "seconddialog.h"
#include <QtDebug>
#include <QFileInfo>

createNewPlayer::createNewPlayer(QWidget *parent) : //Create new player constructor
    QDialog(parent),
    ui(new Ui::createNewPlayer)
{
    ui->setupUi(this);  //creates gui
    setWindowTitle(tr("New Player Creation"));  //sets gui title
}

createNewPlayer::~createNewPlayer()//destructor
{
    delete ui;
}

void createNewPlayer::on_pushButton_clicked()   //when clicked...
{
    //set Username for player
   QString name =  ui->lineEdit->text();
   createPlayerFile(name);

   //p->setusername(userName);

}

void createNewPlayer::createPlayerFile(QString name)    //create new player with designated name
{
    setPlayerName(name);            //set's player with desired name
    QFile playerFile(name+".txt");  //reads player file
    qDebug() << name;

    if(playerFile.open(QIODevice::ReadOnly | QIODevice::Text))  //sends error because username already exists
    {
        QMessageBox::warning(this, tr("Player Creation Error"), tr("User with this name already exist please choose a different name"));
        playerFile.close();
        return;
    }
    else{
        if(playerFile.open(QIODevice::WriteOnly | QIODevice::Text)) //allows new player to be created
        {
            
            //writes to new file
            QTextStream text(&playerFile);
            text << name << "\n" << "100" <<  "\n";
            text.flush();
            playerFile.close();
            
            //alerts user that username has been created
            QMessageBox::information(this, tr("Player Creation Successful!"), tr("Welcome to the game! Your text file has been created you may exit."));
            newPetWindow = new createNewPet(getPlayerName());
            newPetWindow->show();

            close();



        }
    }

}

bool createNewPlayer::checkifFileExists(QString file) //checks to see if username already exists
{

    QFileInfo check_file(file);

    if(check_file.exists() && check_file.isFile())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void createNewPlayer::setPlayerName(QString name)   //set's player name to file
{
    this->player = name;
}

QString createNewPlayer::getPlayerName()    //returns username
{
    return player;
}

