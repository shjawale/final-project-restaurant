#ifndef __CREATOR_CLASS_H__
#define __CREATOR_CLASS_H__

#include <gtest/gtest.h>
#include "../../include/components/headers/Item.h"
#include "../../include/components/headers/moneyclass.h"
#include "../../include/components/headers/ItemCreator.hpp"
#include "../../include/components/headers/plate.h"
#include "../../include/components/headers/SingleItem.hpp"

TEST(ItemCreatorTest, GetSingleItemTest){
	std::string name = "water";
	
	MoneyClass* money = new MoneyClass();
	money->setMoney(0.75);
	
	std::vector<std::string> mod;
	mod.push_back("with ice");
	
	ItemCreator itemCreator;	
    Item* item = itemCreator.CreateItem(SINGLE_ITEM_T, name, *money, mod);
    EXPECT_EQ(item->getName(), "water");
    EXPECT_EQ(item->getPrice().getTotal(), "0.75");
    EXPECT_EQ(item->getModifications(), mod); //{"with ice"});
}

TEST(ItemCreatorTest, GetPlateTest){
    std::string name = "burrito";

    MoneyClass* money = new MoneyClass();
    money->setMoney(12.45);

    std::vector<std::string> mod;
    mod.push_back("separate hot sauce");

    ItemCreator itemCreator;
	Item* item = itemCreator.CreateItem(PLATE_ITEM_T, name, *money, mod);
    EXPECT_EQ(item->getName(), "burrito");
    EXPECT_EQ(item->getPrice().getTotal(), "12.45");
    EXPECT_EQ(item->getModifications(), mod); //{"separate hot sauce"});
}


TEST(ItemCreatorTest, GetSingleItemTest2){
    std::string name = "orange juice";

    MoneyClass* money = new MoneyClass();
    money->setMoney(1.75);

    std::vector<std::string> mod;
    mod.push_back("with a straw");
    mod.push_back("no pulp");

    ItemCreator itemCreator;
    Item* item = itemCreator.CreateItem(SINGLE_ITEM_T, name, *money, mod);
    EXPECT_EQ(item->getName(), "orange juice");
    EXPECT_EQ(item->getPrice().getTotal(), "1.75");
    EXPECT_EQ(item->getModifications(), mod);
}

TEST(ItemCreatorTest, GetPlateTest2){
    std::string name = "burger";

    MoneyClass* money = new MoneyClass();
    money->setMoney(12.95);

    std::vector<std::string> mod;
    mod.push_back("with fries");
    mod.push_back("and shake");

    ItemCreator itemCreator;
    Item* item = itemCreator.CreateItem(PLATE_ITEM_T, name, *money, mod);
    EXPECT_EQ(item->getName(), "burger");
    EXPECT_EQ(item->getPrice().getTotal(), "12.95");
    EXPECT_EQ(item->getModifications(), mod);
}


#endif
