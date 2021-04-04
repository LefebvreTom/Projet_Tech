
#ifndef AFFICHAGETEST_H
#define AFFICHAGETEST_H

#include <iostream>
#include <string>
#include <stack>

#include "Tuiles.h"
#include "Marchandise.h"
#include "Batiment.h"
#include "Animal.h"
#include "De.h"
#include "Chateaux.h"
#include "Bateau.h"
#include "Mine.h"


class AffichageTest
{
    //Constructeur
    public :
        AffichageTest();

    //Méthodes

    //methodes appellees pour verifier les piles, tableaux etc
    void AffichageMarch(Marchandise march);
    void AffichageDe(De de);
    void AffichagePileMarch(std::stack<Marchandise> Stack);
    void AffichagePileBatiment(std::stack<Batiment> Stack);
    void AffichagePileAnimal(std::stack<Animal> Stack);
    void AffichagePileChateau(std::stack<Chateau> Stack);
    void AffichagePileBateau(std::stack<Bateau> Stack);
    void AffichagePileMine(std::stack<Mine> Stack);


    //Attributs
    protected :


};

#endif
