#include "Bonus.h"

    using namespace std;

    //constructeur
    Bonus::Bonus(){
    }

    Bonus::Bonus(int idCouleur,string type)
    {
        Id = idCouleur;

        switch(idCouleur)
        {
        case 1:
            Couleur = "bleu";
            Type = type;
            //Id_Site = "m1";
            break;
        case 2:
            Couleur = "violet";
            Type = type;
            //Id_Site = "m2";
            break;
        case 3:
            Couleur = "rose";
            Type = type;
            //Id_Site = "m3";
            break;
        case 4:
            Couleur = "rouge";
            Type = type;
            //Id_Site = "m4";
            break;
        case 5:
            Couleur = "marron";
            Type = type;
            //Id_Site = "m5";
            break;
        case 6:
            Couleur = "jaune";
            Type = type;
            //Id_Site = "m6";
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
        cout<<"on push un bonus de couleur :"<<bonus.getCouleur()<<" et de type :"<<bonus.getType()<<endl;
        Bonus bonus2 = Bonus(idCouleur,"grand");
        StackBonus.push(bonus2);
        cout<<"on push un bonus de couleur :"<<bonus2.getCouleur()<<" et de type :"<<bonus2.getType()<<endl;
        return StackBonus;
    }





