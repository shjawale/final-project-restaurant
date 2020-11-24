#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <vector>
#include "moneyclass.h"

class IDisplayBehavior;

class Item
{
    protected:
        IDisplayBehavior* displayType;
        MoneyClass price;
        std::vector<Item*> items;
        std::vector<std::string> modifications;
        std::string name;

    public:
        Item();
        Item(std::string name, IDisplayBehavior* displayType);
        std::string displayItem();
        MoneyClass getPrice();
        void setName(std::string name);
        std::string getName();
        void setPrice(double money);
};

#endif