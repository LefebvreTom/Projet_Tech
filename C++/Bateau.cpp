#include "Bateau.h"

using namespace std;

    //constructeur
    Bateau::Bateau()
    {
        Couleur="bleu";
        Id_Site="ts";
    }

    //destructeur
    Bateau::~Bateau(){}

    //accesseur

    //Methodes
    // f°creation des piles
    stack <Bateau> Bateau::initStackBateau()
    {
        Bateau boat = Bateau();
        stack<Bateau> StackBateau;
        for(int i=0;i<20;i++){
            StackBateau.push(boat);
            }
        return StackBateau;
    }


