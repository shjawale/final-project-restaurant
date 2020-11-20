#ifndef SINGLEITEM_H
#define SINGLEITEM_H

#include "Item.h"
#include <string>
#include "moneyclass.h"
#include <vector>

class SingleItem : public Item
{
    private:
        std::string name;
        std::vector<std::string> modifications;
    
    private:
        SingleItem();
        SingleItem(std::string name, double money, IDisplayBehavior* displayType);
        void addModifications(std::string mod);
        void removeModifications(std::string mod);
        void getModifications();
        void setPrice(double money);
        void setName(std::string name);
        std::string getName();
        MoneyClass getPrice();
};

#endif