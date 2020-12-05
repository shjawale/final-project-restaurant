#ifndef EXTRAORDERWINDOW_HPP
#define EXTRAORDERWINDOW_HPP

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

class ExtraMenu : public BasicMenu
{
    private:
        std::map<std::string, std::vector<Item*>> choices;
        Order* order;
        std::string file;
        SingleItemCreator c;
        void printItems(std::string key);
        void initialize();

    public:
        ExtraMenu(const std::string& _title, const std::string& fileName, Order* order);

        void AddDrink();
        
        void AddSide();

        void AddDesert();

        void AddSauce();

        void Exit();
};

#endif