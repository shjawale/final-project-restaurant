#include <gtest/gtest.h>
#include "../headers/ItemCreator.hpp"
#include "../headers/Plate.hpp"
#include "../headers/SingleItem.hpp"

TEST(ItemCreatorTest, GetSingleItemTest){
	string name = "water";
	
	MoneyClass* money = new MoneyClass();
	money->setMoney(0.75);
	
	std::vector<std::string> mod;
	mod.push_back["with ice"];
	
	Item* item = CreateItem(name, *money, &mod);
    EXPECT_EQ(item->getName(), "water");
    EXPECT_EQ(item->getPrice(), 0.75);
    EXPECT_EQ(item->getModifications(), "with ice");
}

TEST(ItemCreatorTest, GetPlateTest){
    string name = "burrito";

    MoneyClass* money = new MoneyClass();
    money->setMoney(12.45);

    std::vector<std::string> mod;
    mod.push_back["separate hot sauce"];

    Item* item = CreateItem(name, *money, &mod);
    EXPECT_EQ(item->getName(), "burrito");
    EXPECT_EQ(item->getPrice(), 12.45);
    EXPECT_EQ(item->getModifications(), "separate hot sauce");
}
