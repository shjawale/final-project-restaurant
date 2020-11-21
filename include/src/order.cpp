
#include "order.h"

Order::Order() : Item() {}

Order::Order(std::string name, IDisplayBehavior* displayType)
{
    this->name = name;
    this->displayType = displayType;
}

void Order::addPlate(Item* item)
{
    items.push_back(item);
    price.addMoney(item->getPrice().getRealMoney());
}

void Order::removePlate(Item* item)
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