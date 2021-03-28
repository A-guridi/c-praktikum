#include <iostream>
#include <square.h>

//addition operator overload
square operator+(square s1, square s2)
{
    return square(s1.getLength()+s2.getLength());
}

// shift operator overload
std::ostream& operator<<(std::ostream &os, const square &sq)
{
    return os << "Quadrat:" << std::endl << "Kantenlaenge: " << sq.getLength() << std::endl << "Umfang: "
    << sq.getScope()<< std::endl << "Flaeche: " << sq.getSurf() << std::endl;
}

int main()
{
    square s1=square(3);
    square s2=square(s1);
    square s3=s1+s2;

    //overload test
    std::cout<<s1;
    std::cout<<s2;
    std::cout<<s3;
    return 0;
}
