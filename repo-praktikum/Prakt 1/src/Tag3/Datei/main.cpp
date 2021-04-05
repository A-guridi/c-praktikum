#include <iostream>
#include <readwrite.h>
#include <string>

int main()
{
    std::string Dateiname="";
    readwrite rw;
    bool bStatus=true;

    std::cout<<"file name: ";
    std::cin>>Dateiname;

    if(bStatus==true)
    {
        bStatus=rw.read_file(Dateiname);
    }

    if(bStatus==true)
    {
        bStatus=rw.write_file(Dateiname);
    }


    if(bStatus==true)
    {
        bStatus=rw.read_file(Dateiname);
    }

    return 0;
}
