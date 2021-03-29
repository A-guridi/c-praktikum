#include "Person.h"
#include<string>

//constructor
Person::Person(std::string sName, std::string sSurname, int iAge) :  m_sName(sName), m_sSurname(sSurname), m_iAge(iAge)
{

}

//deconstructor
Person::~Person(){}

//Get/set
std::string Person::getName()
{
    return Person::m_sName;
}

std::string Person::getSurname()
{
    return Person::m_sSurname;
}

int Person::getAge()
{
    return m_iAge;
}

void Person::setAge(int iAge)
{
    Person::m_iAge=iAge;
}
