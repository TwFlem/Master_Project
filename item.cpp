#include "item.h"
#include <QString>

Item::Item()//empty item constructor
{

}

Item::Item(QString itemname, int itemCost, int matchPetType, QString itemType) ////Real item constructor
{
    this->nameOfItem = itemname;    //item name
    this->costOfItem = itemCost;    //item cost
    this->matchingPetType = matchPetType;   //pet matching
    this->typeOfItem = itemType;    //item type
}

Item::~Item()
{

}

int Item::getCostOfItem()//returns cost of item
{
    return costOfItem;
}

QString Item::getNameOfItem()//returns name of item
{
    return nameOfItem;
}

int Item::getMatchingType()//returns matching of item
{
    return matchingPetType;
}
