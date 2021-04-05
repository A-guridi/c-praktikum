#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>

struct coord
{
    float m_fX, m_fY;
    coord()
    {
        m_fX=0;
        m_fY=0;
    };
    coord(float x, float y)
    {
        m_fX=x;
        m_fY=y;
    };
};

void printlist(std::list<coord>* mylist)
{
    std::list<coord>::iterator myiterator;
    for(myiterator = mylist->begin(); myiterator != mylist->end(); myiterator++)
    {
        std::cout<<"X-Value: ";
        std::cout<<myiterator->m_fX<<"\t";
        std::cout<<"Y-Value: ";
        std::cout<<myiterator->m_fY<<std::endl;
    };
}

void delcoords(std::list<coord>& mylist)
{
    std::list<coord>::iterator myiterator;
    myiterator = mylist.begin();

    while(myiterator != mylist.end())
    {
        if((myiterator->m_fX)<(myiterator->m_fY))  //if condition==true, delete element and set iterator to next element
        {
            myiterator=mylist.erase(myiterator);
        }
        else                    //if condition==false, set iterator to next element
        {
            myiterator++;
        }
    }
}

int main()
{
    srand(time(nullptr));

    int z=0;
    std::list<coord> myList1;
    std::list<coord> myList2;
    std::list<coord>* pList1=&myList1;
    std::list<coord>* pList2=&myList2;

    //erstellung zufälliger listenelemente
    for(z=1;z<=10;z++)
    {
        myList1.push_back(coord(rand() % 20 + -10,rand() % 20 + -10));
    }

    //Liste kopieren
    myList2=myList1;

    //Zufällige Liste ausgeben
    std::cout<<"----------------RANDOM LIST #1--------------------------------"<<std::endl;
    printlist(pList1);

    delcoords(myList2);

    std::cout<<"----------------RANDOM LIST #1--------------------------------"<<std::endl;
    printlist(pList1);

    std::cout<<"----------------RANDOM LIST #2---------(except x<y)-----------"<<std::endl;
    printlist(pList2);
    return 0;
}
