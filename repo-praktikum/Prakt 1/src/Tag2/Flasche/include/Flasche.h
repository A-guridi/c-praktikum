#ifndef FLASCHE_H
#define FLASCHE_H

#include<string>

class Flasche
{
    public:
        Flasche();
        Flasche(double dVolumen, std::string sMaterial);
        virtual ~Flasche();
        double getVolumen();
        std::string getMaterial();
        bool setVolumen(double dVolInput);
        bool setMaterial(std::string sMaterialInput);
        void printFlasche();
        void adoptFlasche(double dVolInput, std::string sMaterialInput);

    private:
        double m_dVolumen;
        std::string m_sMaterial;
};
#endif // FLASCHE_H
