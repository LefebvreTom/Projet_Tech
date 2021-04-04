#include "Case.h"

using namespace std;

    //constructeur
    Case :: Case(){}

    Case ::Case(int id,int numDe,string couleur)
    {
        //on cree une case de plateau contenant son id de reperage, le numero du dé pour poser qqch dessus et sa couleur
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

