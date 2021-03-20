#include "Batiment.h"

    using namespace std;

    //constructeur
    Batiment::Batiment(){
    }

    Batiment::Batiment(int idType)
    {
        id_Type = idType;

        switch(idType)
        {
        case 1:
            Type = "eglise";
            break;
        case 2:
            Type = "banque";
            break;
        case 3:
            Type = "pension";
            break;
        case 4:
            Type = "entrepot";
            break;
        case 5:
            Type = "menuisier";
            break;
        case 6:
            Type = "marche";
            break;
        case 7:
            Type = "mairie";
            break;
        case 8:
            Type = "tour";
            break;

        default :
            break;


        }
    }

    //accesseurs

    std::string Batiment::getType()
    {
        return Type;
    }

    int Batiment::getIdType()
    {
        return id_Type;
    }


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





