#ifndef SECONDDIALOG_H
#define SECONDDIALOG_H

#include "mainmenu.h"
#include <QDialog>

namespace Ui {
class SecondDialog; //the second dialog window
}

class SecondDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SecondDialog(QWidget *parent = 0);
    ~SecondDialog();

private slots:
    void on_pushButton_clicked(); //button corresponding to verify user

private:
    Ui::SecondDialog *ui;
    void verifyUser(QString name);  //veryfies user

};

#endif // SECONDDIALOG_H
