#ifndef BATIMENT_H
#define BATIMENT_H

#include <string>
#include <stack>


class Batiment
{
    //Constructeur
    public :
        Batiment();
        Batiment(int idType);

    //Méthodes
        std::string getType();
        int getIdType();
        std::stack <Batiment> initStackBatiment(int idType);

    //Attributs
    protected :
        std::string Type;
        int id_Type;

};


#endif

