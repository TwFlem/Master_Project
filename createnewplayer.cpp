#include "createnewplayer.h"
#include "ui_createnewplayer.h"
#include <QMessageBox>
#include <QFile>
#include <QtCore/QTextStream>
#include "seconddialog.h"
#include <QtDebug>
#include <QFileInfo>

createNewPlayer::createNewPlayer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createNewPlayer)
{
    ui->setupUi(this);
    setWindowTitle(tr("New Player Creation"));
}

createNewPlayer::~createNewPlayer()
{
    delete ui;
}

void createNewPlayer::on_pushButton_clicked()
{
    //set Username for player
   QString name =  ui->lineEdit->text();
   createPlayerFile(name);

   //p->setusername(userName);

}

void createNewPlayer::createPlayerFile(QString name)
{
    setPlayerName(name);
    QFile playerFile(name+".txt");
    qDebug() << name;

    if(playerFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, tr("Player Creation Error"), tr("User with this name already exist please choose a different name"));
        playerFile.close();
        return;
    }
    else{
        if(playerFile.open(QIODevice::WriteOnly | QIODevice::Text))
        {

            QTextStream text(&playerFile);
            text << name << "\n" << "100" <<  "\n";
            text.flush();
            playerFile.close();

            QMessageBox::information(this, tr("Player Creation Successful!"), tr("Welcome to the game! Your text file has been created you may exit."));
            newPetWindow = new createNewPet(getPlayerName());
            newPetWindow->show();

            close();



        }
    }

}

bool createNewPlayer::checkifFileExists(QString file)
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

void createNewPlayer::setPlayerName(QString name)
{
    this->player = name;
}

QString createNewPlayer::getPlayerName()
{
    return player;
}

