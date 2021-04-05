#include <iostream>
#include <list>

struct coord
{
    float m_fX, m_fY;
    coord(float x, float y)
    {
        m_fX=x;
        m_fY=y;
    };
};

void printlist()
{

}

int main()
{
    float f1=1, f2=2;
    std::list<coord> mylist;
    std::list<coord>::iterator myiterator;
    myiterator=mylist.begin();
    *myiterator=coord(f1,f2);
    myiterator++;
    *myiterator=coord(f1,f2);
    std::cout<<*myiterator.m_fX;


    return 0;
}
