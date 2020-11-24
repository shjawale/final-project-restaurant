#pragma once

#include "../../components/headers/Menu.hpp"
#include "../../components/headers/Utilities.hpp"
#include <fstream>
#include <map>


class LoginWindow: public BasicMenu{
private:
    std::map<std::string, User*> users;
    std::string users_file;
    User* current_user;
    void readUsers();
    void writeUsers();
public:
    LoginWindow(const std::string& _title, const std::string& _filename);

    void login();

    void add_user();

    void Exit();

    // Not displayed on menu
    User* get_current_user();
};


