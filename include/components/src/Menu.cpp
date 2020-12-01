#include "../headers/Menu.hpp"

const int SEPARATOR_LENGTH = 50;


//======== BasicMenuOption =================

void BasicMenuOption::display() {
	std::cout << " - " << label << "\n";
}

void BasicMenuOption::execute() {
	action();
}

//============ BasicMenu ====================

BasicMenu::BasicMenu(const std::string& _title): menu_title(_title){}


std::string BasicMenu::get_title(){
	return menu_title;
}

void BasicMenu::display(){
	std::cout << std::setfill('-') << std::setw(SEPARATOR_LENGTH) << "\n\n";
	std::cout << std::setfill(' ');

	std::cout << menu_title << "\n\n";

	for (int i = 0; i < options.size(); i++){
		std::cout << std::setw(20) << i + 1 ;
		options[i]->display();
	}
	std::cout << "\n\n";
}

void BasicMenu::execute(){
	current_option = options[0];
	do{
		display();
		std::cout << "Enter choice: ";
		int choice;
		std::cin >> choice;
		if (choice > options.size() || choice < 0) throw std::runtime_error("OUT OF BOUND");
		options[choice-1]->execute();
	}while(current_option);
}

void BasicMenu::addOption(BasicMenuOption* _option){
	options.push_back(_option);
}

void BasicMenu::removeOption(int index){
	options.erase(options.begin() + index);
}


//============ NestedMenu ===================

BasicNestedMenu::BasicNestedMenu(const std::string& _title): window_title(_title){}

void BasicNestedMenu::display(){
	std::cout << std::setfill('=') << std::setw(SEPARATOR_LENGTH) << "\n\n";
	std::cout << std::setfill(' ');

	std::cout << window_title << "\n\n";

	for(int i = 0; i < windows.size(); i++){
		int spacing = windows[i]->get_title().size()/2 + 1;
		std::cout << std::setw(spacing*2) << windows[i]->get_title() << std::setw(4) << "|";
	}
	std::cout << std::endl;
	
	for (int i = 0; i < windows.size(); i++){
		int spacing = windows[i]->get_title().size()/2 + 1;
		std::cout << std::setw(spacing*2) << i + 1 << std::setw(4) << "|";
	}
	std::cout << "\n\n";
}

void BasicNestedMenu::switchWindow(){
	display();
	std::cout << "Enter Q to quit\nEnter window: ";
	int temp;
	std::cin >> temp;
	if(std::cin.fail()){
		current_window = nullptr;
		std::cout << "Closing Program...\n";
		return;
	}
	if(temp > windows.size() || temp < 0){
		throw std::runtime_error("OUT OF BOUND");
	}

	current_window = windows[temp-1];
}


void BasicNestedMenu::execute(){
	current_window = windows[0];
	do{
		display();
		current_window->execute();
		switchWindow();
	}while(current_window);
}
void BasicNestedMenu::addWindow(BasicMenu* _window){
	windows.push_back(_window);
}
void BasicNestedMenu::removeWindow(int index){
	windows.erase(windows.begin() + index);
}

