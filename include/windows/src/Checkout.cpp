#include "../headers/Checkout.hpp"

CheckoutWindow::CheckoutWindow(const std::string& _title, std::vector<Order*>* _orders, MoneyClass* _balance): BasicMenu(_title){
    orders = _orders;
    balance = _balance;
    addOption(new BasicMenuOption("Cash", [this](){pay();}));
    addOption(new BasicMenuOption("Return", [this](){Exit();}));
}

void CheckoutWindow::display(){
    orders->back()->getDisplay();

    std::cout << std::right;
	
	for(int i = 0; i < options.size(); i++){
		std::cout << std::setw(20) << options[i]->get_title() << std::setw(5) << "|";
	}
	std::cout << "\n";
	for(int i = 0; i < options.size(); i++){
		std::cout << std::setw(20) << i + 1 << std::setw(5) << "|";
	}
	std::cout << "\n\n";
}


void CheckoutWindow::pay(){
    std::cin.ignore();
    std::cout << "Handed cash: $ ";
    std::string cash;
    getline(std::cin, cash);

    MoneyClass payment(std::stod(cash));

    std::cout << "\n\n";

    balance->addMoney(orders->back()->getTotalPrice());

    payment.subMoney(orders->back()->getTotalPrice());


    std::cout << "Change: $" << payment.getRealMoney() << "\n\n";
    std::cout << "\n\n";

    orders->push_back(new Order(std::to_string(orders->size() + 1), new OrderDisplay()));
}


void CheckoutWindow::Exit(){
    current_option = nullptr;
}   
