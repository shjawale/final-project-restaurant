#include "../headers/FileIO.hpp"

FileIOB::FileIOB(const std::string& _filename){
    filename = _filename;
}


void FileIOB::write(char* data, int size){
    fileOut.open(filename, std::ios::binary | std::ios::app);
    
    if(fileOut.is_open()){
        fileOut.write(data, size);
        fileOut.close();
    }
    else{
        throw std::runtime_error("File did not open.");
        std::cout << "fileOut did not open\n\n";
    }
}