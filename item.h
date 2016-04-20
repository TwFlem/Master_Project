#ifndef ITEM_H
#define ITEM_H

#include <QString>

class Item
{
public:
    Item();
    Item(QString nameOfItem, int costOfItem, int matchingPetType, QString typeOfItem);
    ~Item();
    QString getNameOfItem();
    int getCostOfItem();
    int getMatchingType();

private:
    QString nameOfItem;
    int costOfItem;
    int matchingPetType;
    QString typeOfItem;
};

#endif // ITEM_H
