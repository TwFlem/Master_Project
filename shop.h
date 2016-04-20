#ifndef SHOP_H
#define SHOP_H

#include "item.h"
#include "thebank.h"
#include <QDialog>
#include <QString>
#include <QVector>

namespace Ui {
class shop;
}

class shop : public QDialog
{
    Q_OBJECT

public:
    explicit shop(QWidget *parent = 0);
    shop(int tokens, QString name, int Pet, int petType);
    QString convertToString(int toconvert);
    int convertoInt(QString number);
    ~shop();


private slots:
    void on_pushButton0_clicked();

    void on_pushButton1_clicked();

    void on_pushButton2_clicked();

    void on_pushButton3_clicked();

    void on_pushButton4_clicked();

    void on_pushButton5_clicked();

    void on_pushButton6_clicked();

    void on_pushButton7_clicked();

    void on_pushButton8_clicked();

    void on_pushButton9_clicked();

    void on_pushButton10_clicked();

    void on_pushButton11_clicked();

    void on_pushButton12_clicked();

    void on_pushButton13_clicked();

    void on_pushButton14_clicked();

    void on_pushButton15_clicked();

    void on_pushButton16_clicked();

    void on_pushButton17_clicked();

    void on_pushButton18_clicked();

    void on_pushButton19_clicked();

    void on_pushButton20_clicked();





    void on_bankAccount_clicked();

private:
    Ui::shop *ui;
    void setImages();
    void initializeFoodShop();
    void setNames_Prices();
    int getNumTokens();
    void setNumTokens(int newNumTokens);
    void addNumTokens(int newNumTokens);
    bool enoughTokens(int numNeeded);
    void subtractNumTokens(int numNeeded);

    void LoadPet(QString name);
    void setHunger(int hunger);
    void setHappinessLevel(int happiness);
    void addHappinessLevel(int happy);
    void addHungerLevel(int hunger);
    void subtractHappinessLevel(int happiness);
    void infoLikedit();
    void infoDislikedit();
    void updateVector();
    void setPetType(int x);
    int getPetType();
    int getHappiness();
    int getHunger();
    int randomNumberGenerator();
    int tokenNumber;
    int pet;
    int petType;
    int petHunger;
    int petHappiness;

    void updateFile(QString name);
    QString name;
    QVector <QString> HHL;
    QVector<Item*> shopItems;
};

#endif // SHOP_H
