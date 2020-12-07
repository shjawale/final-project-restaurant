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
        void setName(std::string name);
        std::string getName();
        void setPrice(double money);
        std::string getModification(int i);
        Item* getItem(int i);
        int getModSize();
        int getItemSize();
        void getDisplay();
        double getTotalPrice();
        std::string displayItem();
		void setPrice(MoneyClass price);
        // virtual void addPlate(Item* item);
        // virtual void addItem(Item* item);
        // virtual void addModifications(std::string mod);
        // virtual void removeItem(int i);
        // virtual void removeModifications(int i);
};

#endif
