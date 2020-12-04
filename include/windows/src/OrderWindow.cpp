
#include "../headers/OrderWindow.hpp"
#include "../../components/headers/SingleItemDisplay.hpp"
#include "../../components/headers/MultiItemDisplay.hpp"
#include "../../components/headers/OrderDisplay.hpp"
#include "../../components/src/HelperFunctions.cpp"
#include <string>

OrderMenu::OrderMenu(const std::string& _title, std::string fileName, Order* order) : BasicMenu(_title)
{
    this->order = order;
    file = fileName;
    addOption(new BasicMenuOption("Make a Plate", [this](){AddItem();}));
    addOption(new BasicMenuOption("Remove a Plate", [this](){RemoveItem();}));
    addOption(new BasicMenuOption("Return", [this](){Exit();}));

    this->initialize();
}

void OrderMenu::initialize()
{
    bool inMap = false;
    std::ifstream inFile(file);
    if (inFile.is_open())
    {
        std::string key, name, price;
        while(inFile >> key)
        {
            inFile >> name;
            inFile >> price;
            if (choices.find(key) != choices.end())
            {
                choices.find(key)->second.push_back(c.CreateItem(name, std::stod(price)));
            }
            else
            {
                std::vector<Item*> temp = {c.CreateItem(name, std::stod(price))};
                choices.insert(std::pair<std::string, std::vector<Item*>>(key, temp));
            } 
        }
    }
    else
    {
        throw std::runtime_error("inFile Did Not Open");
    }
    
}

void OrderMenu::printItems(std::string key)
{ 
    std::cout << std::endl << "Items: " << std::endl << "Name:   " << " | ";
    for(int i = 0; i < choices.find(key)->second.size(); i++)
    {
        std::cout << choices.find(key)->second.at(i)->getName() << " | ";
    }
    std::cout << std::endl << "Price:  " << " | ";
    for(int i = 0; i < choices.find(key)->second.size(); i++)
    {
        printAtCenterCont(choices.find(key)->second.at(i)->getPrice().getTotal(), ' ', choices.find(key)->second.at(i)->getName().size());
        std::cout << " | ";
    }
    std::cout << std::endl << "Choice: " << " | ";
    for(int i = 0; i < choices.size() + 1; i++)
    {
        printAtCenterCont(std::to_string(i), ' ', choices.find(key)->second.at(i)->getName().size());
        std::cout << " | ";
    }
    std::cout << std::endl;
}

void OrderMenu::AddItem()
{
    printItems("mixed");
    Plate* test = new Plate("Plate", new MultiDisplay());
    std::cin.ignore();
    std::cout << std::endl << std::endl << "Choose an Item for your plate: ";
    int i;
    std::cin >> i;
    //std::cin.clear();
    while(i >= choices.find("mixed")->second.size())
    {
        std::cout << "You have entered an incorrect choice, choose again: ";
        std::cin >> i;
        std::cin.clear();
    }
    std::cin.clear();
    test->addItem(choices.find("mixed")->second.at(i));
    std::string c;
    bool cont = false;
     while (!cont)
    {
        std::cout << "Do you want to add another Item for the plate (y/n): ";
        std::cin >> c;
        std::cin.clear();
        if (c != "n")
        {
            std::cout << "Choose an Item for your plate: ";
            std::cin >> i;
            //std::cin.clear();
            while(i >= choices.find("mixed")->second.size())
            {
                std::cout << "You have entered an incorrect choice, choose again: ";
                std::cin >> i;
                std::cin.clear();
            }
            std::cin.clear();
            test->addItem(choices.find("mixed")->second.at(i));
        }
        else
        {
            cont = true;
        }
        
    }
    order->addPlate(test);
    order->getDisplay();
}

void OrderMenu::RemoveItem()
{
    std::cin.ignore();
    if (order->getItemSize() == 0)
    {
        std::cout << "No Plate to Remove." << std::endl;
    }
    else
    {
        std::cout << std::endl << std::endl << "Choose a plate to remove: ";
        int i;
        std::cin >> i;
        i -= 1;
        while (i > order->getItemSize())
        {
            std::cout << "You have entered an incorrect choice, choose again: ";
            std::cin >> i;
            i -= 1;
            std::cin.clear();
        }
        std::cin.clear();
        order->removePlate(i);
        order->getDisplay();
    }
    
}

void OrderMenu::Exit()
{
    current_option = nullptr;
}