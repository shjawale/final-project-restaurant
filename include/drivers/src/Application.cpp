#include "../headers/Application.hpp"

Application::Application(){
    menu = new BasicNestedMenu("RESTAURANT");
    menu->addWindow(login);
    menu->addWindow(new CheckoutWindow("CHECKOUT", &orders, &balance));

    //========= Making and order manually ========================
    SingleItemDisplay* displayTest = new SingleItemDisplay();
    SingleItem* testItem = new SingleItem("Cheese", displayTest, 12.36);
    testItem->addModifications("Extra Cheese");
    SingleItem* testItem2 = new SingleItem("Olive", displayTest, 18.49);

    //testItem->getDisplay();

    std::cout << std::endl << std::endl;

    MultiDisplay* multiDisplayTest = new MultiDisplay();
    Plate* testPlate = new Plate("Cheese dish", multiDisplayTest);
    testPlate->addItem(testItem);
    testPlate->addItem(testItem2);

    //testPlate->getDisplay();

    OrderDisplay* orderDisplayTest = new OrderDisplay();
    Order* testOrder = new Order("Order", orderDisplayTest);
    testOrder->addPlate(testPlate);
    testOrder->addPlate(testPlate);
    testOrder->addPlate(testItem);
    testOrder->addPlate(testPlate);
//============ End of order ===============================================

    orders.push_back(testOrder);
}

void Application::run(){
    menu->switchWindow(0);
    bool is_done = false;
    do{
        do{
            menu->display();
            menu->get_current()->display();
            std::cout << "Enter option: ";
            int option;
            std::cin >> option;
            menu->get_current()->switch_options(option - 1);
            menu->execute();
        }while(menu->get_current()->get_current());
        menu->display();
        std::cout << "Press \"Q\" to quit\nSelect Window: ";
        int window;
        std::cin >> window;
        if(std::cin.fail()){is_done = true;}
        else{
            menu->switchWindow(window - 1);
        }
    }while(!is_done);
}

Application::~Application(){
    delete menu;
    for (int i = 0; i < orders.size(); i++){
        delete orders[i];
    }
}