#ifndef INPUTROUTINE_H
#define INPUTROUTINE_H

#include<string>


class InputRoutine
{
    public:
        InputRoutine();
        InputRoutine(std::string sInputMsg, std::string sErrorMsg);
        double RunInput(double dInput);
        std::string RunInput(std::string sInput);
        virtual ~InputRoutine();

    protected:

    private:
        std::string m_sInputMsg;
        std::string m_sErrorMsg;
};

#endif // INPUTROUTINE_H
