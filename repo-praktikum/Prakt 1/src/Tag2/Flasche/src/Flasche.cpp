#include "Flasche.h"
#include<iostream>
#include<string>

//constructor
Flasche::Flasche()
{
    //intitializing Variables
    Flasche::m_dVolumen=0;
    Flasche::m_sMaterial="";
}

//overload constructor
Flasche::Flasche(double dVolumen, std::string sMaterial)
{
    //intitializing Variables
    Flasche::m_dVolumen=dVolumen;
    Flasche::m_sMaterial=sMaterial;
}

//destrustor
Flasche::~Flasche()
{
    ///////
}

//get
double Flasche::getVolumen()
{
    return m_dVolumen;
}

std::string Flasche::getMaterial()
{
    return m_sMaterial;
}

//set
bool Flasche::setVolumen(double dVolInput)
{
    if(dVolInput>=0)
    {
        m_dVolumen=dVolInput;
        return true;
    }
    else
    {
        std::cout<<"Volumen muss >0 sein."<<std::endl;
        return false;
    }
}

bool Flasche::setMaterial(std::string sMaterialInput)
{
    m_sMaterial=sMaterialInput;
    return true;
}

//console output
void Flasche::printFlasche()
{
    std::cout<<"Volumen: "<<this->getVolumen()<<std::endl;
    std::cout<<"Material: "<<this->getMaterial()<<std::endl;
}


//adopt
void Flasche::adoptFlasche(double dVolInput, std::string sMaterialInput)
{
    Flasche::m_dVolumen=dVolInput;
    Flasche::m_sMaterial=sMaterialInput;
}
