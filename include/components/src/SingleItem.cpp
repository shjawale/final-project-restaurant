#include "SingleItem.hpp"

SingleItem::SingleItem() : Item() {}

SingleItem::SingleItem(std::string name, IDisplayBehavior* displayType)
{
    this->name = name;
    this->displayType = displayType;
}

void SingleItem::addItem(Item* item)
{
    items.push_back(item);
    price.addMoney(item->getPrice().getRealMoney());
}

void SingleItem::removeItem(Item* item)
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
