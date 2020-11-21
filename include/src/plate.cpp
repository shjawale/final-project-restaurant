#include "plate.h"

Plate::Plate() : Item() {}

Plate::Plate(std::string name, IDisplayBehavior* displayType)
{
    this->name = name;
    this->displayType = displayType;
}

void Plate::addItem(Item* item)
{
    items.push_back(item);
    price.addMoney(item->getPrice().getRealMoney());
}

void Plate::removeItem(Item* item)
{
    for (int i = 0; i < items.size(); i++)
    {
        if (items.at(i) == item)
        {
            items.erase(items.begin() + i);
            price.subMoney(item->getPrice().getRealMoney());
        }
    }
}