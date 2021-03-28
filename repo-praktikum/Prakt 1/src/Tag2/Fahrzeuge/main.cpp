#include <iostream>
#include <vehicle.h>



int main()
{
    //Erzeugen der objekte
    vehicle auto1=vehicle(vehicle::schwarz,12000,1980);
    vehicle auto2=vehicle(vehicle::blau,10.52,2010);
    vehicle auto3=vehicle(vehicle::rot,237241,1979);

    //test
    std::cout<<"Auto 1 ID: "<<auto1.getID()<<std::endl;
    std::cout<<"Auto 1 Farbe: "<<auto1.getColor()<<std::endl;
    std::cout<<"Auto 1 Baujahr: "<<auto1.getYear()<<std::endl;
    std::cout<<"Auto 1 Oldtimer: "<<auto1.isOldtimer(auto1)<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Auto 2 ID: "<<auto2.getID()<<std::endl;
    std::cout<<"Auto 2 Farbe: "<<auto2.getColor()<<std::endl;
    std::cout<<"Auto 2 Baujahr: "<<auto2.getYear()<<std::endl;
    std::cout<<"Auto 2 Oldtimer: "<<auto2.isOldtimer(auto2)<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Auto 3 ID: "<<auto3.getID()<<std::endl;
    std::cout<<"Auto 3 Farbe: "<<auto3.getColor()<<std::endl;
    std::cout<<"Auto 3 Baujahr: "<<auto3.getYear()<<std::endl;
    std::cout<<"Auto 3 Oldtimer: "<<auto3.isOldtimer(auto3)<<std::endl;

    return 0;
}
