#include "../headers/ManagerWindow.hpp"
#include "../../components/headers/SingleItemDisplay.hpp"
#include "../../components/headers/MultiItemDisplay.hpp"
#include "../../components/headers/OrderDisplay.hpp"
#include "../../components/src/HelperFunctions.cpp"
#include "../../components/headers/Item.h"
#include <string>
#include <fstream>
#include <iostream>

ManagerWindow::ManagerWindow(const std::string& title, const std::string& fileName, std::vector<Order*>* ordervector): BasicMenu(title) {
	this->orders = ordervector;
	_totalCost = 0;

	addOption(new BasicMenuOption("View Today's Total", [this](){PrintMenu();}));
    addOption(new BasicMenuOption("Return", [this](){Exit();}));
}

void ManagerWindow::PrintMenu(){ 
	orders->back->getDisplay();
	std::string lineacross = "-----------------------------";

	for (int i = 0; i < orders.size(); i++){
		std::cout << orders[i]->getName() << lineacross << orders.at[i]->getTotalPrice() << "\n\n";

		_totalCost += orders[i]->getTotalPrice();
	}
	std::cout << "\n\n" << "Today's total" << lineacross << _totalCost << std::endl;
}

void ManagerWindow::Exit(){
	currentOption = nullptr;
} 
