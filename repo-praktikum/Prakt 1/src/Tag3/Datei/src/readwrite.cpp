#include "readwrite.h"
#include <fstream>
#include <iostream>

readwrite::readwrite()
{
    //ctor
}

readwrite::~readwrite(){}

bool readwrite::read_file(std::string Dateiname)
{
    std::ifstream read;
    std::string sString="";
    int iSize=0;

    //open file and check
    read.open(Dateiname,std::ios::in);
    if(read.is_open()==false)
    {
        std::cout<<"File could not be opened";
        return false;
    }
    std::cout<<"-------------------file: "<<Dateiname<<"----------------------"<<std::endl;
    while(read.eof()==false)
    {
        getline(read,sString);
        iSize++;
        std::cout<<sString<<std::endl;
    }

    std::cout<<"---------------file end: "<<Dateiname<<"----------------------"<<std::endl;
    //close file and check
    read.close();
    if(read.is_open()==true)
    {
        std::cout<<"File could not be closed";
        return false;
    }
    return true;
}

bool readwrite::write_file(std::string Dateiname)
{
    std::string sInput="";
    std::ofstream write;

    //open file and check
    write.open(Dateiname,std::ios::out | std::ios::app);
    if(write.is_open()==false)
    {
        std::cout<<"File could not be opened";
        return false;
    }

    std::cout<<"your text here:"<<std::endl;
    while(sInput!="exit")
    {
        std::cin>>sInput;
        if(sInput!="exit")
        {
            write<<std::endl<<sInput;
        }
    }
    //close file and check
    write.close();
    if(write.is_open()==true)
    {
        std::cout<<"File could not be closed";
        return false;
    }
    return true;
}
