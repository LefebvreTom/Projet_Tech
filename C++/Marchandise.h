
#ifndef MARCHANDISE_H
#define MARCHANDISE_H
#include "Tuiles.h"

#include <string>
#include <stack>


class Marchandise : public Tuiles{
    //Constructeur
    public :
        Marchandise();

        //constructeur d'une marchandise d'une couleur
        Marchandise(int idCouleur);

    //destructeur
        ~Marchandise();

    //Méthodes
        std::stack <Marchandise> initStackMarchandise(int idMarch);//initialisation d'une pile de marchandises d'une couleur

    //Attributs
    protected :
        int id_Couleur;
};

#endif // MATCHANDISE_H

