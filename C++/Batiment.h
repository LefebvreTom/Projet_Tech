#ifndef BATIMENT_H
#define BATIMENT_H

#include <string>
#include <stack>

#include "Tuiles.h"


class Batiment : public Tuiles
{
    //Constructeur
    public :
        Batiment();
        Batiment(int idType);
    //destructeur
        ~Batiment();

    //Méthodes
        std::stack <Batiment> initStackBatiment(int idType);

    //Attributs
    protected :


};


#endif


