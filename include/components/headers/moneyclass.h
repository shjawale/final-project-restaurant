#ifndef MONEYCLASS_H
#define MONEYCLASS_H

#include <string>
#include <cmath>

#define ERROR 0.000001

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
        void setDiscount(double discount);
        double getRealMoney();
        void addMoney(double tempMoney);
        void subMoney(double tempMoney);
};

#endif