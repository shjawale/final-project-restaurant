#include "../headers/LoginWindow.hpp"

LoginWindow::LoginWindow(const std::string& _title,const std::string& _filename): BasicMenu(_title){
    current_user = nullptr;
    users_file.set_file(_filename);

    //filling up the users vector.
    fillUsers();


    //Add functions to Options vector
    addOption(new BasicMenuOption(
        "Login",
        [this](){ login(); }
    ));

    addOption(new BasicMenuOption(
        "Register",
        [this](){ add_user(); }
    )),

    addOption(new BasicMenuOption(
        "Exit",
        [this](){ Exit(); }
    ));
}


void LoginWindow::fillUsers(){
    int number_of_users = users_file.tell_size() / sizeof(User);
    User* temp = new User();
    users.clear();
    for (int i = 0; i < number_of_users; i++){
        users_file.setg(0);
        users_file.read((char*) temp, sizeof(*temp));
        users[temp->name] = temp;
    }
}

void LoginWindow::login(){
    std::cin.ignore();
    std::cout << "Username: ";
    std::string username;
    getline(std::cin, username);
    std::cout << "\n";
    std::cout << "Password: ";
    std::string password;
    getline(std::cin, password);

    if(users.find(username) != users.end()){
        if(strcmp(users.find(username)->second->password, password.c_str()) == 0){
            current_user = users.find(username)->second;
            std::cout << "Welcome " << current_user->name << "\n\n";
            return;
        }
        std::cout << "Wrong Password\n\n";
    }
    else{
        std::cout << "User Not Found\n\n";
    }
}


void LoginWindow::add_user(){
    std::cin.ignore();
    std::cout << "Username: ";
    std::string username;
    getline(std::cin, username);
    std::cout << "\n";
    std::cout << "Password: ";
    std::string password;
    getline(std::cin, password);
    std::cout << "\n";
    std::cout << "Title: ";
    std::string title;
    getline(std::cin, title);

    User temp{title.c_str(), username.c_str(), password.c_str()};
    if(users.find(username) != users.end()){
        std::cout << "User Already Exists\n\n";
        return;
    }
    users_file.write((char*) &temp, sizeof(User));
    fillUsers();
    std::cout << "New user registered.\n\n";
}

void LoginWindow::Exit(){
    current_option = nullptr;
}

//============= Not shown on menu;



User* LoginWindow::get_current_user(){
    return current_user;
}