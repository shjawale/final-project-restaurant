
#include "../headers/moneyclass.h"

MoneyClass::MoneyClass()
{
    Dollars = 00;
    Cents = 00;
}

MoneyClass::MoneyClass(double tempMoney)
{
    this->setMoney(tempMoney);
}

void MoneyClass::setMoney(double tempMoney)
{
    int tempDollar;
    double tempCent;
    tempDollar = static_cast<int>(tempMoney);
    tempCent = (tempMoney - tempDollar) * 100;
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
    std::string mon = std::to_string(Dollars) + "." + std::to_string(Cents);
    return mon;
}

void MoneyClass::setDiscount(double discount)
{
    std::string totalMoney = std::to_string(Dollars) + "." + std::to_string(Cents);
    double tm = std::stod(totalMoney);
    tm = tm - (tm * (discount / 100));
    this->setMoney(tm);
}

double MoneyClass::getRealMoney()
{
    std::string totalMoney = std::to_string(Dollars) + "." + std::to_string(Cents);
    return std::stod(totalMoney);
}

void MoneyClass::addMoney(double tempMoney)
{
    double realPrice = tempMoney + this->getRealMoney();
    this->setMoney(realPrice);
}

void MoneyClass::subMoney(double tempMoney)
{
    double realPrice = this->getRealMoney() - tempMoney;
    this->setMoney(realPrice);
}
