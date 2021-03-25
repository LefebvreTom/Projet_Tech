#ifndef DOSNOIR_H
#define DOSNOIR_H

#include <stdlib.h>
#include <string>
#include <stack>

#include "Tuiles.h"
#include "Marchandise.h"
#include "Chateaux.h"
#include "Bateau.h"
#include "Mine.h"
#include "Batiment.h"
#include "Animal.h"
#include "Connaissance.h"

#include <vector>



class DosNoir
{
    //Constructeur
    public :
        DosNoir();
    //Destructeur
        ~DosNoir();

    //Méthodes
    public :
        std::vector <Tuiles*> initStackDosNoir();

    //Attributs
    protected :

};

#endif


