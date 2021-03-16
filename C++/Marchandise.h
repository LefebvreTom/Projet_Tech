#ifndef MATCHANDISE_H
#define MATCHANDISE_H

#include <string>


class Marchandise
{
    //Constructeur
public :
    Marchandise(int idCouleur);

    //Méthodes
    std::string getCouleur();
    int getIdCouleur();

    //Attributs
protected :
    std::string Couleur;
    int id_Couleur;




};


#endif // MATCHANDISE_H

