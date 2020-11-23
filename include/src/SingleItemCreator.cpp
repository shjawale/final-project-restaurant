#include "../header/Item.h"
#include "../header/moneyclass.h"
#include <string>

Item* SingleItemCreator::CreateItem(std::string* name, MoneyClass* price, std::vector<std::string> modification){
	MoneyClass money = new MoneyClass(price);
    money->setPrice(price);

	Item* item = new SingleItem();
	item->setName(name);
	//item->setPrice(price);
	//item->setModifications(modification);
	return item;
}

