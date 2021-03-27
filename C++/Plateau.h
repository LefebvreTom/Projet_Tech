
#ifndef PLATEAU_H
#define PLATEAU_H

#include <iostream>
#include <stdlib.h>
#include <string>


class Plateau{

public:
        virtual ~Plateau()=0;
        std::string getType();
        int getIdJoueur();
        std::string getIdSite();

protected:
        std::string Type;
        int Id_Joueur;
        std::string Id_Site;

};




#endif
