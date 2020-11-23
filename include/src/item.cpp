
#include "Item.h"
#include <string>
#include "moneyclass.h"

Item::Item()
{
    displayType = nullptr;
    name = "";
}

Item::Item(std::string name, IDisplayBehavior* displayType)
{
    this->name = name;
    this->displayType = displayType;
}

void Item::setPrice(MoneyClass price)
{
	this->price = price;
}

MoneyClass Item::getPrice()
{
    return price;
}

void Item::setModifications(std::vector<std::string> modifications)
{
	this->modifications = modifications;
}

std::vector<std::string> Item::getModifications()
{
	return modifications;
}

void Item::setName(std::string name)
{
    this->name = name;
}

std::string Item::getName()
{
    return name;
}
