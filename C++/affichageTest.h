#ifndef AFFICHAGETEST_H
#define AFFICHAGETEST_H

#include <iostream>
#include <string>
#include <stack>

#include "Marchandise.h"
#include "Batiment.h"
#include "De.h"
#include "Chateau.h"
#include "Bateau.h"
#include "Mine.h"


class AffichageTest
{
    //Constructeur
    public :
        AffichageTest();

    //Méthodes
    void AffichageMarch(Marchandise march);
    void AffichageDe(De de);
    void AffichagePileMarch(std::stack<Marchandise> Stack);
    void AffichagePileBatiment(std::stack<Batiment> Stack);
    void AffichagePileChateau(std::stack<Chateau> Stack);
    void AffichagePileBateau(std::stack<Bateau> Stack);
    void AffichagePileMine(std::stack<Mine> Stack);



    //Attributs
    protected :


};

#endif
