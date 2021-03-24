#ifndef CHATEAUX_H
#define CHATEAUX_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <stack>

#include "Tuiles.h"

class Chateau : public Tuiles{
public:
    //Constructeur
    public :
        Chateau();
    //destructeur
        ~Chateau();
    //methode
        std::stack <Chateau> initStackChateau();

    protected:

};

#endif
