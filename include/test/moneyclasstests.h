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
    EXPECT_EQ(test->getDollar(), 987);

    test->setMoney(1.78);
    EXPECT_EQ(test->getDollar(), 1);
}

#endif