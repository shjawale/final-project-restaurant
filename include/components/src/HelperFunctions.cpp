
#include <iostream>
#include <iomanip>

static void printAtCenter(std::string name, char fill, int sizeSet)
{
    sizeSet = sizeSet - name.size();
    int left, right;
    if  (sizeSet % 2 == 0)
    {
        left = sizeSet / 2;
        right = sizeSet / 2;
    }
    else
    {
        left = (sizeSet / 2) + 1;
        right = sizeSet / 2;
    }

    while(left > 0)
    {
        std::cout << fill;
        left--;
    }
    std::cout << name;
    while(right > 0)
    {
        std::cout << fill;
        right--;
    }
    std::cout << std::endl;
}

static void printAtCenterCont(std::string name, char fill, int sizeSet)
{
    sizeSet = sizeSet - name.size();
    int left, right;
    if  (sizeSet % 2 == 0)
    {
        left = sizeSet / 2;
        right = sizeSet / 2;
    }
    else
    {
        left = (sizeSet / 2) + 1;
        right = sizeSet / 2;
    }

    while(left > 0)
    {
        std::cout << fill;
        left--;
    }
    std::cout << name;
    while(right > 0)
    {
        std::cout << fill;
        right--;
    }
    //std::cout << std::endl;
}