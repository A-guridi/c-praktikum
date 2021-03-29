#include "Student.h"
#include <string.h>



//constructor overload
Student::Student(std::string sName, std::string sSurname, int iAge, unsigned int uiStudentID) : Person(sName, sSurname, iAge)
{
    Student::m_uiStudentID=uiStudentID;
}


//overwrite GetName
std::string Student::getName()
{
    return "Student: " + Person::getName();
}

//getID
unsigned int Student::getID()
{
    return Student::m_uiStudentID;
}
Student::~Student()
{
    //dtor
}
