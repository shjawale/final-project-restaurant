#ifndef ITEM_H
#define ITEM_H

#include <string>

class IDisplayBehavior;

class Item
{
    protected:
        IDisplayBehavior* displayType;
        MoneyClass price;

    public:
        virtual std::string displayItem(IDisplayBehavior* idb);
        virtual MoneyClass getPrice();
};

#endif