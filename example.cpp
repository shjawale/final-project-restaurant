#include "include/headers/Menu.h"
// The following code should be on a separate .hpp
// I wrote it here for brevity

#include <iomanip>

struct Smoothie{
    std::string flavor;
    std::string size;
    double price;
    Smoothie(double p): price(p){}
};

class SmoothieMenu: public BasicNestedMenu {
private:
    Smoothie* smooth;
public:
    SmoothieMenu(const std::string& _title, Smoothie* _s);

    void AskFlavor();

    void AskSize();

    void Checkout();

    void Exit();
};


// This would go on a separate .cpp file

SmoothieMenu::SmoothieMenu(const std::string& _title, Smoothie* _s): BasicNestedMenu(_title), smooth(_s){
    choices[choices.size() + 1] = new BasicMenuOption("Enter flavor", [this](){ AskFlavor(); });
    choices[choices.size() + 1] = new BasicMenuOption("Enter size", [this](){ AskSize(); });
    choices[choices.size() + 1] = new BasicMenuOption("Checkout", [this](){ Checkout(); });
    choices[choices.size() + 1] = new BasicMenuOption("Exit", [this](){ Exit(); });
}

void SmoothieMenu::AskFlavor(){
    std::cin.ignore();
    std::cout << "What flavor would you like: ";
    std::string flavor;
    std::getline(std::cin, flavor);
    smooth->flavor = flavor;
}

void SmoothieMenu::AskSize(){
    std::cin.ignore();
    std::cout << "What size would you like: ";
    std::string size;
    std::getline(std::cin, size);
    smooth->size = size;
}

void SmoothieMenu::Checkout(){
    std::cout << "You ordered a " << smooth->size << " " << smooth->flavor << " smoothie.\n";
    std::cout << std::setprecision(3) << "Your total is: $" << smooth->price << "\n\n";
}

void SmoothieMenu::Exit(){
    done = true;
}

//---------------- classes' code ends here ---------------------------


int main(){
    Smoothie Asmoothie(4.57);
    SmoothieMenu menu("Smoothie Menu", &Asmoothie);

    menu.execute();
    return 0;
}