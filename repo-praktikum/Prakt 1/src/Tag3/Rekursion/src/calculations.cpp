#include "calculations.h"
#include <iostream>

calculations::calculations(){}
calculations::~calculations(){}


unsigned int calculations::factorialIter(unsigned int uiInput)
{
    //unsigned int iResult=0;
    if(uiInput>1)
    {
        uiInput=uiInput*calculations::factorialIter(uiInput-1);
    }
    else if(uiInput==1)
    {
        return uiInput;
    }
}

//Aufgerufene Funktion, gibt die ersten zwei Folgenglieder aus und ruft die private iterationfunktion auf
unsigned int calculations::fibonacci(unsigned int uiZ, unsigned int uiN1, unsigned int uiN2)
{
    std::cout<<uiN1<<std::endl;
    std::cout<<uiN2<<std::endl;
    this->fibonacciIter(uiZ-2,uiN1,uiN2);
}

//private iterationfunktion
unsigned int calculations::fibonacciIter(unsigned int uiZ, unsigned int uiN1, unsigned int uiN2)
{
    unsigned int uiResult=uiN1+uiN2;
    std::cout<<uiResult<<std::endl;
    if(uiZ>1)
    {
        calculations::fibonacciIter(uiZ-1,uiN2,uiResult);
    }
    else
    {
        return uiResult;
    }
}

