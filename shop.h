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
    shop(int tokens, QString name, int Pet, int petType);   //shop gui
    ~shop();


private slots:
    void on_pushButton0_clicked();//WLOG, buttons 1-20 represent items in that shop that cane be purchased

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





    void on_bankAccount_clicked(); //displays bank account

private:
    Ui::shop *ui;   //shop gui
    void setImages();   //shop images for each item
    void initializeFoodShop();  //shop for each food item
    void setNames_Prices();//prices for each item
    int getNumTokens(); //number of tokens from user
    void setNumTokens(int newNumTokens);//sets number of tokens
    void addNumTokens(int newNumTokens);//adds tokens
    bool enoughTokens(int numNeeded);//determines if user has enough tokens to purchase item
    void subtractNumTokens(int numNeeded);//subtracts tokens after purchase
    int convertoInt(QString number);//convers string to intger
    void LoadPet(QString name);//loads desired pet
    void setHunger(int hunger);//sets hunger of pet
    void setHappinessLevel(int happiness);//sets happiness of pet
    void addHappinessLevel(int happy);//adds happines off pet
    void addHungerLevel(int hunger);//adds hunger to pet
    void subtractHappinessLevel(int happiness);//subtratcs happiness of pet
    void infoLikedit();//displays which pet likes which items
    void infoDislikedit();//displays which pet dilikes which items
    void updateVector();//updates database
    void setPetType(int x);//sets pet tpye
    int getPetType();//returns pet type
    int getHappiness();//returns pets happiness
    int getHunger();//returns pets hunger
    int randomNumberGenerator();//generates random number
    int tokenNumber;//number of user otkens
    int pet;//user's pet
    int petType;//user's pet type
    int petHunger;//user's pet's hunger
    int petHappiness;//user pet's happiness
    QString convertToString(int toconvert);//converts int to string
    void updateFile(QString name);//updates user text file
    QString name;//updates user's name
    QVector <QString> HHL;//user's database
    QVector<Item*> shopItems;//shop's item database
};

#endif // SHOP_H
