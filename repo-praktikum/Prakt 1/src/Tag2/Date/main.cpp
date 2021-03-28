#include <iostream>
#include <Date.h>
#include <ctime>


int main()
{
    srand(time(nullptr));
    Date date1=Date(8,03,1995), date2=Date(8,03,1995);

   ;

    std::cout<<"Tag 1:"<<std::endl;
    std::cout<<date1.getDay()<<"."<<date1.getMonth()<<"."<<date1.getYear()<<std::endl;
    std::cout<<"Tag 2:"<<std::endl;
    std::cout<<date2.getDay()<<"."<<date2.getMonth()<<"."<<date2.getYear()<<std::endl;

    std::cout<<"Compare:"<<std::endl;

    std::cout<<date1.compare(date2);
    return 0;
}
