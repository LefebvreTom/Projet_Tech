
#ifndef BATEAU_H
#define BATEAU_H

#include <stdlib.h>
#include <string>
#include <stack>

class Bateau
{
    //Constructeur
    public :
        Bateau();
    //Destructeur


    //Méthodes
    public :
        std::string getCouleur();
        std::stack <Bateau> initStackBateau();

    //Attributs
    protected :
        std::string Couleur;

};

#endif
