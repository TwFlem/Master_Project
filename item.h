#ifndef ITEM_H
#define ITEM_H

#include <QString>

class Item  //class for items in shop
{
public:
    Item(); //item constructor
    Item(QString nameOfItem, int costOfItem, int matchingPetType, QString typeOfItem);  //Additional item constructor
    ~Item();    //destructor
    QString getNameOfItem();    //returns item's name
    int getCostOfItem();        //returns cost of item in tokens
    int getMatchingType();      //matches item to pet type

private:
    QString nameOfItem; //item name
    int costOfItem;     //item cost
    int matchingPetType;//item matching with pet type
    QString typeOfItem; //the type of item
};

#endif // ITEM_H
