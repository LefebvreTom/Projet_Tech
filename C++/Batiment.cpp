
#include "Batiment.h"

    using namespace std;

    //constructeur
    Batiment::Batiment(){
    }

    Batiment::Batiment(int idType)
    {
        Id = idType;

        switch(idType)
        {
        case 1:
            Type = "eglise";
            Id_Site="tb3";
            break;
        case 2:
            Type = "banque";
            Id_Site="tb6";
            break;
        case 3:
            Type = "pension";
            Id_Site="tb5";
            break;
        case 4:
            Type = "entrepot";
            Id_Site="tb1";
            break;
        case 5:
            Type = "menuisier";
            Id_Site="tb2";
            break;
        case 6:
            Type = "marche";
            Id_Site="tb4";
            break;
        case 7:
            Type = "mairie";
            Id_Site="tb7";
            break;
        case 8:
            Type = "tour";
            Id_Site="tb8";
            break;

        default :
            break;


        }
    }

    //destructeur
    Batiment::~Batiment(){}

    //accesseurs

    //Methodes

    // f°creation des piles
    stack <Batiment> Batiment::initStackBatiment(int idType)
    {
        Batiment bat = Batiment(idType);
        stack<Batiment> StackBat;
        for(int i=0;i<5;i++){
            StackBat.push(bat);
            }
        return StackBat;
    }





