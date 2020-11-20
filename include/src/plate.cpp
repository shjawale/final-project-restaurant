#include "plate.h"

Plate::Plate(IDisplayBehavior* displayType)
{
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

MoneyClass Plate::getPrice()
{
    return price;
}