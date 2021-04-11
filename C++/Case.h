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
        Case(int id,int numDe,std::string type);

    //destructeur
       ~Case();

    //methode
        int getnumDe();//methode pour recuperer le numero du dé necessaire pour poser une tuile sur cette case
        std::string getType();
        void setType(std::string tuile);//change la couleur contenu dans le type de la case par le nom de la tuile sur le site

protected:
        int Id;//id de la case
        std::string Type;//sa couleur ou la tuile posé dessus
        int NumeroDe;//le numero du de associe


};


#endif
