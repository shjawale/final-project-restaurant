#include "include/components/headers/Menu.hpp"
#include "include/components/headers/Utilities.hpp"
#include "include/windows/headers/LoginWindow.hpp"

int main(){
    BasicNestedMenu menu("Restaurant");
    menu.addWindow(new LoginWindow("Log In or Register", "users.bin"));

    menu.execute();
    return 0;
}