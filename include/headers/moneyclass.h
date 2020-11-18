#ifndef MONEYCLASS_H
#define MONEYCLASS_H

#include <string>

class MoneyClass
{
    private:
        long int Dollars;
        int Cents;

    public:
        MoneyClass();
        MoneyClass(double tempMoney);
        void setMoney(double tempMoney);
        long int getDollar();
        int getCent();
        std::string getTotal(); 
};

#endif