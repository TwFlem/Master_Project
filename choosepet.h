#ifndef CHOOSEPET_H
#define CHOOSEPET_H

#include <QString>
#include <QVector>
#include <QMovie>
#include <QDialog>

namespace Ui {
class choosePet;
}

class choosePet : public QDialog
{
    Q_OBJECT

public:
    explicit choosePet(QWidget *parent = 0);
    choosePet(QVector<QString> & info);
    choosePet(QVector<QString> &info, bool visible, QVector<QString> & pets);
    choosePet(QVector<QString> &info, QVector<QString> &pets);
    ~choosePet();

private slots:
    void on_pushButton1_clicked();

    void on_pushButton2_clicked();

    void on_pushButton3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_chooseTimer1_clicked();

    void on_chooseTimer2_clicked();

    void on_chooseTimer3_clicked();

private:
    Ui::choosePet *ui;
    QString petType1;
    QString petType2;
    QString petType3;
    QString petName1;
    QString petName2;
    QString petName3;
    QString petPers1;
    QString petPers2;
    QString petPers3;
    QString playerName;
    QString petLevel1;
    QString petLevel2;
    QString petLevel3;
    QString petHunger1;
    QString petHunger2;
    QString petHunger3;
    QString petHappiness1;
    QString petHappiness2;
    QString petHappiness3;
    QVector<QString> petz;
    int tokens;
    int chosenPet;
    int getPetType(QString petType);
    QMovie * gif1;
    QMovie * gif2;
    QMovie * gif3;
    void setEverything(int size, QVector<QString> & info); //to go shopping only shows name, type, and personality
    void setEverything(int size, QVector<QString> & info, bool vis, QVector<QString> & pets); //To view stats has all variables
    void setEverything(int size, QVector<QString> & info,  QVector<QString> & pets); //used when to choose study buddy

};

#endif // CHOOSEPET_H
