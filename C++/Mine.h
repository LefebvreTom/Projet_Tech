#ifndef MINE_H
#define MINE_H

#include <stdlib.h>
#include <string>
#include <stack>

class Mine
{
    //Constructeur
    public :
        Mine();
    //Destructeur


    //Méthodes
    public :
        std::string getCouleur();
        std::stack <Mine> initStackMine();

    //Attributs
    protected :
        std::string Couleur;

};

#endif
