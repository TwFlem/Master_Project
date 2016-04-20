#include "shop.h"
#include "ui_shop.h"
#include "item.h"
#include "thebank.h"
#include "mainmenu.h"
#include <QPixmap>
#include <QDebug>
#include <QDir>
#include <QVector>
#include <QString>
#include <QMessageBox>
#include <QFile>

shop::shop(QWidget *parent) :   
    QDialog(parent),
    ui(new Ui::shop)
{
    ui->setupUi(this);

    //sets window title
    setWindowTitle(tr("Best Pet Shop Ever!"));
    //sets every widget in gui
    initializeFoodShop();
    //sets every widget's price tag
    setNames_Prices();

    //sets gui's images
    setImages();

}

//sets up shop
shop::shop(int token, QString names, int Pet, int petTyp) :
    //QDialog(parent),
    ui(new Ui::shop)
{
    
    ui->setupUi(this);

    //sets up pet type
    setPetType(petTyp);
    qDebug() << petType;
    this->name = names;
    this->pet = Pet;

    //loads user's pet's names
    LoadPet(names);

    //loads pet information on gui
    if(pet == 1)
    {

        setHunger(convertoInt(HHL[1]));
        setHappinessLevel(convertoInt(HHL[2]));
    }
    else if(pet == 2)
    {
        setHunger(convertoInt(HHL[5]));
        setHappinessLevel(convertoInt(HHL[6]));
    }
    else if(pet == 3)
    {
        setHunger(convertoInt(HHL[9]));
        setHappinessLevel(convertoInt(HHL[10]));
    }

    qDebug ()<< getHunger();

    //gui tokens display and gui title
    setNumTokens(token);
    setWindowTitle(tr("Best Pet Shop Ever!"));
    initializeFoodShop();
    setNames_Prices();


    setImages();
}

shop::~shop()
{
    delete ui;
}

void shop::setImages()
{
    //points each food item thumbnail to a certain location on gui
    QPixmap pix0("C:/Users/Byron/Desktop/C++/QT Stuff/build-QT_APP-Desktop_Qt_5_6_0_MSVC2015_64bit-Debug/FOOD01.png");
    QPixmap pix1("C:/Users/Byron/Desktop/C++/QT Stuff/build-QT_APP-Desktop_Qt_5_6_0_MSVC2015_64bit-Debug/FOOD1.png");
    QPixmap pix2("C:/Users/Byron/Desktop/C++/QT Stuff/build-QT_APP-Desktop_Qt_5_6_0_MSVC2015_64bit-Debug/FOOD2.png");
    QPixmap pix3("C:/Users/Byron/Desktop/C++/QT Stuff/build-QT_APP-Desktop_Qt_5_6_0_MSVC2015_64bit-Debug/FOOD3.png");
    QPixmap pix4("C:/Users/Byron/Desktop/C++/QT Stuff/build-QT_APP-Desktop_Qt_5_6_0_MSVC2015_64bit-Debug/FOOD4.png");
    QPixmap pix5("C:/Users/Byron/Desktop/C++/QT Stuff/build-QT_APP-Desktop_Qt_5_6_0_MSVC2015_64bit-Debug/FOOD5.png");
    QPixmap pix6("C:/Users/Byron/Desktop/C++/QT Stuff/build-QT_APP-Desktop_Qt_5_6_0_MSVC2015_64bit-Debug/FOOD6.png");
    QPixmap pix7("C:/Users/Byron/Desktop/C++/QT Stuff/build-QT_APP-Desktop_Qt_5_6_0_MSVC2015_64bit-Debug/FOOD7.png");
    QPixmap pix8("C:/Users/Byron/Desktop/C++/QT Stuff/build-QT_APP-Desktop_Qt_5_6_0_MSVC2015_64bit-Debug/FOOD8.png");
    QPixmap pix9("C:/Users/Byron/Desktop/C++/QT Stuff/build-QT_APP-Desktop_Qt_5_6_0_MSVC2015_64bit-Debug/FOOD9.png");
    QPixmap pix10("C:/Users/Byron/Desktop/C++/QT Stuff/build-QT_APP-Desktop_Qt_5_6_0_MSVC2015_64bit-Debug/FOOD10.png");
    QPixmap pix11("C:/Users/Byron/Desktop/C++/QT Stuff/build-QT_APP-Desktop_Qt_5_6_0_MSVC2015_64bit-Debug/FOOD11.png");
    QPixmap pix12("C:/Users/Byron/Desktop/C++/QT Stuff/build-QT_APP-Desktop_Qt_5_6_0_MSVC2015_64bit-Debug/FOOD12.png");
    QPixmap pix13("C:/Users/Byron/Desktop/C++/QT Stuff/build-QT_APP-Desktop_Qt_5_6_0_MSVC2015_64bit-Debug/FOOD13.png");
    QPixmap pix14("C:/Users/Byron/Desktop/C++/QT Stuff/build-QT_APP-Desktop_Qt_5_6_0_MSVC2015_64bit-Debug/FOOD14.png");
    QPixmap pix15("C:/Users/Byron/Desktop/C++/QT Stuff/build-QT_APP-Desktop_Qt_5_6_0_MSVC2015_64bit-Debug/FOOD15.png");
    QPixmap pix16("C:/Users/Byron/Desktop/C++/QT Stuff/build-QT_APP-Desktop_Qt_5_6_0_MSVC2015_64bit-Debug/FOOD16.png");
    QPixmap pix17("C:/Users/Byron/Desktop/C++/QT Stuff/build-QT_APP-Desktop_Qt_5_6_0_MSVC2015_64bit-Debug/FOOD17.png");
    QPixmap pix18("C:/Users/Byron/Desktop/C++/QT Stuff/build-QT_APP-Desktop_Qt_5_6_0_MSVC2015_64bit-Debug/FOOD18.png");
    QPixmap pix19("C:/Users/Byron/Desktop/C++/QT Stuff/build-QT_APP-Desktop_Qt_5_6_0_MSVC2015_64bit-Debug/FOOD19.png");
    QPixmap pix20("C:/Users/Byron/Desktop/C++/QT Stuff/build-QT_APP-Desktop_Qt_5_6_0_MSVC2015_64bit-Debug/FOOD20.png");

    //label's each food item
    ui->food0Label->setPixmap(pix0);
    ui->food1Label->setPixmap(pix1);
    ui->food2Label->setPixmap(pix2);
    ui->food3Label->setPixmap(pix3);
    ui->food4Label->setPixmap(pix4);
    ui->food5Label->setPixmap(pix5);
    ui->food6Label->setPixmap(pix6);
    ui->food7Label->setPixmap(pix7);
    ui->food8Label->setPixmap(pix8);
    ui->food9Label->setPixmap(pix9);
    ui->food10Label->setPixmap(pix10);
    ui->food11Label->setPixmap(pix11);
    ui->food12Label->setPixmap(pix12);
    ui->food13Label->setPixmap(pix13);
    ui->food14Label->setPixmap(pix14);
    ui->food15Label->setPixmap(pix15);
    ui->food16Label->setPixmap(pix16);
    ui->food17Label->setPixmap(pix17);
    ui->food18Label->setPixmap(pix18);
    ui->food19Label->setPixmap(pix19);
    ui->food20Label->setPixmap(pix20);

}

//initializes food shop
void shop::initializeFoodShop()
{
    //stores each item in a verctor with its name, cost, and benificial value for pet
    shopItems.push_back(new Item("Mush", 1, 0, "food"));
    shopItems.push_back(new Item("Kibble", 10, 1, "food"));
    shopItems.push_back(new Item("Bone", 25, 1, "food"));
    shopItems.push_back(new Item("Fish", 15, 2, "food"));
    shopItems.push_back(new Item("Dead Mouse", 30, 2, "food"));
    shopItems.push_back(new Item("Bird seed", 10, 3, "food"));
    shopItems.push_back(new Item("Mango", 25, 3, "food"));
    shopItems.push_back(new Item("Mackeral", 15, 4, "food"));
    shopItems.push_back(new Item("Cod", 20, 4,"food"));
    shopItems.push_back(new Item("Student tears", 15, 5,"food"));
    shopItems.push_back(new Item("Ketchup", 30, 5, "food"));
    shopItems.push_back(new Item("Banana", 10, 6, "food"));
    shopItems.push_back(new Item("Pineapple", 25, 6, "food"));
    shopItems.push_back(new Item("Carrot", 15, 7, "food"));
    shopItems.push_back(new Item("Rabbit Pellets", 20, 7, "food"));
    shopItems.push_back(new Item("Pizza", 30, 8, "food"));
    shopItems.push_back(new Item("Burnt Bits", 10, 8, "food"));
    shopItems.push_back(new Item("Fish Flakes", 15, 9, "food"));
    shopItems.push_back(new Item("Fish Pellets", 20, 9, "food"));
    shopItems.push_back(new Item("Gatorade", 15, 10,"food"));
    shopItems.push_back(new Item("Nole's Fans", 1, 10,"food"));
}

void shop::setNames_Prices()
{
    //sets name for each item in the shop
    ui->label1->setText(shopItems[0]->getNameOfItem());
    ui->label2->setText(shopItems[1]->getNameOfItem());
    ui->label3->setText(shopItems[2]->getNameOfItem());
    ui->label4->setText(shopItems[3]->getNameOfItem());
    ui->label5->setText(shopItems[4]->getNameOfItem());
    ui->label6->setText(shopItems[5]->getNameOfItem());
    ui->label7->setText(shopItems[6]->getNameOfItem());
    ui->label8->setText(shopItems[7]->getNameOfItem());
    ui->label9->setText(shopItems[8]->getNameOfItem());
    ui->label10->setText(shopItems[9]->getNameOfItem());
    ui->label11->setText(shopItems[10]->getNameOfItem());
    ui->label12->setText(shopItems[11]->getNameOfItem());
    ui->label13->setText(shopItems[12]->getNameOfItem());
    ui->label14->setText(shopItems[13]->getNameOfItem());
    ui->label15->setText(shopItems[14]->getNameOfItem());
    ui->label16->setText(shopItems[15]->getNameOfItem());
    ui->label17->setText(shopItems[16]->getNameOfItem());
    ui->label18->setText(shopItems[17]->getNameOfItem());
    ui->label19->setText(shopItems[18]->getNameOfItem());
    ui->label20->setText(shopItems[19]->getNameOfItem());
    ui->label21->setText(shopItems[20]->getNameOfItem());

    //sets cost for each item in the shop
    ui->label->setNum(shopItems[0]->getCostOfItem());
    ui->label_2->setNum(shopItems[1]->getCostOfItem());
    ui->label_3->setNum(shopItems[2]->getCostOfItem());
    ui->label_4->setNum(shopItems[3]->getCostOfItem());
    ui->label_5->setNum(shopItems[4]->getCostOfItem());
    ui->label_6->setNum(shopItems[5]->getCostOfItem());
    ui->label_7->setNum(shopItems[6]->getCostOfItem());
    ui->label_8->setNum(shopItems[7]->getCostOfItem());
    ui->label_9->setNum(shopItems[8]->getCostOfItem());
    ui->label_10->setNum(shopItems[9]->getCostOfItem());
    ui->label_11->setNum(shopItems[10]->getCostOfItem());
    ui->label_12->setNum(shopItems[11]->getCostOfItem());
    ui->label_13->setNum(shopItems[12]->getCostOfItem());
    ui->label_14->setNum(shopItems[13]->getCostOfItem());
    ui->label_15->setNum(shopItems[14]->getCostOfItem());
    ui->label_16->setNum(shopItems[15]->getCostOfItem());
    ui->label_17->setNum(shopItems[16]->getCostOfItem());
    ui->label_18->setNum(shopItems[17]->getCostOfItem());
    ui->label_19->setNum(shopItems[18]->getCostOfItem());
    ui->label_20->setNum(shopItems[19]->getCostOfItem());
    ui->label_21->setNum(shopItems[20]->getCostOfItem());
}

//when button is clicked...
void shop::on_pushButton0_clicked()
{
    //verifies that user bought item
    bool success;
    int cost = 0;
    int randNum = randomNumberGenerator();
    cost = shopItems[0]->getCostOfItem();
    success = enoughTokens(cost);
    
    //if sucessful, change token amount
    if(success == true)
    {

        addHungerLevel(5);
        addHappinessLevel(randNum);
        subtractNumTokens(cost);

    }
}

//returns number of tokens
int shop::getNumTokens()
{
    return tokenNumber;
}

//resets number tokens
void shop::setNumTokens(int newNumTokens)
{
    this->tokenNumber = newNumTokens;
}

//adds number of tokens
void shop::addNumTokens(int newNumTokens)
{
    this->tokenNumber += newNumTokens;
}

//determines whether or not there are enough tokens to purchase item
bool shop::enoughTokens(int numNeeded)
{
    if(tokenNumber >= numNeeded)
        {
          QMessageBox::information(this,tr("Shop"), tr("Purchase Successful!"));
         // std::cout << "You current have " << (tokenNumber-numNeeded) << " tokens left!" << std::endl;
          return true;
        }
        //if you do not you will not be able to make a purchase
        else
        {
          QMessageBox::warning(this, tr("Shop"), tr("Purchase unsuccessful not enough tokens! Study harder to earn more!"));
          //std::cout << "To make this purchase you need " << (-1)*(tokenNumber-numNeeded) << " more tokens!" << std::endl;
          return false;
        }
}

//subtract tokens after purchase
void shop::subtractNumTokens(int numNeeded)
{
    tokenNumber -= numNeeded;
}

/*
    from here until line 768, each method represents clicking a button corresponding to a food item. WLOG, each method determines
    if there were enough tokens to buy the item, add's the benifits of buying the item to the pet, and subtracts tokens from balance
*/
void shop::on_pushButton1_clicked()
{
    //purchase item
    bool success;
    int cost = 0;
    int randNum = randomNumberGenerator();

    cost = shopItems[1]->getCostOfItem();

    qDebug() << randNum;

    success = enoughTokens(cost);
    if(success == true)
    {
        addHungerLevel(5);
        if(petType == 1)
        {
            addHappinessLevel(randNum);
            infoLikedit();
        }
        else
        {
            infoDislikedit();
            subtractHappinessLevel(randNum);
        }

        subtractNumTokens(cost);

    }
}

void shop::on_pushButton2_clicked()
{
    int cost = shopItems[2]->getCostOfItem();
    bool success = enoughTokens(cost);
    int randNum = randomNumberGenerator();

    if(success == true)
    {
        addHungerLevel(5);

        if(petType == 1)
        {
            addHappinessLevel(randNum);
            infoLikedit();
        }
        else
        {
            infoDislikedit();
            subtractHappinessLevel(randNum);
        }

        subtractNumTokens(cost);
    }

}



void shop::on_pushButton3_clicked()
{
    int cost = shopItems[3]->getCostOfItem();
    bool success = enoughTokens(cost);
    int randNum = randomNumberGenerator();

    addHungerLevel(5);
    if(success == true)
    {
        if(petType == 2)
        {
            addHappinessLevel(randNum);
            infoLikedit();
        }
        else
        {
            subtractHappinessLevel(randNum);
            infoDislikedit();
        }

        subtractNumTokens(cost);
    }
}

void shop::on_pushButton4_clicked()
{
    int cost = shopItems[4]->getCostOfItem();
    bool success = enoughTokens(cost);
    int randNum = randomNumberGenerator();

    addHungerLevel(5);
    if(success == true)
    {
        if(petType == 2)
        {
            addHappinessLevel(randNum);
            infoLikedit();
        }
        else
        {
            subtractHappinessLevel(randNum);
            infoDislikedit();
        }

        subtractNumTokens(cost);
    }
}



void shop::on_pushButton5_clicked()
{
    int cost = shopItems[5]->getCostOfItem();
    bool success = enoughTokens(cost);
    int randNum = randomNumberGenerator();

    addHungerLevel(5);
    if(success == true)
    {
        if(petType == 3)
        {
            addHappinessLevel(randNum);
            infoLikedit();
        }
        else
        {
            subtractHappinessLevel(randNum);
            infoDislikedit();
        }

        subtractNumTokens(cost);
    }
}

void shop::on_pushButton6_clicked()
{
    int cost = shopItems[6]->getCostOfItem();
    bool success = enoughTokens(cost);

    int randNum = randomNumberGenerator();

    addHungerLevel(5);
    if(success == true)
    {
        if(petType == 3)
        {
            addHappinessLevel(randNum);
            infoLikedit();
        }
        else
        {
            subtractHappinessLevel(randNum);
            infoDislikedit();
        }

        subtractNumTokens(cost);
    }
}

void shop::on_pushButton7_clicked()
{
    int cost = shopItems[7]->getCostOfItem();
    bool success = enoughTokens(cost);
    int randNum = randomNumberGenerator();

    addHungerLevel(5);
    if(success == true)
    {
        if(petType == 4)
        {
            addHappinessLevel(randNum);
            infoLikedit();
        }
        else
        {
            subtractHappinessLevel(randNum);
            infoDislikedit();
        }

        subtractNumTokens(cost);
    }
}

void shop::on_pushButton8_clicked()
{
    int cost = shopItems[8]->getCostOfItem();
    bool success = enoughTokens(cost);
    int randNum = randomNumberGenerator();

    addHungerLevel(5);
    if(success == true)
    {
        if(petType == 4)
        {
            addHappinessLevel(randNum);
            infoLikedit();
        }
        else
        {
            subtractHappinessLevel(randNum);
            infoDislikedit();
        }

        subtractNumTokens(cost);
    }
}

void shop::on_pushButton9_clicked()
{
    int cost = shopItems[9]->getCostOfItem();
    bool success = enoughTokens(cost);
    int randNum = randomNumberGenerator();

    addHungerLevel(5);
    if(success == true)
    {
        if(petType == 5)
        {
            addHappinessLevel(randNum);
            infoLikedit();
        }
        else
        {
            subtractHappinessLevel(randNum);
            infoDislikedit();
        }

        subtractNumTokens(cost);
    }
}

void shop::on_pushButton10_clicked()
{
    int cost = shopItems[10]->getCostOfItem();
    bool success = enoughTokens(cost);
    int randNum = randomNumberGenerator();

    addHungerLevel(5);
    if(success == true)
    {
        if(petType == 5)
        {
            addHappinessLevel(randNum);
            infoLikedit();
        }
        else
        {
            subtractHappinessLevel(randNum);
            infoDislikedit();
        }

        subtractNumTokens(cost);
    }
}

void shop::on_pushButton11_clicked()
{
    int cost = shopItems[11]->getCostOfItem();
    bool success = enoughTokens(cost);
    int randNum = randomNumberGenerator();

    addHungerLevel(5);
    if(success == true)
    {
        if(petType == 6)
        {
            addHappinessLevel(randNum);
            infoLikedit();
        }
        else
        {
            subtractHappinessLevel(randNum);
            infoDislikedit();
        }

        subtractNumTokens(cost);
    }
}

void shop::on_pushButton12_clicked()
{
    int cost = shopItems[12]->getCostOfItem();
    bool success = enoughTokens(cost);
    int randNum = randomNumberGenerator();

    addHungerLevel(5);
    if(success == true)
    {
        if(petType == 6)
        {
            addHappinessLevel(randNum);
            infoLikedit();
        }
        else
        {
            subtractHappinessLevel(randNum);
            infoDislikedit();
        }

        subtractNumTokens(cost);
    }
}

void shop::on_pushButton13_clicked()
{
    int cost = shopItems[13]->getCostOfItem();
    bool success = enoughTokens(cost);
    int randNum = randomNumberGenerator();

    addHungerLevel(5);
    if(success == true)
    {
        if(petType == 7)
        {
            addHappinessLevel(randNum);
            infoLikedit();
        }
        else
        {
            subtractHappinessLevel(randNum);
            infoDislikedit();
        }

        subtractNumTokens(cost);
    }
}

void shop::on_pushButton14_clicked()
{
    int cost = shopItems[14]->getCostOfItem();
    bool success = enoughTokens(cost);
    int randNum = randomNumberGenerator();

    addHungerLevel(5);
    if(success == true)
    {
        if(petType == 7)
        {
            addHappinessLevel(randNum);
            infoLikedit();
        }
        else
        {
            subtractHappinessLevel(randNum);
            infoDislikedit();
        }

        subtractNumTokens(cost);
    }
}

void shop::on_pushButton15_clicked()
{
    int cost = shopItems[15]->getCostOfItem();
    bool success = enoughTokens(cost);
    int randNum = randomNumberGenerator();

    addHungerLevel(5);
    if(success == true)
    {
        if(petType == 8)
        {
            addHappinessLevel(randNum);
            infoLikedit();
        }
        else
        {
            subtractHappinessLevel(randNum);
            infoDislikedit();
        }

        subtractNumTokens(cost);
    }
}

void shop::on_pushButton16_clicked()
{
    int cost = shopItems[16]->getCostOfItem();
    bool success = enoughTokens(cost);
    int randNum = randomNumberGenerator();

    addHungerLevel(5);
    if(success == true)
    {
        if(petType == 8)
        {
            addHappinessLevel(randNum);
            infoLikedit();
        }
        else
        {
            subtractHappinessLevel(randNum);
            infoDislikedit();
        }

        subtractNumTokens(cost);
    }
}

void shop::on_pushButton17_clicked()
{
    int cost = shopItems[17]->getCostOfItem();
    bool success = enoughTokens(cost);
    int randNum = randomNumberGenerator();

    addHungerLevel(5);
    if(success == true)
    {
        if(petType == 9)
        {
            addHappinessLevel(randNum);
            infoLikedit();
        }
        else
        {
            subtractHappinessLevel(randNum);
            infoDislikedit();
        }

        subtractNumTokens(cost);
    }
}

void shop::on_pushButton18_clicked()
{
    int cost = shopItems[18]->getCostOfItem();
    bool success = enoughTokens(cost);
    int randNum = randomNumberGenerator();

    addHungerLevel(5);
    if(success == true)
    {
        if(petType == 9)
        {
            addHappinessLevel(randNum);
            infoLikedit();
        }
        else
        {
            subtractHappinessLevel(randNum);
            infoDislikedit();
        }

        subtractNumTokens(cost);
    }
}

void shop::on_pushButton19_clicked()
{
    int cost = shopItems[19]->getCostOfItem();
    bool success = enoughTokens(cost);
    int randNum = randomNumberGenerator();

    addHungerLevel(5);
    if(success == true)
    {
        if(petType == 10)
        {
            addHappinessLevel(randNum);
            infoLikedit();
        }
        else
        {
            subtractHappinessLevel(randNum);
            infoDislikedit();
        }

        subtractNumTokens(cost);
    }
}

void shop::on_pushButton20_clicked()
{
    int cost = shopItems[20]->getCostOfItem();
    bool success = enoughTokens(cost);
    int randNum = randomNumberGenerator();

    addHungerLevel(5);
    if(success == true)
    {
        if(petType == 10)
        {
            addHappinessLevel(randNum);
            infoLikedit();
        }
        else
        {
            subtractHappinessLevel(randNum);
            infoDislikedit();
        }

        subtractNumTokens(cost);
    }
}

/*End of food item button methods*/

//opens bank account
void shop::on_bankAccount_clicked()
{
    //updated bank account and file. shows bank vault
    updateVector();
    updateFile(name);
    theBank * bank = new theBank(getNumTokens(), name);
    bank->show();
    close();
}

//loads desired pet
void shop::LoadPet(QString name)
{
    //checks if pet is valid
    QFile myFile("C:\\Users\\Byron\\Desktop\\C++\\QT Stuff\\build-QT_APP-Desktop_Qt_5_6_0_MSVC2015_64bit-Debug\\" + name + "PetHHL" ".txt");
    if(!myFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::information(0, "File error", myFile.errorString());
    }

    //reads pet information
    QTextStream textStream(&myFile);
    QString line;

    while(!textStream.atEnd())
    {
        line = textStream.readLine();
        this->HHL.push_back(line);
    }

    myFile.close();

}

//generates random numbers
int shop::randomNumberGenerator()
{
   int number = 0;
   number = rand() % 20 + 1;
   return number;
}

//converts strings to integers
int shop::convertoInt(QString number)
{
    int converted = number.toInt();
    return converted;
}

//get's pet hunger
int shop::getHunger()
{
    return petHunger;
}

//returns pet's happiness
int shop::getHappiness()
{
    return petHappiness;
}

//sets pet's hunger
void shop::setHunger(int hunger)
{
    this->petHunger = hunger;
}

//sets pet's happiness
void shop::setHappinessLevel(int happiness)
{
    this->petHappiness = happiness;
}

//adds pet happiness
void shop::addHappinessLevel(int happy)
{
    petHappiness += happy;
}

//adds pet hunger
void shop::addHungerLevel(int hunger)
{
    petHunger += hunger;
}

//subtract from current happiness
void shop::subtractHappinessLevel(int happiness)
{
    petHappiness -= happiness;
}

//provides info on pet favorite foods
void shop::infoLikedit()
{
    QMessageBox::information(this, tr("Shop"), tr("it's your pets favorite food!"));
}

//provides info on pets disliked foods
void shop::infoDislikedit()
{
    QMessageBox::information(this, tr("Shop"), tr("Your pet doesn't seem to like that food... they eat it anyway"));
}

//sets pet's type
void shop::setPetType(int x)
{
    this->petType = x;
}

//returns pet type
int shop::getPetType()
{
    return petType;
}

//converts an into to string
QString shop::convertToString(int toconvert)
{
    QString converted = QString::number(toconvert);

    return converted;
}

//updates database
void shop::updateVector()
{
    if(pet == 1)
    {
        QString hunger = convertToString(getHunger());
        QString happiness = convertToString(getHappiness());
        HHL[1] = hunger;
        HHL[2] = happiness;

    }
    else if(pet == 2)
    {
        QString hunger = convertToString(getHunger());
        QString happiness = convertToString(getHappiness());
        HHL[5] = hunger;
        HHL[6] = happiness;

    }
    else if(pet == 3)
    {
        QString hunger = convertToString(getHunger());
        QString happiness = convertToString(getHappiness());
        HHL[9] = hunger;
        HHL[10] = happiness;

    }
}

//updates text file with new information
void shop::updateFile(QString name)
{
    QFile playerFile(name+"PetHHL.txt");
    qDebug() << name;

    if(playerFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {

        QTextStream text(&playerFile);

        for(int i = 0; i < HHL.size(); i++)
        {
            text << HHL[i] << "\n";
        }
        text.flush();
        playerFile.close();
    }
}


