
#ifndef PLATEAU_H
#define PLATEAU_H

#include <iostream>
#include <stdlib.h>
#include <string>


class Plateau{

//classe mere abstraite
public:
    //destructeur virtuel pure
        virtual ~Plateau()=0;

        std::string getType();
        int getId();
        std::string getIdSite();

protected:
    //type definie si cest un plateau de joueur ou le commun
        std::string Type;

        //id du joueur
        int Id;

        //id present sur le site
        std::string Id_Site;

};




#endif
