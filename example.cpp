#include "include/components/headers/Menu.hpp"
// The following code should be on a separate .hpp
// I wrote it here for brevity

#include <iomanip>

struct Smoothie{
    std::string flavor;
    std::string size;
    double price;
    Smoothie(double p): price(p){}
};

class SmoothieMenu: public BasicMenu {
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
SmoothieMenu::SmoothieMenu(const std::string& _title, Smoothie* _s): BasicMenu(_title){
    smooth = _s;
    addOption(new BasicMenuOption("Ask Flavor", [this](){AskFlavor();}));
    addOption(new BasicMenuOption("Ask Size", [this](){AskSize();}));
    addOption(new BasicMenuOption("Checkout", [this](){Checkout();}));
    addOption(new BasicMenuOption("Exit", [this](){Exit();}));
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
    current_option = nullptr;
}

//------------- Separate Chips Window -----------------------------------

struct Chips{
    std::string flavor;
    double price;
   Chips(double p): price(p){}
};

class ChipsMenu: public BasicMenu {
private:
   Chips* chip;
public:
   ChipsMenu(const std::string& _title, Chips* _c);

    void AskFlavor();

    void Checkout();

    void Exit();
};

// ----------------- ChipsMenu ---------------------------------------
ChipsMenu::ChipsMenu(const std::string& _title, Chips* _c): BasicMenu(_title){
    chip = _c;
    addOption(new BasicMenuOption("Ask Flavor", [this](){AskFlavor();}));
    addOption(new BasicMenuOption("Checkout", [this](){Checkout();}));
    addOption(new BasicMenuOption("Exit", [this](){Exit();}));
}

void ChipsMenu::AskFlavor(){
    std::cin.ignore();
    std::cout << "What flavor would you like: ";
    std::string flavor;
    std::getline(std::cin, flavor);
    chip->flavor = flavor;
}

void ChipsMenu::Checkout(){
    std::cout << "You ordered a "<< chip->flavor << " Chips.\n";
    std::cout << std::setprecision(3) << "Your total is: $" << chip->price << "\n\n";
}

void ChipsMenu::Exit(){
    current_option = nullptr;
}


//---------------- classes' code ends here ---------------------------


int main(){
    Smoothie Asmoothie(4.57);
    Chips Achip(1.25);
    BasicNestedMenu menu("Chips Store");
    menu.addWindow(new SmoothieMenu("Smoothies", &Asmoothie));
    menu.addWindow(new ChipsMenu("Chips", &Achip));

    menu.execute();
    return 0;
}