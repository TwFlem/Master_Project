#ifndef HELP_H
#define HELP_H

#include <QFile>
#include <QTextStream>
#include <QDialog>

namespace Ui {
class help;
}

class help : public QDialog
{
    Q_OBJECT

public:
    explicit help(QWidget *parent = 0);
    ~help();

private slots:
    void on_pushButton_clicked(); //method when help button is clicked

private:
    Ui::help *ui;               //help gui
};

#endif // HELP_H
