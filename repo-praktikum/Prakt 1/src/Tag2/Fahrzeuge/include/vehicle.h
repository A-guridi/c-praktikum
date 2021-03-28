#ifndef VEHICLE_H
#define VEHICLE_H

#include<string>

class vehicle
{
    public:
        //color variable definition
        enum color{blau,rot,gruen,weiss,schwarz};
        vehicle();
        vehicle(color color, double dPrice, int iYear);
        virtual ~vehicle();
        std::string getColor();
        double getPrice();
        int getYear();
        int getID();
        static bool isOldtimer(vehicle vehicle);


    protected:

    private:
        int m_iID; //ID des Objetks
        static int siCountID;
        double m_dPrice;
        int m_iYear;
        color m_Color;
};

#endif // VEHICLE_H
