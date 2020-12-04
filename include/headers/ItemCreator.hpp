#ifndef __ITEM_CREATOR_HPP__
#define __ITEM_CREATOR_HPP__

#include "../components/headers/Item.h"
#include "../components/headers/moneyclass.h"
#include <string>
#include <vector>

class ItemCreator{
	public:
		virtual Item* CreateItem(std::string name, double price) = 0;
};
#endif
