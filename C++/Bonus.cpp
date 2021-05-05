#include "Bonus.h"

    using namespace std;

    //constructeur
    Bonus::Bonus(){
    }

    Bonus::Bonus(int idCouleur,string type)
    {
        Id = idCouleur;

        //on cree une tuile bonus servant lors de la completion d'un quartier entier
        //le type correspond a une tuile soit grande soit petite
        switch(idCouleur)
        {
        case 1:
            Couleur = "bleu";
            Type = type;

            break;
        case 2:
            Couleur = "violet";
            Type = type;

            break;
        case 3:
            Couleur = "rose";
            Type = type;

            break;
        case 4:
            Couleur = "rouge";
            Type = type;

            break;
        case 5:
            Couleur = "marron";
            Type = type;

            break;
        case 6:
            Couleur = "jaune";
            Type = type;

            break;
        default :
            break;


        }
    }

    //destructeur
    Bonus::~Bonus(){}

    //accesseurs


    //Methodes

    // f°creation des piles
    stack <Bonus> Bonus::initStackBonus(int idCouleur)
    {
        stack<Bonus> StackBonus;
        Bonus bonus = Bonus(idCouleur,"petit");
        StackBonus.push(bonus);
        //cout<<"on push un bonus de couleur :"<<bonus.getCouleur()<<" et de type :"<<bonus.getType()<<endl;
        Bonus bonus2 = Bonus(idCouleur,"grand");
        StackBonus.push(bonus2);
        //cout<<"on push un bonus de couleur :"<<bonus2.getCouleur()<<" et de type :"<<bonus2.getType()<<endl;
        return StackBonus;
    }





