#include "Chateau.h"

using namespace std;

    //constructeur
    Chateau::Chateau()
    {
        Couleur="vert";
    }


    //accesseur
    string Chateau::getCouleur()
    {
        return Couleur;
    }

    //Methodes
    // f°creation des piles
    stack <Chateau> Chateau::initStackChateau()
    {
        Chateau castle = Chateau();
        stack<Chateau> StackCastle;
        for(int i=0;i<14;i++){
            StackCastle.push(castle);
            }
        return StackCastle;
    }

