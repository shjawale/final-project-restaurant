#include "../components/headers/Item.h"
#include "../components/headers/moneyclass.h"
#include "../headers/ItemCreator.hpp"
#include <string>

Item* ItemCreator::CreateItem(std::string name, MoneyClass price){
	Item* item = new Item();
	item->setName(name);
	item->setPrice(price);
	return item;
}

