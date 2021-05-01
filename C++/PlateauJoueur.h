#ifndef PLATEAUJOUEUR_H
#define PLATEAUJOUEUR_H

#include "Plateau.h"
#include "Case.h"
#include "Marchandise.h"

#include <iostream>
#include <stdlib.h>
#include <string>


#include <vector>


class PlateauJoueur : public Plateau
{

public:
    //constructeur
        PlateauJoueur();
        PlateauJoueur(int idJoueur);

    //destructeur
       ~PlateauJoueur();

    //methode
        Case getCase(int id);
        int getde(int i);
        int getMarch(int i);
        int getNbMarch(int i);
        int getNbMarchVendu(int i);
        std::string getReserve(int i);
        int getPepite();
        int getOuvrier();
        int getScore();

        void setde(int i,int resultat);
        void setMarch(int i, int j,int resultat);
        void setVendu(int i, int resultat);
        void setReserve(int i,std::string resultat);
        void setCase(int i,Case resultat);
        void setPepite(int resultat);
        void setOuvrier(int resultat);
        void setScore(int resultat);




protected:
        int de1;
        int de2;
        int Ouvrier; //nbr d'ouvrier du joueur
        int Pepite; //nbr de pepite
        Case tabCase[37]; //son tableau representant son plateau
        std::string Reserve[3]; //reserve des tuiles non posé encore
        int tabMarch[3][2]; //reserve des marchandises non vendues (stocké comme ceci [0][0]=type de march,[0][1]=nbr de march)
        int tabVendu[6]; //ensembles des marchandises vendues (nbr de marchandises de type 1 = tabVendu[0]
        int score;


};




#endif
