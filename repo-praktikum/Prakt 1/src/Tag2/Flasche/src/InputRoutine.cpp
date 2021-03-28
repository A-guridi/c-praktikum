#include "InputRoutine.h"
#include<iostream>

//constructor without input parameters
InputRoutine::InputRoutine()
{
    m_sInputMsg="user input: ";
    m_sErrorMsg="ERROR. Try again.";
}

//constructor with input parameters
InputRoutine::InputRoutine(std::string sInputMsg, std::string sErrorMsg)
{
    InputRoutine::m_sInputMsg=sInputMsg;
    InputRoutine::m_sErrorMsg=sErrorMsg;
}

//deconstructor
InputRoutine::~InputRoutine(){}

//input routine double
double InputRoutine::RunInput(double dInput)
{
    std::cout<<m_sInputMsg<<std::endl;
    std::cin>>dInput;
    while(std::cin.fail()==true)
    {
        std::cout<<m_sErrorMsg<<std::endl;
        std::cout<<m_sInputMsg<<std::endl;
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        std::cin>>dInput;
    }
    return dInput;
}

//input routine string
std::string InputRoutine::RunInput(std::string sInput)
{
    std::cout<<m_sInputMsg<<std::endl;
    std::cin>>sInput;
    while(std::cin.fail()==true)
    {
        std::cout<<m_sErrorMsg<<std::endl;
        std::cout<<m_sInputMsg<<std::endl;
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        std::cin>>sInput;
    }
    return sInput;
}
