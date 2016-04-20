#ifndef THEBANK_H
#define THEBANK_H

#include <QDialog>
#include <QMovie>

namespace Ui {
class theBank;
}

class theBank : public QDialog //bank gui
{
    Q_OBJECT

public:
    explicit theBank(QWidget *parent = 0);
    theBank(int tokens);                    //bank tokens constructor
    theBank(int tokens, QString name);      //bank token and username constructor
    ~theBank();
    int getNumTokens();                     //returns number of tokens
    void setNumTokens(int newNumTokens);    //sets number of tokens
    void addNumTokens(int newNumTokens);    //adds number of tokens
    bool enoughTokens(int numNeeded);       //determines if there are enough tokens
    void subtractNumTokens(int numNeeded);  //subtracts number of tokens after purchase

private slots:
    void on_pushButton_clicked();           //displays bank account when pushed

private:
    Ui::theBank *ui;                        //bank's ui
    QMovie * movie;                         //bank's animaion
    int tokenNumber;                        //number of tokens in bank
    QString convertToString(int x);         //convert int to string
    void setName(QString user);             //set name to username as desired
    QString getName();                      //returns username
    QString name;                           //username

};

#endif // THEBANK_H
