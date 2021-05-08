#ifndef PLATEAUCENTRAL_H
#define PLATEAUCENTRAL_H

#include "Plateau.h"
#include "De.h"
#include "Initialisation.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <sstream>
#include <queue>





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
       int getPhase();
       int getTour();
       int getDeMarchandise();
       Initialisation getInit();
       std::string getMarchandiseTour();
       void setTuile(int i,int j,std::string chgt);
       void setPhase(int resultat);
       void setTour(int resultat);
       void setMarchandiseTour(std::string marchandiseTour);
       void addMarchandiseListeTuileCentrale(std::string tuile,int i);
       void addTuileListeTuileCentrale(std::string tuile,int i,int j);

protected:
    //tableau des references au id_site des tuiles posées sur le plateau commun
    std::string listeTuileCentrale [7][8]; // 7ligne (de 1 a de 6 et la 7e pour le marche noir) et chaque dé peut amener à 8 colonnes -> 6 marchandises et 2 tuiles (en mode 2 joueurs)
    std::queue<std::string> listeMarchandisesTours;
    int premierajouer;
    int deuxiemeajouer;
    int phase;
    int tour;
    De deMarchandise;
    Initialisation init;

};




#endif

