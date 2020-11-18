
#include "../headers/moneyclass.h"

#define ERROR 0.000001

MoneyClass::MoneyClass()
{
    Dollars = 00;
    Cents = 00;
}

MoneyClass::MoneyClass(double tempMoney)
{
    int tempDollar;
    double tempCent;
    tempDollar = static_cast<int>(tempMoney);
    tempCent = (tempDollar - tempMoney) * 100;
    Dollars = tempDollar;
    Cents = round(tempCent + ERROR);
}

void MoneyClass::setMoney(double tempMoney)
{
    int tempDollar;
    double tempCent;
    tempDollar = static_cast<int>(tempMoney);
    tempCent = (tempDollar - tempMoney) * 100;
    Dollars = tempDollar;
    Cents = round(tempCent + ERROR);
}

long int MoneyClass::getDollar()
{
    return Dollars;
}

int MoneyClass::getCent()
{
    return Cents;
}

std::string MoneyClass::getTotal()
{
    return Dollars + "." + Cents;
}