#include "seconddialog.h"
#include "ui_seconddialog.h"
#include <QFile>
#include <QString>
#include <QMessageBox>
#include <QDebug>
#include <QTextStream>

SecondDialog::SecondDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondDialog)
{
    ui->setupUi(this);
    setWindowTitle(tr("Login"));
   // ui->textEdit->setText("Login Successful!");
}

SecondDialog::~SecondDialog()
{
    delete ui;
}

void SecondDialog::verifyUser(QString name)
{

    QFile playerFile(name+".txt");
    qDebug() << name;

    if((!playerFile.open(QIODevice::ReadOnly | QIODevice::Text)))
    {
        QMessageBox::warning(this, tr("Player Creation Error"), tr("User with this name does not exist please try again"));
        return;
    }


    mainMenu * menu = new mainMenu(name);
    menu->show();

    close();

}

void SecondDialog::on_pushButton_clicked()
{
    QString user = ui->LineUsername->text();
    verifyUser(user);
}

void SecondDialog::on_pushButton_2_clicked()
{
    close();
}
