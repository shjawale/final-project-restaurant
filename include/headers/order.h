#ifndef ORDER_H
#define ORDER_H

#include "Item.h"
#include <string>
#include "moneyclass.h"
#include <vector>

class Order : public Item
{
    private:
        std::vector<Item*> plates;

    public:
        Order(IDisplayBehavior* displayType);
        void addPlate(Item* item);
        void removePlate(Item* item);
        MoneyClass getPrice();
};

#endif