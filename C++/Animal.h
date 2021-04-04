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

        //constructeur utile
        Animal(int idRace, int Nb);

        //celui pour le marche noir
        Animal(int idRace, int Nb,std::string noir);

    //destructeur
        ~Animal();

    //Méthodes
        int getNombre();
        std::stack <Animal> initStackAnimal(int idRace); //initialisation de la pile

    //Attributs
    protected :
        int Nombre;//nombre d'animaux sur la tuile


};


#endif



