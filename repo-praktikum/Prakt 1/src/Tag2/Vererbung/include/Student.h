#ifndef STUDENT_H
#define STUDENT_H

#include<Person.h>
#include<string.h>

class Student : public Person
{
    public:
        Student(unsigned int uiStudentID);
        virtual ~Student();

    protected:

    private:
        unsigned int m_uiStudentID;
};

#endif // STUDENT_H
