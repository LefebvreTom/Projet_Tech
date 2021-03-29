#include "Case.h"

using namespace std;

    //constructeur
    Case :: Case(){}

    Case ::Case(int id,int numDe,string couleur)
    {
        Id=id;
        NumeroDe=numDe;
        Couleur=couleur;
    }

    //destructeur
    Case :: ~Case(){}

    //accesseur
    int Case::getnumDe(){
        return NumeroDe;
    }

    //Methodes

