#include "Noeud.h"

Noeud::Noeud(PlateauJoueur p1, PlateauJoueur p2, PlateauCentral c){
        J1 = p1;
        J2 = p2;
        marche = c;
}
PlateauJoueur Noeud::getJoueur(int id){
    PlateauJoueur joueur;
        if(id==1){
            joueur=J1;
        }
        else
        {
            joueur=J2;
        }
        return joueur;
}
PlateauCentral Noeud::getMarche(){
    return marche;
}
void Noeud::setMarche(PlateauCentral m){
    marche=m;
}
void Noeud::setJoueur(PlateauJoueur joueur,int id){
    if(id == 1){
            J1=joueur;
        }
        if(id == 2){
            J2=joueur;
        }
}
