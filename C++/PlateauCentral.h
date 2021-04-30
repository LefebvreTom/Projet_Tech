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
       void setTuile(int i,int j,std::string chgt);

protected:
    //tableau des references au id_site des tuiles posées sur le plateau commun
    std::string listeTuileCentrale [7][8]; // 7ligne (de 1 a de 6 et la 7e pour le marche noir) et chaque dé peut amener à 8 colonnes -> 6 marchandises et 2 tuiles (en mode 2 joueurs)
    int premierajouer;
    int deuxiemeajouer;


};




#endif

