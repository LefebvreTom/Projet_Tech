#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <stack>

#include <sstream>

#include "Tuiles.h"

class Animal : public Tuiles
{
    //Constructeur
    public :
        Animal();
        Animal(int idRace, int Nb);
    //destructeur
        ~Animal();

    //Méthodes
        int getNombre();
        std::stack <Animal> initStackAnimal(int idRace);

    //Attributs
    protected :
        int Nombre;


};


#endif



