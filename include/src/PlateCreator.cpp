#include "../components/headers/Item.h"
#include "../components/headers/plate.h"
#include "../components/headers/moneyclass.h"
#include "../headers/PlateCreator.hpp"
#include <string>

Item* PlateCreator::CreateItem(std::string name, double price){
	Item* item = new Plate();
	item->setName(name);
	item->setPrice(price);
	return item;
}

