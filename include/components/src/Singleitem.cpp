#include "../headers/Singleitem.h"

SingleItem::SingleItem() : Item() {}

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

void SingleItem::removeModifications(int i)
{
            modifications.erase(modifications.begin() + i);
}