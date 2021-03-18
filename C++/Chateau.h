#ifndef CHATEAU_H
#define CHATEAU_H

#include <stdlib.h>
#include <string>
#include <stack>

class Chateau
{
    //Constructeur
    public :
        Chateau();
    //Destructeur


    //Méthodes
    public :
        std::string getCouleur();
        std::stack <Chateau> initStackChateau();

    //Attributs
    protected :
        std::string Couleur;

};

#endif
