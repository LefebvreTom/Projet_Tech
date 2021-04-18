#ifndef PLATEAUCENTRAL_H
#define PLATEAUCENTRAL_H

#include "Plateau.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <sstream>





class PlateauCentral : public Plateau
{

public:
    //constructeur
        PlateauCentral();

    //destructeur
       ~PlateauCentral();

    //methode
       void recupPlateau();
       std::string getTuileMarche(int i);
       int recupJoueur(int id);

protected:
    //tableau des references au id_site des tuiles posées sur le plateau commun
    std::string listeTuileCentrale [7];
    int premierajouer;
    int deuxiemeajouer;


};




#endif

