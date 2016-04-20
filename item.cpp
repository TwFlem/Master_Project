#include "item.h"
#include <QString>

Item::Item()
{

}

Item::Item(QString itemname, int itemCost, int matchPetType, QString itemType)
{
    this->nameOfItem = itemname;
    this->costOfItem = itemCost;
    this->matchingPetType = matchPetType;
    this->typeOfItem = itemType;
}

Item::~Item()
{

}

int Item::getCostOfItem()
{
    return costOfItem;
}

QString Item::getNameOfItem()
{
    return nameOfItem;
}

int Item::getMatchingType()
{
    return matchingPetType;
}
