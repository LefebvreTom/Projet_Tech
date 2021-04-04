#ifndef BONUS_H
#define BONUS_H
#include "Tuiles.h"

#include <string>
#include <stack>


class Bonus : public Tuiles{
    //Constructeur
    public :
        Bonus();
        //constructeur de la tuile bonus
        Bonus(int idCouleur,std::string type);

    //destructeur
        ~Bonus();

    //Méthodes
        std::stack <Bonus> initStackBonus(int idCouleur);//on cree la pile contenant une grande et une petite tuile bonus d'une couleur

    //Attributs
    protected :
};

#endif // BONUS_H

