
#include "Marchandise.h"

    using namespace std;

    //constructeur
    Marchandise::Marchandise(){
    }

    Marchandise::Marchandise(int idCouleur)
    {
        Id = idCouleur;

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

    //destructeur
    Marchandise::~Marchandise(){}

    //accesseurs


    //Methodes

    // f°creation des piles
    stack <Marchandise> Marchandise::initStackMarchandise(int idMarch)
    {
        Marchandise march = Marchandise(idMarch);
        stack<Marchandise> StackMarch;
        for(int i=0;i<7;i++){
            StackMarch.push(march);
            }
        return StackMarch;
    }





