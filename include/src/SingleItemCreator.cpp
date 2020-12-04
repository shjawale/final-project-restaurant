#include "../components/headers/Item.h"
#include "../components/headers/moneyclass.h"
#include "../components/headers/Singleitem.h"
#include "../components/headers/SingleItemDisplay.hpp"
#include "../headers/SingleItemCreator.hpp"
#include <string>
//#include <vector>


//Fix constructor
Item* SingleItemCreator::CreateItem(std::string name, double price){
	Item* item = new SingleItem(name, new SingleItemDisplay(), price);
	// item->setName(name);
	// item->setPrice(price);
	// //item->setModifications(modification);
	return item;
}

