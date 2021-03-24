
#ifndef BATEAU_H
#define BATEAU_H

#include <stdlib.h>
#include <string>
#include <stack>

#include "Tuiles.h"

class Bateau : public Tuiles
{
    //Constructeur
    public :
        Bateau();
    //Destructeur
        ~Bateau();

    //Méthodes
    public :
        std::stack <Bateau> initStackBateau();

    //Attributs
    protected :

};

#endif

