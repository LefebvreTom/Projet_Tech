#ifndef AFFICHAGETEST_H
#define AFFICHAGETEST_H

#include <iostream>
#include <string>
#include <stack>

#include "Marchandise.h"
#include "De.h"


class AffichageTest
{
    //Constructeur
    public :
        AffichageTest();

    //Méthodes
    void AffichageMarch(Marchandise march);
    void AffichageDe(De de);
    void AffichagePile(std::stack<Marchandise> Stack);

    //Attributs
    protected :


};

#endif
