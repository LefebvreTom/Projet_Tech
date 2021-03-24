
#ifndef MARCHANDISE_H
#define MARCHANDISE_H
#include "Tuiles.h"

#include <string>
#include <stack>


class Marchandise : public Tuiles{
    //Constructeur
    public :
        Marchandise();
        Marchandise(int idCouleur);
    //destructeur
        ~Marchandise();

    //Méthodes
        std::stack <Marchandise> initStackMarchandise(int idMarch);

    //Attributs
    protected :
        int id_Couleur;
};

#endif // MATCHANDISE_H

