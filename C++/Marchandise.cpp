
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
            Id_Site = "m1";
            break;
        case 2:
            Couleur = "violet";
            Id_Site = "m2";
            break;
        case 3:
            Couleur = "rose";
            Id_Site = "m3";
            break;
        case 4:
            Couleur = "rouge";
            Id_Site = "m4";
            break;
        case 5:
            Couleur = "marron";
            Id_Site = "m5";
            break;
        case 6:
            Couleur = "jaune";
            Id_Site = "m6";
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





