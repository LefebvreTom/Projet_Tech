
#ifndef CONNAISSANCE_H
#define CONNAISSANCE_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <stack>


class Connaissance
{
    //Constructeur
    public :
        Connaissance();
        Connaissance(int idType);

    //Méthodes
        std::string getType();
        int getIdType();
        std::stack <Connaissance> initStackConnaissance();

    //Attributs
    protected :
        std::string Type;
        int id_Type;

};


#endif


