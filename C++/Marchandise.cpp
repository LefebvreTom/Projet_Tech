#include "Marchandise.h"

using namespace std;

Marchandise::Marchandise(int idCouleur)
{
    id_Couleur = idCouleur;

    switch(idCouleur)
    {
    case 1:
        Couleur = "bleu";
        break;
    case 2:
        Couleur = "violet";
        break;
    case 3:
        Couleur = "rose";
        break;
    case 4:
        Couleur = "rouge";
        break;
    case 5:
        Couleur = "marron";
        break;
    case 6:
        Couleur = "jaune";
        break;
    default :
        break;


    }
}

    std::string Marchandise::getCouleur()
    {
        return Couleur;
    }

    int Marchandise::getIdCouleur()
    {
        return id_Couleur;
    }



