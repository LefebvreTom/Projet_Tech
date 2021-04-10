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
#include "PlateauJoueur.h"
#include "PlateauCentral.h"

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

        //methodes permettant l'initialisation de chaque composantes du jeu en debut de partie
        void InitTabMarchandise();
        void InitTabBatiment();
        void InitTabAnimal();
        void InitPileChateau();
        void InitPileBateau();
        void InitPileMines();
        void InitPileConnaissance();
        void InitPileMarcheNoir();
        void InitTabBonus();

        //methode pour vider le vecteur du marche noir
        void ClearMarcheNoir();

        //
        PlateauJoueur getJoueur(int id);
        void setJoueur(int id, PlateauJoueur joueur);

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
        PlateauCentral marche;
        PlateauJoueur J1 ;
        PlateauJoueur J2 ;

};

#endif


