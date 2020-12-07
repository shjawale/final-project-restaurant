#include "../headers/ManagerWindow.hpp"
#include "../../components/headers/SingleItemDisplay.hpp"
#include "../../components/headers/MultiItemDisplay.hpp"
#include "../../components/headers/OrderDisplay.hpp"
#include "../../components/src/HelperFunctions.cpp"
#include "../../components/headers/Item.h"
#include <string>
#include <fstream>
#include <iostream>

ManagerWindow::ManagerWindow(const std::string& title, const std::string& fileName, Order* order) : BasicMenu(title) {
	_currentOrder = order;
	_totalCost = 0;

	addOption(new BasicMenuOption("View Today's Total", [this](){PrintMenu();}));
    addOption(new BasicMenuOption("Return", [this](){Exit();}));
}

void ManagerWindow::PrintMenu(){ 
	_currentOrder->getDisplay();
	std::vector<Order*> today = getTodaysOrders();
	std::string lineacross = "-----------------------------";

	for (int i = 0; i < today.size(); i++){
		std::cout << today.at(i)->getName() << lineacross << today.at(i)->getTotalPrice() << "\n\n";

		_totalCost += today.at(i)->getTotalPrice();
	}
	std::cout << "Today's total" << lineacross << _totalCost << std::endl;
}

void ManagerWindow::Exit(){
	currentOption = nullptr;
} 
