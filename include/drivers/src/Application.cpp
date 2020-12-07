#include "../headers/Application.hpp"

Application::Application(){
    menu = new BasicNestedMenu("RESTAURANT");
    menu->addWindow(login);
    menu->addWindow(new OrderMenu("MAKE ORDER", "../files/items.txt", &orders));
    menu->addWindow(new ExtraMenu("EXTRA", "../files/items.txt", &orders));
    menu->addWindow(new CheckoutWindow("CHECKOUT", &orders, &balance));
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
            if(login->get_user()){      //user is not nullptr, hence it exists
                menu->switchWindow(window - 1);
            }
            else{
                std::cout << "Please enter a valid user.\n\n";
            }
        }
    }while(!is_done);
}

Application::~Application(){
    delete menu;
    for (int i = 0; i < orders.size(); i++){
        delete orders[i];
    }
}