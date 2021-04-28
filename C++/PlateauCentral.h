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
       std::string getTuileMarche(int i,int j);
       int recupJoueur(int id);

protected:
    //tableau des references au id_site des tuiles posées sur le plateau commun
    std::string listeTuileCentrale [7][6]; // 7ligne (de 1 a de 6 et la 7e pour le marche noir) et chaque dé peut amener à 6 colonnes -> 4 marchandises et 2 tuiles (en mode 2 joueurs)
    int premierajouer;
    int deuxiemeajouer;


};




#endif

