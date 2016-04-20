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
    explicit createNewPlayer(QWidget *parent = 0);
    ~createNewPlayer();



private slots:
    void on_pushButton_clicked();


private:
    Ui::createNewPlayer *ui;
    createNewPet * newPetWindow ;
    void createPlayerFile(QString name);
    bool checkifFileExists(QString player);
    void setPlayerName(QString name);
    QString getPlayerName();
    QString player;


};

#endif // CREATENEWPLAYER_H
