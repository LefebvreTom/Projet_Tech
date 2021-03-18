#include "Mine.h"

using namespace std;

    //constructeur
    Mine::Mine()
    {
        Couleur="gris";
    }


    //accesseur
    string Mine::getCouleur()
    {
        return Couleur;
    }

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



