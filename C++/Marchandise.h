#ifndef MARCHANDISE_H
#define MARCHANDISE_H

#include <string>
#include <stack>


class Marchandise
{
    //Constructeur
    public :
        Marchandise();
        Marchandise(int idCouleur);

    //Méthodes
        std::string getCouleur();
        int getIdCouleur();
        std::stack <Marchandise> initStackMarchandise(int idMarch);

    //Attributs
    protected :
        std::string Couleur;
        int id_Couleur;




};


#endif // MATCHANDISE_H

