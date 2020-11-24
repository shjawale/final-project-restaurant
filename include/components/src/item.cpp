
#include "../headers/Item.h"
#include <string>
#include "../headers/moneyclass.h"

Item::Item()
{
    displayType = nullptr;
    name = "";
}

Item::Item(std::string name, IDisplayBehavior* displayType)
{
    this->name = name;
    this->displayType = displayType;
}

MoneyClass Item::getPrice()
{
    return price;
}

void Item::setName(std::string name)
{
    this->name = name;
}

std::string Item::getName()
{
    return name;
}

void Item::setPrice(double money)
{
    price.setMoney(money);
}