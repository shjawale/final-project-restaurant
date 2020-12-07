#include "include/components/headers/Menu.hpp"
#include "include/components/headers/Utilities.hpp"
#include "include/windows/headers/LoginWindow.hpp"
#include "include/windows/headers/Checkout.hpp"

#include "include/components/headers/Item.h"
#include "include/components/headers/Singleitem.h"
#include "include/components/headers/plate.h"
#include "include/components/headers/order.h"
#include "include/components/headers/SingleItemDisplay.hpp"
#include "include/components/headers/MultiItemDisplay.hpp"
#include "include/components/headers/OrderDisplay.hpp"

int main(){
    BasicNestedMenu menu("Restaurant");
    menu.addWindow(new LoginWindow("Log In or Register", "users.txt"));

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

    menu.addWindow(new CheckoutWindow("Checkout", testOrder));


    menu.execute();
    return 0;
}