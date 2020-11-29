
#include "../headers/OrderDisplay.hpp"
#include "HelperFunctions.cpp"
#include <iostream>
#include <iomanip>

void OrderDisplay::display(Item* i)
{
    printAtCenter(i->getName(), '-', 57);
    for(int j = 0; j < i->getItemSize(); j++)
    {
        std::cout << std::setw(10);
        i->getItem(j)->getDisplay();
        std::cout << std::endl;
    }
    std::string totalName = i->getName() + " Total";
    std::string endName = "End of " + i->getName();
    std::cout << std::left << std::setw(49) << totalName << "$" << i->getTotalPrice() << std::endl;
    printAtCenter(endName, '-', 57);
}