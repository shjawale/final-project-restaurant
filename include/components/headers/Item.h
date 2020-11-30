#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <vector>
#include "moneyclass.h"
#include "IDisplayStrategy.hpp"

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
        MoneyClass getPrice();
        //void setDisplay(IDisplayBehavior* )
        void setName(std::string name);
        std::string getName();
        void setPrice(double money);
        std::string getModification(int i);
        Item* getItem(int i);
        int getModSize();
        int getItemSize();
        void getDisplay();
        double getTotalPrice();
};

#endif