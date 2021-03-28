#include <Date.h>
#include <cstdlib>


//constructor
Date::Date()
{
    //random year
    m_iYear=rand() % 60+1970;
    //random month
    m_iMonth=rand() % 11+1;
    //random day
    if(m_iMonth==1||m_iMonth==3||m_iMonth==5||m_iMonth==7||m_iMonth==8||m_iMonth==10||m_iMonth==12)
    {
        m_iDay=rand() % 30+1;
    }
    else if(m_iMonth==2)
    {
        m_iDay=rand() % 27+1;
    }
    else
    {
        m_iDay=rand() % 29+1;
    }
}

//constructor overload for given values
Date::Date(int iDay, int iMonth, int iYear)
{
    Date::m_iDay=iDay;
    Date::m_iMonth=iMonth;
    Date::m_iYear=iYear;
}

//deconstructor
Date::~Date()
{

}

//GetDay
int Date::getDay()
{
    return m_iDay;
}

//GetMonth
int Date::getMonth()
{
    return m_iMonth;
}

//GetYear
int Date::getYear()
{
    return m_iYear;
}


//IsEqual
bool Date::isEqual(Date dd)
{
    if(m_iDay==dd.getDay() && m_iMonth==dd.getMonth()&& m_iYear==dd.getYear()){return true;}
    else {return false;}
}

//Compare
int Date::compare(Date dd)
{
    if(dd.getYear()>m_iYear)
    {
        return 1;
    }
    else if(dd.getYear()<m_iYear)
    {
        return -1;
    }
    else
    {
        if(dd.getMonth()>m_iMonth)
        {
            return 1;
        }
        else if(dd.getMonth()<m_iMonth)
        {
            return -1;
        }
        else
        {
           if(dd.getDay()>m_iDay)
            {
                return 1;
            }
            else if(dd.getMonth()<m_iMonth)
            {
                return -1;
            }
            else
            {
                return 0;
            }
        }
    }
}

//IsValid
bool Date::isValid()
{
    //checking correct year
    if(m_iYear>=1979 && m_iYear<=2030)
    {
        //checking correct month/day combination
        if(m_iMonth==1||m_iMonth==3||m_iMonth==5||m_iMonth==7||m_iMonth==8||m_iMonth==10||m_iMonth==12)
        {
            //checking correct day
            if(m_iDay<=31 && m_iDay>=1)
            {
                return true;
            }
            else{return false;}
        }
        else if(m_iMonth==4||m_iMonth==6||m_iMonth==9||m_iMonth==11)
        {
            //checking correct day
            if(m_iDay<=30 && m_iDay>=1)
            {
                return true;
            }
            else{return false;}
        }
        else if(m_iMonth==2)
        {
            //checking correct day
            if(m_iDay<=28 && m_iDay>=1)
            {
                return true;
            }
            else{return false;}
        }
        else{return false;}
    }
    else{return false;}
}
