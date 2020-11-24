#pragma once

#include "../../components/headers/Menu.hpp"
#include "../../components/headers/FileIOB.hpp"
#include "../../components/headers/Utilities.hpp"
#include <map>


class LoginWindow: public BasicMenu{
private:
    std::map<std::string, User*> users;
    User* current_user;
    FileIOB users_file;
    void fillUsers();
public:
    LoginWindow(const std::string& _title, const std::string& _filename);

    void login();

    void add_user();

    void Exit();

    // Not displayed on menu
    User* get_current_user();
};


