#include "PlateauCentral.h"


using namespace std;

    //constructeur
    PlateauCentral::PlateauCentral(){}

    //destructeur
    PlateauCentral::~PlateauCentral(){}

    //methode

    void PlateauCentral::recupPlateau()
    {
        ifstream monFlux("../Donnes/marche.txt");  //Ouverture d'un fichier en lecture
        if(monFlux)
        {
            //Tout est prêt pour la lecture.
            cout<<"fichier ouvert"<<endl;

            string ligne;

            while(getline(monFlux, ligne)) //Tant qu'on n'est pas à la fin, on lit
              {
                if(ligne.compare("tuile_centrale:")==0) //on lit le tableau du plateau commun
                {
                    for(int i=0;i<7;i++)
                    {
                        getline(monFlux, ligne);
                        listeTuileCentrale[i]=ligne;
                        cout<<ligne<<endl;
                    }

                }
              }

            //affichage test
            //cout<<listeTuileCentrale[0]<<listeTuileCentrale[1]<<endl;
            //on ferme le fichier
            monFlux.close();
            cout<<"fichier ferme"<<endl;
        }
        else
        {
            cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
        }
    }
