#pragma once

#include <fstream>
#include <string>
#include <stdexcept>
#include <iostream>
#include <cstring>

struct User{
    std::string position;
    std::string username; 
    std::string password;
};


class FileIOB{  //Writes data to binary file. Always in append mode.
private:
    std::string filename;
    std::ifstream fileIn;
    std::ofstream fileOut;
public:
    FileIOB(const std::string& _filename);

    void write(char* data, int size);//Writes a block of data of size "size" to file

    void read(char* data, int size); //Reads a blok of data of size "size" to data;

    void erase(char* data, int size); //Erases block of data "data" of size "size" from file
};