#include "Case.h"

using namespace std;

    //constructeur
    Case :: Case(){}

    Case ::Case(int id,int numDe,string type)
    {
        //on cree une case de plateau contenant son id de reperage, le numero du dé pour poser qqch dessus et sa couleur/sa tuile
        Id=id;
        NumeroDe=numDe;
        Type=type;
    }

    //destructeur
    Case :: ~Case(){}

    //accesseur
    int Case::getnumDe(){
        return NumeroDe;
    }

    string Case::getType(){
        return Type;
    }

    //setter
    void Case::setType(string tuile){
        NumeroDe=0;
        Type=tuile;
    }

    //Methodes

