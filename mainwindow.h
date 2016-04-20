#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "seconddialog.h" //Needed for modaless approach
#include "createnewplayer.h"

namespace Ui {
class MainWindow;//main window gui
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QVector <QString> stringVector; //vector for soring information

private slots:
    void on_pushButton_clicked();   //function for clicking buttton on gui

    void on_pushButtonYes_clicked();//function for clicking yes on gui

    void on_pushButton_2No_clicked();//function for clicking no on gui

private:
    Ui::MainWindow *ui;
    void getTextFile();         //gets text file
    QString userName;           //gets username
    QString passWord;           //gets password
    void setUsername(QString x);//sets username
    void setPassword(QString x);//sets password
    QString getPassword();      //returns password
    QString getUsername();      //returns username
    SecondDialog * secDialog;   //point towards second dialog gui
    createNewPlayer * newPlayer;//points to newly created player


};

#endif // MAINWINDOW_H
