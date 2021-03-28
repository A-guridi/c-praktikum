#include "vehicle.h"
//static varible init
int vehicle::siCountID=0;


//constr
vehicle::vehicle()
{
    m_iID=siCountID++;
    vehicle::m_Color=schwarz;
    vehicle::m_dPrice=0;
    vehicle::m_iYear=0;
}

//constr overload
vehicle::vehicle(color color, double dPrice, int iYear)
{
    m_iID=siCountID++;
    vehicle::m_Color=color;
    vehicle::m_dPrice=dPrice;
    vehicle::m_iYear=iYear;
}

//deconstr
vehicle::~vehicle()
{
    //dtor
}

//Get-methods
    std::string vehicle::getColor()
    {
        switch (m_Color)
        {
            case 0:
                return "blau";
                break;
            case 1:
                return "rot";
                break;
            case 2:
                return "gruen";
                break;
            case 3:
                return "weiss";
                break;
            case 4:
                return "schwarz";
                break;
        }
    }
    double vehicle::getPrice()
    {
        return m_dPrice;
    }
    int vehicle::getYear()
    {
        return m_iYear;
    }
    int vehicle::getID()
    {
        return m_iID;
    }

//isOldtimer-methode
bool vehicle::isOldtimer(vehicle vehicle)
{
    if(vehicle.getYear()<1980){return true;}
    else {return false;}
}

