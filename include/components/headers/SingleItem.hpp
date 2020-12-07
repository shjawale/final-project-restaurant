#ifndef __SINGLE_ITEM_H__
#define __SINGLE_ITEM_H__

#include "Item.h"
#include <string>
#include "moneyclass.h"
#include <vector>

class SingleItem : public Item
{
    public:
		SingleItem();
        SingleItem(std::string name, IDisplayBehavior* displayType);
        void addItem(Item* item);
        void removeItem(Item* item);
};

#endif
