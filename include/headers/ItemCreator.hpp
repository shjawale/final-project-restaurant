#ifndef __ITEM_CREATOR_HPP__
#ifndef __ITEM_CREATOR_HPP__

#include "Item.h"
#include "Money.hpp"
#include <string>

class ItemCreator{
	public:
		virtual Item* CreateItem(string* name, money* price, std::vector<std::string> modification);
};
#endif
