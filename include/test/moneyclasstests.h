#ifndef MONEYCLASSTESTS_H
#define MONEYCLASSTESTS_H

#include <gtest/gtest.h>
#include "../headers/moneyclass.h"

TEST(MoneyclassTest, GetDollarTest)
{
    MoneyClass* test = new MoneyClass();
    EXPECT_EQ(test->getDollar(), 00);

    test->setMoney(123.45);
    EXPECT_EQ(test->getDollar(), 123);

    MoneyClass* test2 = new MoneyClass(987.65);
    EXPECT_EQ(test2->getDollar(), 987);

    test2->setMoney(1.78);
    EXPECT_EQ(test2->getDollar(), 1);
}

TEST(MoneyclassTest, GetCentTest)
{
    MoneyClass* test = new MoneyClass();
    EXPECT_EQ(test->getCent(), 00);

    test->setMoney(123.45);
    EXPECT_EQ(test->getCent(), 45);

    MoneyClass* test2 = new MoneyClass(987.65);
    EXPECT_EQ(test2->getCent(), 65);

    test2->setMoney(1.78);
    EXPECT_EQ(test2->getCent(), 78);
}

TEST(MoneyclassTest, GetTotalTest)
{
    MoneyClass* test = new MoneyClass();
    EXPECT_EQ(test->getTotal(), "0.0");

    test->setMoney(123.45);
    EXPECT_EQ(test->getTotal(), "123.45");

    MoneyClass* test2 = new MoneyClass(987.65);
    EXPECT_EQ(test2->getTotal(), "987.65");

    test2->setMoney(1.78);
    EXPECT_EQ(test2->getTotal(), "1.78");
}

#endif