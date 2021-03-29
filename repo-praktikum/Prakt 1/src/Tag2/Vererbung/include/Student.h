#ifndef STUDENT_H
#define STUDENT_H

#include<Person.h>
#include<string.h>

class Student : public Person
{
    public:
        Student(std::string sName, std::string sSurname, int iAge, unsigned int uiStudentID);
        virtual ~Student();
        std::string getName();
        unsigned int getID();

    protected:

    private:
        unsigned int m_uiStudentID;
};

#endif // STUDENT_H
