
#ifndef MINE_H
#define MINE_H

#include <stdlib.h>
#include <string>
#include <stack>

#include "Tuiles.h"

class Mine : public Tuiles
{
    //Constructeur
    public :
        Mine();
        Mine(std::string noir);
    //Destructeur
        ~Mine();

    //Méthodes
    public :
        std::stack <Mine> initStackMine();

    //Attributs
    protected :

};

#endif
