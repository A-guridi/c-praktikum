#ifndef SQUARE_H
#define SQUARE_H


class square
{
    public:
        square();
        square(int iLength);
        square(const square& riSq);
        virtual ~square();
        int getLength() const;
        int getScope() const;
        int getSurf() const;

    protected:

    private:
        int m_iLength;
};

#endif // SQUARE_H
