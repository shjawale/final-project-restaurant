#ifndef ORDERWINDOW_HPP
#define ORDERWINDOW_HPP

#include "../../components/headers/Menu.hpp"
#include "../../components/headers/Utilities.hpp"
#include "../../components/headers/Item.h"
#include "../../components/headers/order.h"
#include "../../components/headers/plate.h"
#include "../../components/headers/Singleitem.h"
#include <fstream>
#include <map>
#include <vector>

class OrderMenu : public BasicMenu
{
    private:
        std::vector<Item*> choices;
        Order* order;
        void printItems();
    public:
        OrderMenu(const std::string& _title, std::string fileName);

        void MeatPlate();

        void VegPlate();

        void DesertPlate();

        void MixedPlate();

        void ItemPlate();

        void SidePlate();

        void DrinkPlate();

        void RemovePlate();

        void Exit();

};

#endif
