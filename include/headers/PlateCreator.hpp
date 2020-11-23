#ifndef __PLATE_CREATOR_HPP__
#ifndef __PLATE_CREATOR_HPP__

#include "Item.h"
#include "Money.hpp"
#include <string>

class PlateCreator : public ItemCreator{
	public:
		virtual Item* CreateItem(string* name, money* price, std::vector<std::string> modification);
};
#endif
