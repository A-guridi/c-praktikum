#include <iostream>
#include <fstream>
#include <exception>

class nofileException : public std::exception
{
public:
    virtual const char* what() const throw()
    {
        return "Die Datei existiert nicht.";
    }
};

bool read_file(std::string Dateiname)
{
    std::ifstream read;
    std::string sString="";
    int iSize=0;

    //open file and check
    try
    {
        read.open(Dateiname,std::ios::in);
        if(read.is_open()==false)
        {
            throw nofileException{};
        }    //read file
        while(read.eof()==false)
        {
            getline(read,sString);
            iSize++;
            std::cout<<sString<<std::endl;
        }
    }
    catch (nofileException& e)
    {
        std::cout<<e.what()<<std::endl;
    }



    //close file and check
    read.close();
    return true;
}


int main()
{
    read_file("datei.txt");
    return 0;
}
