#ifndef CALCULATIONS_H
#define CALCULATIONS_H


class calculations
{
    public:
        calculations();
        virtual ~calculations();
        unsigned int factorialIter(unsigned int iInput);
        unsigned int fibonacci(unsigned int uiZ, unsigned int uiN1, unsigned int uiN2);

    protected:

    private:
        unsigned int fibonacciIter(unsigned int uiZ, unsigned int uiN1, unsigned int uiN2);
};

#endif // CALCULATIONS_H
