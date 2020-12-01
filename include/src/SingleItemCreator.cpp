#include "../components/headers/Item.h"
#include "../components/headers/moneyclass.h"
#include "../components/headers/Singleitem.h"
#include "../headers/SingleItemCreator.hpp"
#include <string>
//#include <vector>


//Fix constructor
Item* SingleItemCreator::CreateItem(std::string name, MoneyClass price){
	Item* item = new SingleItem();
	item->setName(name);
	item->setPrice(price);
	//item->setModifications(modification);
	return item;
}

