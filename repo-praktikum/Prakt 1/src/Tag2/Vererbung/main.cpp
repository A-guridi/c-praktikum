#include <iostream>
#include<Person.h>
#include<Student.h>

int main()
{
    int z;

    Person person1=Person("Alex", "Hug", 26);
    Student stud1=Student("Arturo","Guridi",25,366123);

    std::cout<<"Person 1: "<<std::endl;
    std::cout<<stud1.getName()<<std::endl;
    std::cout<<"Person 2: "<<std::endl;
    std::cout<<person1.getName()<<std::endl;

    //Überschreiben mit Kindklasse
    person1=stud1;

    std::cout<<"Person 1: "<<std::endl;
    std::cout<<stud1.getName()<<std::endl;
    std::cout<<"Person 2: "<<std::endl;
    std::cout<<person1.getName()<<std::endl<<std::endl;


    //pointer auf person
    Person* pp[3];

    //eingabe
    for(z=0;z<3;z++)
    {
        std::string* pString1=new std::string;
        std::string* pString2=new std::string;
        int* int1 = new int;
        unsigned int* int2 = new unsigned int;

        std::cout<<"Vorname: ";
        std::cin>>*pString1;
        std::cout<<"Nachname: ";
        std::cin>>*pString2;
        std::cout<<"Alter: ";
        std::cin>>*int1;
        std::cout<<"ID: ";
        std::cin>>*int2;

        pp[z]= new Student("*pString1","*pString2",*int1,*int2);
        delete pString1, pString2, int1, int2;

    }
    //ausgabe
    for(z=0;z<3;z++)
    {
        std::cout<<"Vorname: "<<pp[z]->getName();
        std::cout<<"Nachname: "<<pp[z]->getSurname();
        std::cout<<"Alter: "<<pp[z]->getAge();
        std::cout<<"ID: "<<pp[z]->getID();
    }
    std::cout<<pp[0]->getAge();
    return 0;
}
