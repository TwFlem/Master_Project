#ifndef CREATENEWPET_H
#define CREATENEWPET_H

#include "seconddialog.h"
#include <QDialog>
#include <QMovie>
#include <QFile>


namespace Ui {
class createNewPet;
}

class createNewPet : public QDialog
{
    Q_OBJECT

public:
    explicit createNewPet(QWidget *parent = 0);
    createNewPet(QString name);
    ~createNewPet();



private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_confirmButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::createNewPet *ui;
    QString petName;
    QMovie * movie;
    void setPetName(QString name);
    QString getPetName();
    void setPetType(QString type);
    QString getPetType();
    void setPlayerName(QString name);
    QString getPlayerName();
    void viewPets(int x);
    void writeHappyHungerLevel();
    int cycle;
    int petNumber;
    QString petType;
    QString playerName;
    QString takeText();
    QString getPetPersonality(QString petName);



};

#endif // CREATENEWPET_H
