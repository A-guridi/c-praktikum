#include <iostream>
#include <calculations.h>

using namespace std;

int main()
{
    calculations calc;

    std::cout<<"Fakultaet von 5"<<std::endl;
    std::cout<<calc.factorialIter(5);
    std:cout<<std::endl<<std::endl;

    std::cout<<"Fibonacci-Folge bis 15"<<std::endl;
    calc.fibonacci(15,1,1);

    return 0;
}
