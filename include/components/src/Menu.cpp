#include "../headers/Menu.h"


//======== BasicMenuOption =================

void BasicMenuOption::display() {
	std::cout << " - " << label << "\n";
}

void BasicMenuOption::execute() {
	action();
}


Menu* BasicMenuOption::returnBasic() {
	return this;
}

bool BasicMenuOption::quit() {
	throw std::runtime_error("NOT A NESTED MENU");
}

//============ NestedMenu ===================

BasicNestedMenu::~BasicNestedMenu() {
	for (auto a : choices) {
		delete a.second;
	}
}

void BasicNestedMenu::choose() {
	std::cout << "Enter Option: ";
	int selection;
	std::cin >> selection;
	chosen = choices[selection];
}

void BasicNestedMenu::display() {
	std::cout << std::setw(50) << title << "\n\n";
	std::cout << std::setw(50 - title.size()*2) << "=" << std::setw(title.size()* 3) << std::setfill('=') << "\n\n";
	std::cout << std::setfill(' ');

	for (auto option : choices) {
		std::cout << std::setw(40) << option.first; option.second->display();
	}
}

void BasicNestedMenu::execute() {
	while (!quit()) {
		display();
		choose();
		chosen->execute();
		std::cout << "\n\n";
	}
}

void BasicNestedMenu::addOption(Menu* op) {
	choices[choices.size() + 1] = op->returnBasic();
}

void BasicNestedMenu::removeOption(int index) {
	choices.erase(index);
}

bool BasicNestedMenu::quit() {
	return done;
}

Menu* BasicNestedMenu::returnBasic() {
	return new BasicMenuOption(
		title,
		[this]() {
			while (!quit()) {
				execute();
			}
			done = false;
		}
	);
}