#ifndef PLATEAUJOUEUR_H
#define PLATEAUJOUEUR_H

#include "Plateau.h"
#include "Case.h"
#include "Marchandise.h"

#include <iostream>
#include <stdlib.h>
#include <string>


class PlateauJoueur : public Plateau
{

public:
    //constructeur
        PlateauJoueur(int idJoueur);

    //destructeur
       ~PlateauJoueur();

    //methode
        Case getCase(int id);

protected:
        int Ouvrier; //nbr d'ouvrier du joueur
        int Pepite; //nbr de pepite
        Case tabCase[37]; //son tableau representant son plateau
        Case tabReserve[3]; //reserve des tuiles non posé encore
        Marchandise tabMarch[3]; //reserve des marchandises non vendues


};




#endif
