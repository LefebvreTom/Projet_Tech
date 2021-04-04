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
        //constructeur utile
        Batiment(int idType);

        //celui du marche noir
        Batiment(int idType,std::string noir);

    //destructeur
        ~Batiment();

    //Méthodes
        std::stack <Batiment> initStackBatiment(int idType);//init de la pile de tuile d'un type de batiment

    //Attributs
    protected :


};


#endif


