#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <stack>


class Animal
{
    //Constructeur
    public :
        Animal();
        Animal(int idRace, int Nb);

    //Méthodes
        std::string getRace();
        int getIdRace();
        int getNombre();
        std::stack <Animal> initStackAnimal(int idRace);

    //Attributs
    protected :
        std::string Race;
        int Nombre;
        int id_Race;

};


#endif


