#ifndef SIMULATEUR_H
#define SIMULATEUR_H

#include "PlateauJoueur.h"
#include "PlateauCentral.h"
#include "Partie.h"

#include<stdio.h>
#include<string>

#include <cstdlib>
#include <stdlib.h>

class Simulateur
{
    //Constructeur
    public :
        Simulateur();
    //Destructeur

    //methode
    void jouer();
    void testVenteMarch(PlateauJoueur joueur, int de1, int de2);

    //attribut
    //int tour
    //int manche
    //le joueur
};


#endif
