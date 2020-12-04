#ifndef ORDERWINDOW_HPP
#define ORDERWINDOW_HPP

#include "../../components/headers/Menu.hpp"
#include "../../components/headers/Utilities.hpp"
#include "../../components/headers/Item.h"
#include "../../components/headers/order.h"
#include "../../components/headers/plate.h"
#include "../../components/headers/Singleitem.h"
#include "../../headers/SingleItemCreator.hpp"
#include <fstream>
#include <map>
#include <vector>
#include <map>

class OrderMenu : public BasicMenu
{
    private:
        std::map<std::string, std::vector<Item*>> choices;
        Order* order;
        std::string file;
        SingleItemCreator c;
        void printItems(std::string key);
        void initialize();
    public:
        OrderMenu(const std::string& _title, std::string fileName, Order* order);

        void AddItem();

        void RemoveItem();

        void Exit();

};

#endif
