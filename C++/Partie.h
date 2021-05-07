#ifndef PARTIE_H
#define PARTIE_H

#include "Tuiles.h"
#include "affichageTest.h"
#include "Marchandise.h"
#include "Chateaux.h"
#include "Bateau.h"
#include "Mine.h"
#include "Batiment.h"
#include "Animal.h"
#include "Connaissance.h"
#include "DosNoir.h"
#include "Bonus.h"
#include "PlateauJoueur.h"
#include "PlateauCentral.h"
#include "Initialisation.h"

#include <string>
#include <stack>
#include <vector>

#include <sstream>
#include <iostream>


class Partie
{
    //Constructeur
    public :
        Partie();
        Partie(PlateauJoueur p1, PlateauJoueur p2, PlateauCentral c);

    //Destructeur

    //methode

        void MajPlateauJoueur(std::string Joueur);
        PlateauJoueur getJoueur(int id);
        PlateauCentral getMarche();
        void updatePhaseTourMarche(PlateauCentral marche);

    //attribut
    protected:
        std::ifstream monFlux2;
        PlateauCentral marche;
        PlateauJoueur J1 ;
        PlateauJoueur J2 ;

};

#endif

