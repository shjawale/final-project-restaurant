#include "../headers/Menu.hpp"

const int SEPARATOR_LENGTH = 70;


//======== BasicMenuOption =================

void BasicMenuOption::display() {
	std::cout << " - " << label << "\n";
}

void BasicMenuOption::execute() {
	action();
}

std::string BasicMenuOption::get_title(){
	return label;
}

//============ BasicMenu ====================

BasicMenu::BasicMenu(const std::string& _title): menu_title(_title){}


std::string BasicMenu::get_title(){
	return menu_title;
}

void BasicMenu::display(){
	std::cout << std::setfill('-') << std::setw(SEPARATOR_LENGTH) << '-' << "\n\n";
	std::cout << std::setfill(' ');

	std::cout << menu_title << "\n\n";

	for (int i = 0; i < options.size(); i++){
		std::cout << std::setw(20) << i + 1 ;
		options[i]->display();
	}
	std::cout << "\n\n";
}

Menu* BasicMenu::get_current(){
	return current_option;
}

void BasicMenu::switch_options(int index){
	current_option = options[index];
}

void BasicMenu::execute(){
	current_option->execute();
}

void BasicMenu::addOption(Menu* _option){
	options.push_back(_option);
}

void BasicMenu::removeOption(int index){
	options.erase(options.begin() + index);
}


//============ NestedMenu ===================

BasicNestedMenu::BasicNestedMenu(const std::string& _title): window_title(_title){}

void BasicNestedMenu::display(){
	std::cout << std::setfill('=') << std::setw(SEPARATOR_LENGTH) << '=' << "\n\n";
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

std::string BasicNestedMenu::get_title(){
	return window_title;
}

void BasicNestedMenu::switchWindow(int index){
	current_window = windows[index];
}


void BasicNestedMenu::execute(){
	current_window->execute();
}
void BasicNestedMenu::addWindow(BasicMenu* _window){
	windows.push_back(_window);
}

BasicMenu* BasicNestedMenu::get_current(){
	return current_window;
}

void BasicNestedMenu::removeWindow(int index){
	windows.erase(windows.begin() + index);
}

