
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
    double tempDollar;
    double tempCent;
    tempCent = modf(tempMoney, &tempDollar);  // separates the whole and the fractional part of a double.
    Dollars = static_cast<int>(tempDollar + ERROR);
    Cents = static_cast<int>((tempCent + ERROR) * 100);
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
    //std::string stream
    std::string mon = std::to_string(Dollars) + "." + std::to_string(Cents);
    return mon;
}

void MoneyClass::setDiscount(double discount)
{
    double real_discount = getRealMoney() * ((discount / 100.0) + ERROR);
    subMoney(real_discount);
}

double MoneyClass::getRealMoney()
{
    std::string totalMoney = std::to_string(Dollars) + "." + std::to_string(Cents);
    return std::stod(totalMoney);
}

void MoneyClass::addMoney(double tempMoney)
{
    double realPrice = tempMoney + this->getRealMoney();
    this->setMoney(realPrice + ERROR);
}

void MoneyClass::subMoney(double tempMoney)
{
    double realPrice = this->getRealMoney() - tempMoney;
    this->setMoney(realPrice + ERROR);
}
