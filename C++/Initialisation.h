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
#include <typeinfo>

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
        Chateau getChateau();
        Bateau getBateau();
        Mine getMine();
        Connaissance getConnaissance();
        Batiment getBatiment();
        Animal getAnimal();
        std::string getDosNoir();
        Marchandise getMarchandise();

        //methode pour vider le vecteur du marche noir
        void ClearMarcheNoir();

        //
        //PlateauJoueur getJoueur(int id);
        //void setJoueur(int id, PlateauJoueur joueur);

    //Attributs
    protected :
        std::stack <Marchandise> TabMarchandise[6];
        std::stack <Batiment> TabBatiment[8];
        std::stack <Animal> TabAnimal[4];
        std::stack <Bonus> TabBonus[6];
        std::stack <Chateau> TabChateau;
        std::stack <Bateau> TabBateau;
        std::stack <Mine> TabMine;
        AffichageTest affichetest;
        std::stack <Connaissance> TabConnaissance;
        DosNoir dosNoir;
        std::vector<Tuiles*> MarcheNoir;


};

#endif


