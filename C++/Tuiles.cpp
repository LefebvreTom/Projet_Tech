#include "Tuiles.h"

using namespace std;

    Tuiles::~Tuiles(){}

    string Tuiles::getCouleur()
    {
        return Couleur;
    }

    string Tuiles::getType()
    {
        return Type;
    }

    int Tuiles::getId()
    {
        return Id;
    }

    string Tuiles::getIdSite()
    {
        return Id_Site;
    }

    void Tuiles::setType(string type){
        Type=type;
    }

    void Tuiles::setCouleur(string couleur){
    }
