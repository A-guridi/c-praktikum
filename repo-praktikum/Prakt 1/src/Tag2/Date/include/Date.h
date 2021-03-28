#ifndef DATE_H
#define DATE_H


class Date
{
    public:
        Date();
        Date(int day, int month, int year);
        virtual ~Date();
        bool isEqual(Date dd);
        bool isValid();
        int compare(Date dd);
        int getDay();
        int getMonth();
        int getYear();
        /*
        void SetDay(int iDay);
        void SetMonth(int iMonth);
        void SetYear(int iYear);
        */

    protected:

    private:
        int m_iDay, m_iMonth, m_iYear;

};

#endif // DATE_H
