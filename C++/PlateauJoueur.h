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
        int Ouvrier;
        int Pepite;
        Case tabCase[37];
        Case tabReserve[3];
        Marchandise tabMarch[3];


};




#endif
