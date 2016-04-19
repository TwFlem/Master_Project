#ifndef THEBANK_H
#define THEBANK_H

#include <QDialog>
#include <QMovie>

namespace Ui {
class theBank;
}

class theBank : public QDialog
{
    Q_OBJECT

public:
    explicit theBank(QWidget *parent = 0);
    theBank(int tokens);
    theBank(int tokens, QString name);
    ~theBank();
    int getNumTokens();
    void setNumTokens(int newNumTokens);
    void addNumTokens(int newNumTokens);
    bool enoughTokens(int numNeeded);
    void subtractNumTokens(int numNeeded);

private slots:
    void on_pushButton_clicked();

private:
    Ui::theBank *ui;
    QMovie * movie;
    int tokenNumber;
    QString convertToString(int x);
    void setName(QString user);
    QString getName();
    QString name;

};

#endif // THEBANK_H
