#include "../header/Item.h"
#include "../header/moneyclass.h"
#include <string>

Item* PlateCreator::CreateItem(std::string name, MoneyClass price, std::vector&<std::string> modification){
	Item* item = new Plate();
	item->setName(name);
	item->setPrice(price);
	item->setModifications(modification);
	return item;
}

