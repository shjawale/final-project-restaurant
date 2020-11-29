#include "../headers/LoginWindow.hpp"

LoginWindow::LoginWindow(const std::string& _title,const std::string& _filename): BasicMenu(_title){
    current_user = nullptr;
    users_file = _filename;

    //filling up the users vector.
    readUsers();


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


void LoginWindow::readUsers(){
    std::ifstream inFile(users_file);
    if(inFile.is_open()){
        std::string title, username, password;
        while(inFile >> title){
            inFile >> username;
            inFile >> password;
            users[username] = new User({title, username, password});
        }
        inFile.close();
    }
    else{
        throw std::runtime_error("inFile Did Not Open");
    }
}

void LoginWindow::writeUsers(){
    std::ofstream outFile;
    outFile.open(users_file);

    if(outFile.is_open()){
        for(auto user : users){
            outFile << user.second->title << " ";
            outFile << user.second->name << " ";
            outFile << user.second->password;
            outFile << std::endl;
        }
        outFile.close();
    }
    else{
        throw std::runtime_error("outFile Did Not Open");
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

    auto user = users.find(username);

    if(user != users.end()){
        if(user->second->password == password){
            current_user = user->second;
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

    if (users.find(username) != users.end()){
        std::cout << "User Already Exists\n\n";
        return;
    }
    users[username] = new User({title, username, password});

    writeUsers();
}

void LoginWindow::Exit(){
    current_option = nullptr;
}

//============= Not shown on menu;



User* LoginWindow::get_current_user(){
    return current_user;
}