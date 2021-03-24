#ifndef INITIALISATION_H
#define INITIALISATION_H

#include "Tuiles.h"
#include "affichageTest.h"
#include "Marchandise.h"
#include "Chateaux.h"
#include "Bateau.h"
#include "Mine.h"
#include "Batiment.h"
#include "Animal.h"
#include "Connaissance.h"

#include <string>
#include <stack>

class Initialisation
{
    //Constructeur
    public :
        Initialisation();
    //Destructeur


    //Méthodes
        void InitTabMarchandise();
        void InitTabBatiment();
        void InitTabAnimal();
        void InitPileChateau();
        void InitPileBateau();
        void InitPileMines();
        void InitPileConnaissance();
    //Attributs
    protected :
        std::stack <Marchandise> TabMarchandise[6];
        std::stack <Batiment> TabBatiment[8];
        std::stack <Animal> TabAnimal[4];
        Chateau StackChateau;
        Bateau StackBateau;
        Mine StackMine;
        AffichageTest affichetest;
        Connaissance StackConnaissance;

};

#endif


