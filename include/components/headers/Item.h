#ifndef ITEM_H
#define ITEM_H

#include "moneyclass.h"
#include <string>
#include <vector>

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
		void setPrice(MoneyClass price);
        MoneyClass getPrice();
		void setModifications(std::vector<std::string> modifications);
		std::vector<std::string> getModifications();
        void setName(std::string name);
        std::string getName();
};

#endif
