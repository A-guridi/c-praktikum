#include <iostream>
#include <string>
#include <Flasche.h>
#include <InputRoutine.h>

int main()
{
    //Input-Variablen
    double dInput;
    std::string sInput;

    //Erzeugen des Input-Routine-Objekts
    InputRoutine InputVolumen("Bitte Volumen eingeben","Eingabe falsch."), InputMaterial("Bitte Material eingeben", "Eingabe falsch.");

    //Erzeugen der beiden Flaschen-Objekte
    Flasche bottle1,bottle2;
    Flasche bottle3=Flasche(25,"Aluminium");

    //Ausgabe der Standardwerte
    std::cout<<"Initialwerte:"<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Flasche 1:"<<std::endl;
    bottle1.printFlasche();
    std::cout<<"Flasche 2:"<<std::endl;
    bottle2.printFlasche();
    std::cout<<"Flasche 3:"<<std::endl;
    bottle3.printFlasche();
    std::cout<<std::endl;

    //input-routine
    std::cout<<std::endl;
    while(bottle1.setVolumen(InputVolumen.RunInput(dInput))==false){}
    while(bottle1.setMaterial(InputMaterial.RunInput(sInput))==false){}
    while(bottle2.setVolumen(InputVolumen.RunInput(dInput))==false){}
    while(bottle2.setMaterial(InputMaterial.RunInput(sInput))==false){}

    //geänderte werte ausgeben
    std::cout<<std::endl;
    std::cout<<"Neue Werte"<<std::endl;
    bottle1.printFlasche();
    bottle2.printFlasche();

    //Flassche 1&2 angleichen
    bottle2.adoptFlasche(bottle1.getVolumen(),bottle1.getMaterial());

    //geänderte Werte ausgeben
    std::cout<<std::endl;
    std::cout<<"Neue Werte (adopt)"<<std::endl;
    bottle1.printFlasche();
    bottle2.printFlasche();

    return 0;
}
