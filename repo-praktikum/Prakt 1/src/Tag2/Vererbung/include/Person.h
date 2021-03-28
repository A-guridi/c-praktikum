#ifndef PERSON_H
#define PERSON_H

#include<string>

class Person
{
    public:
        Person(std::string sName, std::string sSurname, int iAge);
        virtual ~Person();
        std::string getName();
        std::string getSurname();
        int getAge();
        void setAge(int iAge);

    protected:

    private:
        std::string m_sName;
        std::string m_sSurname;
        int m_iAge;
};

#endif // PERSON_H
