#include "help.h"
#include "ui_help.h"

help::help(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::help)
{
    ui->setupUi(this);

    QFile file("C:\\Users\\Byron\\Desktop\\C++\\QT Stuff\\build-QT_APP-Desktop_Qt_5_6_0_MSVC2015_64bit-Debug\\instructions.txt");
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);
        ui->textBrowser->setText(in.readAll());
    }
}

help::~help()
{
    delete ui;
}

void help::on_pushButton_clicked()
{
    close();
}
