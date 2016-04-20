#include "timegrab.h"
#include "ui_timegrab.h"
#include <QMessageBox>
#include <QString>
#include <QTimer>
#include <QtCore>
#include <QtGui>
#include <QDialog>

TimeGrab::TimeGrab(QWidget *parent) : //Set's up ui for the timer's window
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

    timer = new QTimer(this);       //Timer to control time flow

    setWindowTitle(tr("Study Time!"));//initial window size and title
    resize(560,375);

    ui->Continue->setEnabled(false);    //disables the continue button
    ui->Pause->setEnabled(false);       //disables the pause button
    ui->End->setEnabled(false);         //disables the end button

    ui->ExperienceBar->setRange(0,100); //sets range of eperience bar
    ui->ExperienceBar->setValue(0);     //sets current value to 0

    ui->spinBox->setRange(0,23);        //sets range of both the minute and hour boxes. 23 hours and 60 minutes
    ui->spinBox_2->setRange(0,60);

    current_level = 1;                  //pet level

    ui->Level->setText(QString::number(current_level)); //updates level on gui
    ui->Tokens->setText(QString::number(tokens));       //updates toekns on gui
    ui->Happiness->setValue(happiness);                 //updates happiness on gui
    ui->Hunger->setValue(hunger);                       //updates hunger on gui
}

TimeGrab::~TimeGrab()
{
    delete ui;
}

void TimeGrab::showtime() //updates gui every second
{

    int tens_hours = hours/10;      //tens place of hours
    int ones_hours = hours%10;      //ones place of hours
    int tens_minutes = minutes/10;  //WLOG to minutes and seconds
    int ones_minutes = minutes%10;
    int tens_seconds = seconds/10;
    int ones_seconds = seconds%10;

     //Displays time in text form
    QString H_time_1 = QString::number(tens_hours);
    QString H_time_2 = QString::number(ones_hours);
    QString M_time_1 = QString::number(tens_minutes);
    QString M_time_2 = QString::number(ones_minutes);
    QString S_time_1 = QString::number(tens_seconds);
    QString S_time_2 = QString::number(ones_seconds);
    QString Time_text = H_time_1 + H_time_2 + " : " + M_time_1 + M_time_2 +
            " : " + S_time_1 + S_time_2;

    ui->Clock->setText(Time_text); //set's the text in gui

    seconds--; //counts down the seconds

    //increments experience by one fore every second. if bar is filled, levels up
    current_level_experience++;
    total_experience++;
    if(current_level_experience == ui->ExperienceBar->maximum())
        level_up();

    ui->ExperienceBar->setValue(current_level_experience);  //updates progress bar for experience in gui

    //increments tokens for every second and displays to user
    tokens++;
    ui->Tokens->setText(QString::number(tokens));

    //decrements hunger by 0.01 for every second and updates on gui
    if(hunger>=0){
        hunger -= 0.01;
        ui->Hunger->setValue(hunger);
    }

    //decrements happiness by 0.01 for every second and updates to gui
    if(happiness>=0){
        happiness -=0.01;
        ui->Happiness->setValue(happiness);
    }
    //when seconds couts down to 0...
    if(seconds < 0){
        //and when minutes and hours are also 0...
        if(hours == 0 && minutes == 0){
        //complete
        timer->stop();  //stop menu animations
        timer->disconnect(timer, SIGNAL(timeout()), this, SLOT(showtime()));    //disconnect timer from gui
        ui->Clock->setText("Complete!");    //display complete
        ui->Start->setEnabled(true);        //enable the start button again
        ui->Pause->setEnabled(false);       //disable all other push buttons while enabling everything else
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

void TimeGrab::on_Start_clicked()   //when Start is clicked on gui...
{
    {
        //read values from spin boxes
        hours = ui->spinBox->value();
        minutes = ui->spinBox_2->value();
        seconds = 0;

        //if nothing was set
        if(minutes==0 && hours==0){
            ui->Clock->setText("Set a Time!");
            return;
        }
        //disable spinboxes if sucessfully set
        ui->spinBox->setEnabled(false);
        ui->spinBox_2->setEnabled(false);

        //disconnect any previous timers
        disconnect(timer, SIGNAL(timeout()), this, SLOT(showtime()));

        //disable start while enabling pause and end
        ui->Start->setEnabled(false);
        ui->Pause->setEnabled(true);
        ui->End->setEnabled(true);
        ui->MainMenu->setEnabled(false);

        //make up for the second it takes to set timer to desired value
        current_level_experience--;
        total_experience--;
        //connect and start timer to call on the function, showtime() for every 1000ms
        connect(timer, SIGNAL(timeout()), this, SLOT(showtime()));
        timer->start(1000);
    }
}

//when pause is clicked
void TimeGrab::on_Pause_clicked()
{
    //pause timer
    timer->stop();
    //disconnect timer
    disconnect(timer, SIGNAL(timeout()), this, SLOT(showtime()));
    //set continue to enabled
    ui->Continue->setEnabled(true);
    //set pause to disabled
    ui->Pause->setEnabled(false);
}

//when continue is clicked
void TimeGrab::on_Continue_clicked()
{
    //reconnect itmer and restert timer
    connect(timer, SIGNAL(timeout()), this, SLOT(showtime()));
    timer->start(1000);
    //enable pause button and disable continue button
    ui->Pause->setEnabled(true);
    ui->Continue->setEnabled(false);
}

void TimeGrab::on_End_clicked()
{
  //stop timer
  timer->stop();

  //enable start and diable everything but main menu
  ui->Start->setEnabled(true);
  ui->Continue->setEnabled(false);
  ui->Pause->setEnabled(false);
  ui->End->setEnabled(false);

  //reEnable spin boxes
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

//on level up...
void TimeGrab::level_up(){

    //reset experience bar
    ui->ExperienceBar->setValue(0);
    ui->ExperienceBar->setMaximum(current_level_experience*10);
    current_level_experience = 0;
    current_level++;
    ui->Level->setText(QString::number(current_level));

    //pop up a message box
    QMessageBox::information(this,tr("LEVEL UP!!!!!!!!!!"),tr("Wow, you leveled up! What a super studier! Keep it up!"));

}
