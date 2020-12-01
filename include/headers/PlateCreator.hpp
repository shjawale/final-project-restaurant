#ifndef __PLATE_CREATOR_HPP__
#define __PLATE_CREATOR_HPP__

#include "../components/headers/Item.h"
#include "../components/headers/moneyclass.h"
#include "ItemCreator.hpp"
#include <string>

class PlateCreator : public ItemCreator{
	public:
		virtual Item* CreateItem(std::string name, MoneyClass price);
};
#endif
