#pragma once

#include <fstream>
#include <string>
#include <stdexcept>
#include <iostream>
#include <cstring>

class FileIOB{  //Writes data to binary file.
private:
    std::string filename;
    long file_size;
    std::ifstream fileIn;
    std::ofstream fileOut;
    std::streampos get_position;
    std::streampos put_position;
public:
    FileIOB(){};

    FileIOB(const std::string& _filename);

    long tell_size();    //Tells size of file in bytes;

    void set_file(const std::string& _filename);

    void write(char* data, int size);//Writes a block of data of size "size" to file

    void read(char* data, int size); //Reads a blok of data of size "size" to data;

    void setg(std::streampos g);  //Sets "put" to a specific position. 

    void setp(std::streampos p);  //Sets "get" to a specific position.
};