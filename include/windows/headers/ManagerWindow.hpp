#ifndef __MANAGER_WINDOW_HPP__
#define __MANAGER_WINDOW_HPP__

#include "../../components/headers/Menu.hpp"
#include "../../components/headers/order.h"

class Order;

class ManagerWindow : public BasicMenu{
private:
	std::vector<Order*>* orders;
	double _totalCost;
public:
	ManagerWindow(const std::string& title, const std::string& fileName, std::vector<Order*>* orders);
	void PrintMenu();
	void Exit();	
};
#endif
