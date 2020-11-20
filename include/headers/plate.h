#ifndef PLATE_H
#define PLATE_H

#include "Item.h"
#include <string>
#include "moneyclass.h"
#include <vector>

class Plate : public Item
{
    private:
        std::vector<Item*> items;

    public:
        Plate(IDisplayBehavior* displayType);
        void addItem(Item* item);
        void removeItem(Item* item);
        MoneyClass getPrice();

};

#endif