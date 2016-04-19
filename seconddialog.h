#ifndef SECONDDIALOG_H
#define SECONDDIALOG_H

#include "mainmenu.h"
#include <QDialog>

namespace Ui {
class SecondDialog;
}

class SecondDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SecondDialog(QWidget *parent = 0);
    ~SecondDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SecondDialog *ui;
    void verifyUser(QString name);

};

#endif // SECONDDIALOG_H
