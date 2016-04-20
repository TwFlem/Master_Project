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

//verifies username
void SecondDialog::verifyUser(QString name)
{
    //opens file corresponding to username
    QFile playerFile(name+".txt");
    qDebug() << name;

    //checks to see if username exists
    if((!playerFile.open(QIODevice::ReadOnly | QIODevice::Text)))
    {
        QMessageBox::warning(this, tr("Player Creation Error"), tr("User with this name does not exist please try again"));
        return;
    }

    //opens main menu
    mainMenu * menu = new mainMenu(name);
    menu->show();

    close();

}

//when button is clicked
void SecondDialog::on_pushButton_clicked()
{
    //tries entered username
    QString user = ui->LineUsername->text();
    verifyUser(user);
}

//closes window when button is pushed
void SecondDialog::on_pushButton_2_clicked()
{
    close();
}
