#include "timegrab.h"
#include "ui_timegrab.h"
#include <QMessageBox>
#include <QString>
#include <QTimer>
#include <QtCore>
#include <QtGui>
#include <QDialog>

TimeGrab::TimeGrab(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TimeGrab)
{
    tokens = 0;
    happiness = 70;
    hunger = 70;
    seconds = 0;
    current_level_experience = 0;
    total_experience = 0;

    ui->setupUi(this);

    timer = new QTimer(this);

    setWindowTitle(tr("Study Time!"));
    resize(560,375);

    ui->Continue->setEnabled(false);
    ui->Pause->setEnabled(false);
    ui->End->setEnabled(false);

    ui->ExperienceBar->setRange(0,100);
    ui->ExperienceBar->setValue(0);

    ui->spinBox->setRange(0,23);
    ui->spinBox_2->setRange(0,60);

    current_level = 1;
    ui->Level->setText(QString::number(current_level));
    ui->Tokens->setText(QString::number(tokens));
    ui->Happiness->setValue(happiness);
    ui->Hunger->setValue(hunger);
}

TimeGrab::~TimeGrab()
{
    delete ui;
}

void TimeGrab::showtime()
{

    int tens_hours = hours/10;
    int ones_hours = hours%10;
    int tens_minutes = minutes/10;
    int ones_minutes = minutes%10;
    int tens_seconds = seconds/10;
    int ones_seconds = seconds%10;

    QString H_time_1 = QString::number(tens_hours);
    QString H_time_2 = QString::number(ones_hours);
    QString M_time_1 = QString::number(tens_minutes);
    QString M_time_2 = QString::number(ones_minutes);
    QString S_time_1 = QString::number(tens_seconds);
    QString S_time_2 = QString::number(ones_seconds);

    QString Time_text = H_time_1 + H_time_2 + " : " + M_time_1 + M_time_2 +
            " : " + S_time_1 + S_time_2;

    ui->Clock->setText(Time_text);

    seconds--;

    current_level_experience++;
    total_experience++;
    if(current_level_experience == ui->ExperienceBar->maximum())
        level_up();

    ui->ExperienceBar->setValue(current_level_experience);

    tokens++;
    ui->Tokens->setText(QString::number(tokens));

    if(hunger>=0){
        hunger -= 0.01;
        ui->Hunger->setValue(hunger);
    }

    if(happiness>=0){
        happiness -=0.01;
        ui->Happiness->setValue(happiness);
    }
    if(seconds < 0){
        if(hours == 0 && minutes == 0){
        timer->stop();
        timer->disconnect(timer, SIGNAL(timeout()), this, SLOT(showtime()));
        ui->Clock->setText("Complete!");
        ui->Start->setEnabled(true);
        ui->Pause->setEnabled(false);
        ui->End->setEnabled(false);
        ui->spinBox->setEnabled(true);
        ui->spinBox_2->setEnabled(true);
        ui->MainMenu->setEnabled(true);
        return;
        }
        seconds = 59;
        minutes--;
    }

    if(minutes < 0){
        if(hours !=0){
            minutes = 59;
            hours--;
        }
    }
    if(minutes <0 && seconds < 0){
        hours--;
        minutes = 59;
    }
    if(hours < 0){
        hours = 0;
        }
}

void TimeGrab::on_Start_clicked()
{
    {
        hours = ui->spinBox->value();
        minutes = ui->spinBox_2->value();
        seconds = 0;

        if(minutes==0 && hours==0){
            ui->Clock->setText("Set a Time!");
            return;
        }
        ui->spinBox->setEnabled(false);
        ui->spinBox_2->setEnabled(false);

        disconnect(timer, SIGNAL(timeout()), this, SLOT(showtime()));

        ui->Start->setEnabled(false);
        ui->Pause->setEnabled(true);
        ui->End->setEnabled(true);
        ui->MainMenu->setEnabled(false);
        current_level_experience--;
        total_experience--;
        connect(timer, SIGNAL(timeout()), this, SLOT(showtime()));
        timer->start(1000);
    }
}

void TimeGrab::on_Pause_clicked()
{
    timer->stop();
    disconnect(timer, SIGNAL(timeout()), this, SLOT(showtime()));
    ui->Continue->setEnabled(true);
    ui->Pause->setEnabled(false);
}

void TimeGrab::on_Continue_clicked()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(showtime()));
    timer->start(1000);
    ui->Pause->setEnabled(true);
    ui->Continue->setEnabled(false);
}

void TimeGrab::on_End_clicked()
{
  timer->stop();
  ui->Start->setEnabled(true);
  ui->Continue->setEnabled(false);
  ui->Pause->setEnabled(false);
  ui->End->setEnabled(false);
  ui->spinBox->setEnabled(true);
  ui->spinBox_2->setEnabled(true);
  ui->spinBox->setValue(0);
  ui->spinBox_2->setValue(0);
  ui->spinBox->setEnabled(true);
  ui->spinBox_2->setEnabled(true);
  ui->MainMenu->setEnabled(true);

  seconds = 0;
  minutes = 0;
  hours = 0;

  ui->Clock->setText("00 : 00 : 00");

}

void TimeGrab::level_up(){

    ui->ExperienceBar->setValue(0);
    ui->ExperienceBar->setMaximum(current_level_experience*10);
    current_level_experience = 0;
    current_level++;
    ui->Level->setText(QString::number(current_level));

    QMessageBox::information(this,tr("LEVEL UP!!!!!!!!!!"),tr("Wow, you leveled up! What a super studier! Keep it up!"));

}
