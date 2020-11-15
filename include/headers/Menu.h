#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <functional>
#include <map>
#include <exception>

// Component
class Menu {
public:
	virtual void display() = 0;
	virtual void execute() = 0;
	virtual Menu* returnBasic() = 0; // Returns a Menu* that is assigned to the corresponding type (i.e., BasicMenuOption).
	virtual bool quit() = 0;
};


// Leafs
class BasicMenuOption : public Menu {
protected:
	std::function<void()> action;
	std::string label;
public:
	BasicMenuOption(const std::string& _name, std::function<void()> _action)
	: label(_name), action(_action){}
	void display();
	void execute();
	Menu* returnBasic();
	bool quit();
};



// Composites
class BasicNestedMenu : public Menu {
protected:
	std::string title;
	std::map<int, Menu*> choices;
	Menu* chosen;
	bool done = false;
	virtual void choose();
public:
	// Constructor, destructor, and shared Menu members
	BasicNestedMenu(const std::string& _name): title(_name), chosen(nullptr) {}
	~BasicNestedMenu();
	void display();
	void execute();
	Menu* returnBasic();
	bool quit();
public:
	// BasicNestedMenu only members  
	void addOption(Menu* op);
	void removeOption(int index);
};