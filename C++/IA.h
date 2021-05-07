#ifndef IA_H_INCLUDED
#define IA_H_INCLUDED

#include "PlateauJoueur.h"
#include "PlateauCentral.h"
#include "Partie.h"
#include "Simulateur.h"
#include "Noeud.h"

#include<stdio.h>
#include<string>
#include <random>
#include <iostream>

#include <cstdlib>
#include <stdlib.h>
#include <sstream>

class IA
{
public :
        IA();

        ~IA();

        void Monte_Carlo();
        std::vector<std::string> createListeTourPossible(int id);
        void jouerCoup(PlateauJoueur &j,PlateauCentral &m,std::string coup);
        int simulationNFindeTour(int id, Partie configFils);
        int modifValeurDe(int de);
        std::vector<std::string> vecteurBranche(int id);
        std::vector<Noeud> createListeSuccesseur(std::vector<std::string> tour,PlateauJoueur joueur,int id,PlateauCentral marche);


protected :
    Partie partie;
    Simulateur simulateur;
};
#endif // IA_H_INCLUDED
