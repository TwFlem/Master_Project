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

//gathers text file
void MainWindow::getTextFile()
{
    //file path
    QFile myFile(":/user.txt");
    //opens text file
    myFile.open(QIODevice::ReadOnly);

    //file stream
    QTextStream textStream(&myFile);
    QString line;

    //reads each line
    for(int i = 0; i < 2; i++)
    {
        line = textStream.readLine();
        stringVector.append(line);
    }
    //closes file
    myFile.close();
    setUsername(stringVector[0]);
    setPassword(stringVector[1]);

}

//user password
void MainWindow::setPassword(QString x)
{
    this->passWord = x;
}

//sets username
void MainWindow::setUsername(QString x)
{
    this->userName = x;
}

//gets user's password
QString MainWindow::getPassword()
{
    return passWord;
}

//returns user's username
QString MainWindow::getUsername()
{
    return userName;
}

//when yes is pushed, creates new player
void MainWindow::on_pushButtonYes_clicked()
{
    newPlayer = new createNewPlayer(this);
    newPlayer->show();

}

//when no is clicked, continues to login
void MainWindow::on_pushButton_2No_clicked()
{
    secDialog = new SecondDialog(this);
    secDialog->show();

}
