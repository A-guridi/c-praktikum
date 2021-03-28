#ifndef STUDENT_H
#define STUDENT_H

#include<Person.h>
#include<string.h>

class Student : public Person
{
    public:
        Student(unsigned int uiStudentID, std::string sName, std::string sSurname, int iAge);
        virtual ~Student();

    protected:

    private:
        unsigned int m_uiStudentID;
};

#endif // STUDENT_H
