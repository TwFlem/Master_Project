#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QMessageBox>
#include <QtCore/QVector>
#include "seconddialog.h" //Needed in general
#include "createnewplayer.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //getTextFile();
    //connect(ui->horizontalSlider, SIGNAL(valueChanged(int)),ui->progressBar,SLOT(setValue(int)));
    //connect(ui->LinePassword, SIGNAL(returnPressed()), ui->pushButton, SLOT(click()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
   close();
}

void MainWindow::getTextFile()
{

    QFile myFile(":/user.txt");
    myFile.open(QIODevice::ReadOnly);


    QTextStream textStream(&myFile);
    QString line;

    for(int i = 0; i < 2; i++)
    {
        line = textStream.readLine();
        stringVector.append(line);
    }

    myFile.close();
    setUsername(stringVector[0]);
    setPassword(stringVector[1]);

}

void MainWindow::setPassword(QString x)
{
    this->passWord = x;
}

void MainWindow::setUsername(QString x)
{
    this->userName = x;
}

QString MainWindow::getPassword()
{
    return passWord;
}

QString MainWindow::getUsername()
{
    return userName;
}

void MainWindow::on_pushButtonYes_clicked()
{
    newPlayer = new createNewPlayer(this);
    newPlayer->show();

}

void MainWindow::on_pushButton_2No_clicked()
{
    secDialog = new SecondDialog(this);
    secDialog->show();

}
