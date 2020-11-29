#pragma once

#include "../../components/headers/Menu.hpp"

class Order;

class CheckoutWindow: public BasicMenu{
private:
    Order* current_order;
public:
    CheckoutWindow(const std::string& _title, Order* _order);

    void display();
};
