#ifndef SECONDDIALOG_H
#define SECONDDIALOG_H

#include "mainmenu.h"
#include <QDialog>

namespace Ui {
class SecondDialog;
}

class SecondDialog : public QDialog //second dialog class
{
    Q_OBJECT

public:
    explicit SecondDialog(QWidget *parent = 0);
    ~SecondDialog();

private slots:
    void on_pushButton_clicked();   //verifies if username is correct

    void on_pushButton_2_clicked(); //exits gui

private:
    Ui::SecondDialog *ui;           //gui
    void verifyUser(QString name);  //checks to see if user is valid

};

#endif // SECONDDIALOG_H
