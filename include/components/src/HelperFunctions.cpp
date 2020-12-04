
#include "../headers/Item.h"
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

static void printVector(std::vector<Item*> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v.at(i)->getName() << ": " << v.at(i)->getPrice().getTotal() << "  ";
    }
}

static int checkIntSelection(int i, int size)
{
    while(i >= size)
    {
        std::cout << "You have entered an incorrect choice, choose again: ";
        std::cin >> i;
        std::cin.clear();
    }
    return i;
}