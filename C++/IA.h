#ifndef IA_H_INCLUDED
#define IA_H_INCLUDED

#include "PlateauJoueur.h"
#include "PlateauCentral.h"
#include "Partie.h"
#include "Simulateur.h"

#include<stdio.h>
#include<string>
#include <random>

#include <cstdlib>
#include <stdlib.h>
#include <sstream>

class IA
{
public :
        IA();

        ~IA();

        void Monte_Carlo();
        int simulationNFindeTour(int N, int id, Partie configFils);
        int modifValeurDe(int de);
        std::vector<std::string> vecteurBranche(int id);


protected :
    Partie partie;
    Simulateur simulateur;
};
#endif // IA_H_INCLUDED
