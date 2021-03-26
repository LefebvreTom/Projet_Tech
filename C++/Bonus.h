#ifndef BONUS_H
#define BONUS_H
#include "Tuiles.h"

#include <string>
#include <stack>


class Bonus : public Tuiles{
    //Constructeur
    public :
        Bonus();
        Bonus(int idCouleur,std::string type);
    //destructeur
        ~Bonus();

    //Méthodes
        std::stack <Bonus> initStackBonus(int idCouleur);

    //Attributs
    protected :
};

#endif // BONUS_H

