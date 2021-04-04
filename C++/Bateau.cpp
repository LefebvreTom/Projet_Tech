#include "Bateau.h"

using namespace std;

    //constructeur
    Bateau::Bateau()
    {
        //tuiles normales
        Couleur="bleu";
        Id_Site="ts";
    }

    Bateau::Bateau(string noir)
    {
        //tuile du marche noir donc id different
        Couleur="bleu";
        Id_Site="tsb";
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
        //on cree une pile de 20 tuiles bateaux
        for(int i=0;i<20;i++){
            StackBateau.push(boat);
            }
        return StackBateau;
    }


