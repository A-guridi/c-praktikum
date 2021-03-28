#include "square.h"

//constructor
square::square()
{
    square::m_iLength=0;
}

//constructor overload
square::square(int iLength)
{
    square::m_iLength=iLength;
}

//Constructor which gets a square object reference
square::square(const square& riSq)
{
    m_iLength=riSq.getLength();
}

//destr
square::~square()
{
    //dtor
}

//GetSet
    int square::getLength() const
    {
        return square::m_iLength;
    }

    int square::getScope() const
    {
        return 4*square::m_iLength;
    }
    int square::getSurf() const
    {
        return square::m_iLength * square::m_iLength;
    }
