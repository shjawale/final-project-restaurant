
#include "order.h"

Order::Order(IDisplayBehavior* displayType)
{
    this->displayType = displayType;
}

void Order::addPlate(Item* item)
{
    plates.push_back(item);
    price.addMoney(item->getPrice().getRealMoney());
}

void Order::removePlate(Item* item)
{
    for (int i = 0; i < plates.size(); i++)
    {
        if (plates.at(i) == item)
        {
            plates.erase(plates.begin() + i);
            price.subMoney(item->getPrice().getRealMoney());
        }
    }
}

MoneyClass Order::getPrice()
{
    return price;
}