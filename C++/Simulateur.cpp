#include "Simulateur.h"

    using namespace std;

    //constructeur
    Simulateur::Simulateur(){
    }

    //methode
    void Simulateur::jouer()
    {

        //"clear de console"
        cout<<"--------------------------------------------------------------------------------"<<endl;
        cout<<endl;
        cout<<endl;

        system("python ../Python/login.py ");

        Partie partie;

        PlateauJoueur joueur1;
        PlateauJoueur joueur2;

        PlateauCentral marche;

        partie.MajPlateauJoueur("J1");
        partie.MajPlateauJoueur("J2");

        joueur1=partie.getJoueur(1);
        joueur2=partie.getJoueur(2);

        marche=partie.getMarche();




    }

