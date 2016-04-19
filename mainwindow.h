#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "seconddialog.h" //Needed for modaless approach
#include "createnewplayer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QVector <QString> stringVector;

private slots:
    void on_pushButton_clicked();

    void on_pushButtonYes_clicked();

    void on_pushButton_2No_clicked();

private:
    Ui::MainWindow *ui;
    void getTextFile();
    QString userName;
    QString passWord;
    void setUsername(QString x);
    void setPassword(QString x);
    QString getPassword();
    QString getUsername();
    SecondDialog * secDialog;
    createNewPlayer * newPlayer;


};

#endif // MAINWINDOW_H
