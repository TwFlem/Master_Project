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
    explicit mainMenu(QWidget *parent = 0);
    mainMenu(QString user);
    mainMenu(QString user, QString token);
    ~mainMenu();

private slots:


    void on_createPetButton_clicked();

    void on_exitButton_clicked();

    void on_SetTimerButton_clicked();

    void on_bankButton_clicked();

    void on_shopButton_clicked();

    void on_viewPetStatsButtonB_clicked();

    void on_helpButton_clicked();

private:
    Ui::mainMenu *ui;
    void readFile(QString name);
    QString username;
    void setUsername(QString name);
    QString getName();
    void setTokens(QString tok);
    int getTokens();
    int checkPets();
    void storeInfo(QString name);
    void updateFile(QString name);
    QVector<QString> userInfoVector;
    QVector<QString> petInfo;
    QString tokens;



};

#endif // MAINMENU_H
