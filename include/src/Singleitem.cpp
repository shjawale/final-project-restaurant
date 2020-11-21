#include "Singleitem.h"
#include <iostream>

SingleItem::SingleItem() : Item()
{
    price.setMoney(0.0);
}

SingleItem::SingleItem(std::string name, IDisplayBehavior* displayType, double money)
{
    this->name = name;
    this->displayType = displayType;
    price.setMoney(money);
}

void SingleItem::addModifications(std::string mod)
{
    modifications.push_back(mod);
}

void SingleItem::removeModifications(std::string mod)
{
    for (int i = 0; i < modifications.size(); i++)
    {
        if (modifications.at(i) == mod)
        {
            modifications.erase(modifications.begin() + i);
        }
    }
}

void SingleItem::setPrice(double money)
{
    price.setMoney(money);
}