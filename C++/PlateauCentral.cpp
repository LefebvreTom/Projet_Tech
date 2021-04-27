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
                        //cout<<ligne<<endl;
                    }

                }

                if(ligne.compare("pions:")==0){
                    getline(monFlux, ligne);
                    //cout<<ligne<<endl;
                    istringstream iss( ligne );
                    string morceau;
                    int test=0;
                    while (getline(iss, morceau, ',' ) )//on decoupe les lignes du doc
                    {
                        if(test==2)//on veut recuperer que le 3eme morceau pour avoir le joueur
                        {
                            string resultat;
                            morceau.erase(0,3);
                            morceau.erase(morceau.size()-2,2);
                            resultat=morceau;
                            if(resultat.compare("0")==0){
                                premierajouer=1;
                                deuxiemeajouer=2;
                            }
                            else{
                                premierajouer=2;
                                deuxiemeajouer=1;
                            }
                            //cout<<resultat<<endl;
                            //cout<<"1er joueur: "<<premierajouer<<endl;
                            //cout<<"2eme joueur: "<<deuxiemeajouer<<endl;

                        }
                        test=test+1;
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

    int PlateauCentral::recupJoueur(int i){
        int Joueur;
        if(i==1){
            Joueur=premierajouer;
        }
        else{
            Joueur=deuxiemeajouer;
        }
        return Joueur;
    }

    string PlateauCentral::getTuileMarche(int i){
        string tuile=listeTuileCentrale[i];
        return tuile;
    }
