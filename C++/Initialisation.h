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
#include "DosNoir.h"
#include "Bonus.h"

#include <string>
#include <stack>
#include <vector>

class Initialisation
{
    //Constructeur
    public :
        Initialisation();
        Initialisation(int fin);
    //Destructeur


    //Méthodes
        void InitTabMarchandise();
        void InitTabBatiment();
        void InitTabAnimal();
        void InitPileChateau();
        void InitPileBateau();
        void InitPileMines();
        void InitPileConnaissance();
        void InitPileMarcheNoir();
        void InitTabBonus();
        void ClearMarcheNoir();
    //Attributs
    protected :
        std::stack <Marchandise> TabMarchandise[6];
        std::stack <Batiment> TabBatiment[8];
        std::stack <Animal> TabAnimal[4];
        std::stack <Bonus> TabBonus[6];
        Chateau StackChateau;
        Bateau StackBateau;
        Mine StackMine;
        AffichageTest affichetest;
        Connaissance StackConnaissance;
        DosNoir dosNoir;
        std::vector<Tuiles*> MarcheNoir;

};

#endif


