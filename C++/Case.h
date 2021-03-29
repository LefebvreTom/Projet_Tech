#ifndef CASE_H
#define CASE_H

#include <iostream>
#include <stdlib.h>
#include <string>



class Case
{

public:
    //constructeur
        Case();
        Case(int id,int numDe,std::string couleur);

    //destructeur
       ~Case();

    //methode
        int getnumDe();

protected:
        int Id;
        std::string Couleur;
        int NumeroDe;


};


#endif
