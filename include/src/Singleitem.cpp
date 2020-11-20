#include "Singleitem.h"
#include <iostream>

SingleItem::SingleItem()
{
    name = "No Product";
    price.setMoney(0.0);
}

SingleItem::SingleItem(std::string name, double money, IDisplayBehavior* displayType)
{
    this->name = name;
    price.setMoney(money);
    this->displayType = displayType;
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

void SingleItem::getModifications()
{
    std::cout << "\t Modifications: " << std::endl;
    for (int i = 0; i < modifications.size(); i++)
    {
        std::cout << "\t" << modifications.at(i) << std::endl; 
    }
}

void SingleItem::setPrice(double money)
{
    price.setMoney(money);
}

void SingleItem::setName(std::string name)
{
    this->name = name;
}

std::string SingleItem::getName()
{
    return name;
}

MoneyClass SingleItem::getPrice()
{
    return price;
}