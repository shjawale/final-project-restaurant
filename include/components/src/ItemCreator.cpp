#include "../headers/ItemCreator.hpp"
#include "../headers/Item.h"
#include "../headers/plate.h"
#include "../headers/SingleItem.hpp"
#include "../headers/moneyclass.h"
#include <string>

Item* ItemCreator::CreateItem(ItemType TypeId, std::string name, MoneyClass price){
	if(TypeId == PLATE_ITEM_T){
		Plate* item = new Plate(name, multiDisplayTest, price);
		return item;
	}

	if(TypeId == SINGLE_ITEM_T){
		SingleItem* item = new SingleItem(name, SingleItemDisplay, price);
        return item;
    }
}

