#include "../headers/FileIOB.hpp"

FileIOB::FileIOB(const std::string& _filename){
    filename = _filename;
    get_position = 0;
    put_position = 0;
}


void FileIOB::write(char* data, int size){
    fileOut.open(filename, std::ios::binary | std::ios::app);
    fileOut.seekp(put_position);

    if(fileOut.is_open()){
        fileOut.write(data, size);
        put_position = fileOut.tellp();
        fileOut.close();
    }
    else{
        throw std::runtime_error("Ofile did not open.");
        std::cout << "fileOut did not open\n\n";
    }
}

void FileIOB::read(char* data, int size){
    fileIn.open(filename, std::ios::binary);
    fileIn.seekg(get_position);


    if(fileIn.is_open()){
        if(!fileIn.read(data, size)){
            std::cout << "get position: " << fileIn.tellg() << "\n";
            std::cout << "Bytes read: " << fileIn.gcount() << "\n";
            fileIn.clear();
            throw std::runtime_error("Error while reading data");
        }
        get_position = fileIn.tellg();
        fileIn.close();
    }
    else{
        throw std::runtime_error("Infile did not open.");
        std::cout << "fileIn did not open\n\n";
    }
}


void FileIOB::setg(std::streampos g){
    get_position = g;
}

void FileIOB::setp(std::streampos p){
    put_position = p;
}