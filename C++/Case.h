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
        int getnumDe();//methode pour recuperer le numero du dé necessaire pour poser une tuile sur cette case

protected:
        int Id;//id de la case
        std::string Couleur;//sa couleur
        int NumeroDe;//le numero du de associe


};


#endif
