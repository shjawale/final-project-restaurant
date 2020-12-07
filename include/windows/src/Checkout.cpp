#include "../headers/Checkout.hpp"

CheckoutWindow::CheckoutWindow(const std::string& _title, Order* _order): BasicMenu(_title){
    current_order = _order;

    addOption(new BasicMenuOption("Payment", [this](){pay();}));
    addOption(new BasicMenuOption("Exit", [this](){Exit();}));
}

void CheckoutWindow::display(){
    current_order->getDisplay();

	for (int i = 0; i < options.size(); i++){
		std::cout << std::setw(20) << i + 1 ;
		options[i]->display();
	}
	std::cout << "\n\n";
}


void CheckoutWindow::pay(){
    std::cout << "Handed cash: ";
    // do the payment
    std::cout << "\n\n";

    std::cout << "Change: ";
    // get the change;

    std::cout << "\n\n";
}


void CheckoutWindow::Exit(){
    current_option = nullptr;
}   
