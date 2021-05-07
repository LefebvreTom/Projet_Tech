#ifndef NOEUD_H_INCLUDED
#define NOEUD_H_INCLUDED

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
#include "Initialisation.h"

#include <string>
#include <stack>
#include <vector>

#include <sstream>
#include <iostream>
class Noeud
{
    public:
        Noeud(PlateauJoueur J1,PlateauJoueur J2,PlateauCentral marche);
        PlateauJoueur getJoueur(int id);
        PlateauCentral getMarche();
        void setMarche(PlateauCentral m);
        void setJoueur(PlateauJoueur joueur,int id);
    protected:
        PlateauCentral marche;
        PlateauJoueur J1 ;
        PlateauJoueur J2 ;
};

#endif // NOEUD_H_INCLUDED
