
#ifndef CONNAISSANCE_H
#define CONNAISSANCE_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <stack>
#include "Tuiles.h"


class Connaissance : public Tuiles
{
    //Constructeur
    public :
        Connaissance();
        Connaissance(int idType);
    //destructeur
        ~Connaissance();

    //Méthodes
        std::stack <Connaissance> initStackConnaissance();

    //Attributs
    protected :

};


#endif



