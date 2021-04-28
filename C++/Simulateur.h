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
    void testOuvrier(PlateauJoueur joueurcourant,int de1, int de2,bool de1vendu,bool de2vendu,PlateauCentral marche);
    void testVenteMarch(PlateauJoueur joueur, int de1, int de2,PlateauCentral marche);
    void testPepite(PlateauJoueur joueur,PlateauCentral marche,int pepite);
    void testPosage(PlateauJoueur joueur,int de1, int de2);
    void testAchat(PlateauCentral marche,int de1, int de2);

    //attribut
    //int tour
    //int manche
    //le joueur
};


#endif
