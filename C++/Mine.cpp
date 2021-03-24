
#include "Mine.h"

using namespace std;

    //constructeur
    Mine::Mine()
    {
        Couleur="gris";
    }

    //destructeur
    Mine::~Mine(){}

    //accesseur

    //Methodes
    // f°creation des piles
    stack <Mine> Mine::initStackMine()
    {
        Mine mine = Mine();
        stack<Mine> StackMine;
        for(int i=0;i<10;i++){
            StackMine.push(mine);
            }
        return StackMine;
    }



