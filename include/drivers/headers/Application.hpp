#pragma once

#include "../../components/headers/Menu.hpp"
#include "../../components/headers/Utilities.hpp"
#include "../../windows/headers/LoginWindow.hpp"
#include "../../windows/headers/Checkout.hpp"
#include "../../components/headers/Item.h"
#include "../../components/headers/Singleitem.h"
#include "../../components/headers/plate.h"
#include "../../components/headers/order.h"
#include "../../components/headers/SingleItemDisplay.hpp"
#include "../../components/headers/MultiItemDisplay.hpp"
#include "../../components/headers/OrderDisplay.hpp"


class Application{
private:
    LoginWindow* login = new LoginWindow("LOGIN OR REGISTER", "users.txt");

    BasicNestedMenu* menu = nullptr;
    std::vector<Order*> orders;
    User* current_user;
    MoneyClass balance;
public:
    Application();

    void run();

    ~Application();
};