#ifndef SIMULATEUR_H
#define SIMULATEUR_H

#include "PlateauJoueur.h"
#include "PlateauCentral.h"
#include "Partie.h"
#include "De.h"

#include<stdio.h>
#include<string>
#include <random>

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
    bool testVenteMarchandise(PlateauJoueur joueur, int de, PlateauCentral marche);
    bool testPepite(PlateauJoueur joueur,PlateauCentral marche,int pepite);
    void testPosage(PlateauJoueur joueur,int de1, int de2);
    void testAchat(PlateauCentral marche,int de1, int de2);
    bool testReserveVide(PlateauJoueur joueur);
    bool testPosageTuile(PlateauJoueur joueur, int de, int choixTuile, int choixCase);
    void finDeTour(PlateauCentral &marche,PlateauJoueur &J1,PlateauJoueur &J2);

    PlateauJoueur copieJoueur(PlateauJoueur joueur);
    PlateauCentral copieMarche(PlateauCentral marche);

    bool achatPepite(PlateauJoueur &joueur,PlateauCentral &marche,int choix);
    bool testAchatPepite(PlateauJoueur joueur,PlateauCentral marche,int choix);
    bool utilisationOuvrier(PlateauJoueur &joueur,int de,int nbr,bool chgt);
    bool venteDe(PlateauJoueur &joueur,int choix);
    bool venteMarchandise(PlateauJoueur &joueur, int choix);
	bool achatTuile(PlateauJoueur &joueur,PlateauCentral &marche,int choixDe,int choix);
	bool posageTuile(PlateauJoueur &joueur,int choixDe,int choixTuile,int choixCase);
	
	void actionBateau(PlateauJoueur &joueur,PlateauCentral &marche,int choixZone);
    void actionPension(PlateauJoueur &joueur);
    void actionBanque(PlateauJoueur &joueur);
    void actionEntrepot(PlateauJoueur &joueur,int choixVente);
    void actionMine(PlateauJoueur &joueur);

    //attribut
    protected :
        Initialisation init;
    //int tour
    //int manche
    //le joueur
};


#endif
