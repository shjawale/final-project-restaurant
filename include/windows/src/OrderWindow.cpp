
#include "../headers/OrderWindow.hpp"
#include "../../components/headers/SingleItemDisplay.hpp"
#include "../../components/headers/MultiItemDisplay.hpp"
#include "../../components/headers/OrderDisplay.hpp"
#include "../../components/src/HelperFunctions.cpp"

OrderMenu::OrderMenu(const std::string& _title, std::string fileName) : BasicMenu(_title)
{
    order = new Order("Order", new OrderDisplay());
    addOption(new BasicMenuOption("Make a Meat Plate", [this](){MeatPlate();}));
    addOption(new BasicMenuOption("Make a Vegetable Plate", [this](){VegPlate();}));
    addOption(new BasicMenuOption("Make a Desert Plate", [this](){DesertPlate();}));
    addOption(new BasicMenuOption("Make a Mixed Plate", [this](){MixedPlate();}));
    addOption(new BasicMenuOption("Add an Item", [this](){ItemPlate();}));
    addOption(new BasicMenuOption("Add a Side", [this](){SidePlate();}));
    addOption(new BasicMenuOption("Add a Drink", [this](){DrinkPlate();}));
    addOption(new BasicMenuOption("Remove an Item", [this](){RemovePlate();}));
    addOption(new BasicMenuOption("Exit", [this](){Exit();}));

    SingleItem* testItem = new SingleItem("Cheese", new SingleItemDisplay(), 12.36);
    SingleItem* testItem2 = new SingleItem("Olive", new SingleItemDisplay(), 18.49);
    SingleItem* testItem3 = new SingleItem("Chicken", new SingleItemDisplay(), 3.58);

    choices.push_back(testItem);
    choices.push_back(testItem2);
    choices.push_back(testItem3);

    // Plate* testPlate = new Plate("Cheese dish", new MultiDisplay());
    // testPlate->addItem(testItem);
    // testPlate->addItem(testItem2);

    // order->addPlate(testPlate);
    // order->addPlate(testPlate);
}

void OrderMenu::printItems()
{
    std::cout << std::endl << "Items: " << std::endl << "Name:   " << " | ";
    for(auto e : choices)
    {
        std::cout << e->getName() << " | ";
    }
    std::cout << std::endl << "Price:  " << " | ";
    for(auto e : choices)
    {
        printAtCenterCont(e->getPrice().getTotal(), ' ', e->getName().size());
        std::cout << " | ";
    }
    std::cout << std::endl << "Choice: " << " | ";
    for(int i = 0; i < choices.size(); i++)
    {
        printAtCenterCont(std::to_string(i), ' ', choices.at(i)->getName().size());
        std::cout << " | ";
    }
}

void OrderMenu::MeatPlate()
{
    printItems();
    std::cin.ignore();
    std::cout << std::endl << std::endl << "Choose an Item for your plate: ";
    int i;
    std::cin >> i;
    order->addPlate(choices.at(i));
    char c;
    bool cont = true;
     while (cont)
    {
        std::cout << "Do you want to add another Item for the plate (y/n): ";
        std::cin >> c;
        //std::cout << "C: " << c << std::endl;
        if (c != 'n')
        {
            std::cout << "Choose an Item for your plate: ";
            std::cin >> i;
            order->addPlate(choices.at(i));
        }
        else
        {
            cont = false;
        }
        
    }
    order->getDisplay();
}

void OrderMenu::VegPlate()
{
    current_option = nullptr;
}

void OrderMenu::DesertPlate()
{
    current_option = nullptr;
}

void OrderMenu::MixedPlate()
{
    current_option = nullptr;
}

void OrderMenu::ItemPlate()
{
    printItems();
    std::cout << std::endl << std::endl << "Choose your Item: ";
    int c;
    std::cin >> c;
    //std::cout << choices.at(c)->getName();
    order->addPlate(choices.at(c));
    order->getDisplay();
}

void OrderMenu::SidePlate()
{
    current_option = nullptr;
}

void OrderMenu::DrinkPlate()
{
    current_option = nullptr;
}

void OrderMenu::RemovePlate()
{
    current_option = nullptr;
}

void OrderMenu::Exit()
{
    current_option = nullptr;
}