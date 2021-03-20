#ifndef INITIALISATION_H
#define INITIALISATION_H


#include "affichageTest.h"
#include "Marchandise.h"
#include "Chateau.h"
#include "Bateau.h"
#include "Mine.h"
#include "Batiment.h"
#include "Animal.h"

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
    //Attributs
    protected :
        std::stack <Marchandise> TabMarchandise[6];
        std::stack <Batiment> TabBatiment[8];
        std::stack <Animal> TabAnimal[4];
        Chateau StackChateau;
        Bateau StackBateau;
        Mine StackMine;
        AffichageTest affichetest;

};

#endif

