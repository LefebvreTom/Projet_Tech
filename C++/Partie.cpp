#include "Partie.h"

    using namespace std;

    //constructeur
    Partie::Partie(){
        J1 = PlateauJoueur(1);
        J2 = PlateauJoueur(2);
        marche = PlateauCentral();
        //recuperation du plateau marche
        marche.recupPlateau();

    }


    //methode
    void Partie::MajPlateauJoueur(string Joueur)
    {

        //recuperation de l'ensemble des donnees d'un joueur
        PlateauJoueur joueur;
        if(Joueur.compare("J1")==0)
        {
            joueur=J1;
        }
        if(Joueur.compare("J2")==0)
        {
            joueur=J2;
        }

        //PlateauJoueur joueur;
        //joueur=init.getJoueur(id);


        string fichier="../Donnes/";
        fichier+=Joueur;
        fichier+=".txt";
        cout<<fichier<<endl;


        char fichierChar[fichier.size() + 1];
        fichier.copy(fichierChar, fichier.size() + 1);
        fichierChar[fichier.size()] = '\0';


        ifstream monFlux2(fichierChar);  //Ouverture d'un fichier en lecture
        cout<<"fichier ouvert "<<endl;

        if(monFlux2)
        {
            //Tout est prêt pour la lecture.

            string ligne;

            while(getline(monFlux2, ligne)) //Tant qu'on n'est pas à la fin, on lit
            {

                //LES DES
                if(ligne.compare("de:")==0) //on lit le tableau du plateau commun et on cherche la partie pour les des
                {
                    for(int i=0;i<2;i++)//on travaille sur 2 lignes
                    {
                        getline(monFlux2, ligne);
                        istringstream iss( ligne );
                        string morceau;

                        int test=0;
                        while (getline(iss, morceau, ';' ) )//on decoupe les lignes du doc
                        {
                            if(test==1)//on veut recuperer que le 2eme morceau pour avoir la valeur du de
                            {
                                int resultat;
                                istringstream (morceau) >> resultat;
                                if(i==0)
                                {
                                    joueur.setde(1,resultat);

                                }
                                else{
                                    joueur.setde(2,resultat);
                                }

                            }
                            test=test+1;
                        }
                    }
                    //cout <<"de1 du joueur vaut:"<<joueur.getde(1)<<endl;
                    //cout <<"de2 du joueur vaut:"<<joueur.getde(2)<<endl;

                }
                //LES  PEPITES
                if(ligne.compare("pepite:")==0)
                {
                    //cout<<"test ligne pepite"<<endl;
                    getline(monFlux2, ligne);
                    istringstream iss( ligne );
                    int resultat;
                    iss >> resultat; //resultat = nbr de pepite
                    joueur.setPepite(resultat);

                    //cout<<ligne<<endl;

                }

                //LES MARCHANDISES
                if(ligne.compare("marchandise:")==0)
                {
                    //cout<<"test ligne march"<<endl;

                    int testNbMarch=0; //le test pour savoir si c'est la 1,2 ou 3e marchandises sur le plateau du joueur
                    while(ligne.compare("marchandise_vendu:")!=0)
                    {
                        getline(monFlux2, ligne);
                        istringstream iss( ligne );
                        string morceau;
                        int testmorceau=0;

                        if(ligne.compare("marchandise_vendu:")!=0){

                            while (getline(iss, morceau, ';' ) )
                            {
                                if(testmorceau==0)//on veut recuperer le 1er morceau pour avoir la valeur du de
                                {
                                    int resultat;
                                    istringstream (morceau) >> resultat; //resultat = num du de
                                    //cout<<"num du de :"<<resultat<<endl;
                                    joueur.setMarch(testNbMarch,0,resultat);

                                }
                                else //testmorceau =1 -> 2e morceau qui vaut le nombre de marchandise de ce type
                                {
                                    int resultat;
                                    istringstream (morceau) >> resultat; //resultat = nbr de marchandises
                                    //cout<<"nbr de marchandises :"<<resultat<<endl;
                                    joueur.setMarch(testNbMarch,1,resultat);
                                }
                                testmorceau=testmorceau+1;
                                //1er morceau = dé
                                //2eme morceau = le nombre
                            }
                            testNbMarch=testNbMarch+1;
                        }

                    }

                    //test d'acces au marchandises du joueurs
                    //cout<<"tabMarch[0] :"<<joueur.getMarch(0)<<" et nbr:"<<joueur.getNbMarch(0)<<endl;
                    //cout<<"tabMarch[1] :"<<joueur.getMarch(1)<<" et nbr:"<<joueur.getNbMarch(1)<<endl;
                    //cout<<"tabMarch[2] :"<<joueur.getMarch(2)<<" et nbr:"<<joueur.getNbMarch(2)<<endl;

                }

                //LES MARCHANDISES VENDUES
                if(ligne.compare("marchandise_vendu:")==0){
                    //cout<<"test ligne marchandises Vendues"<<endl;
                    while(ligne.compare("reserve:")!=0)
                    {
                        getline(monFlux2, ligne);
                        istringstream iss( ligne );
                        string morceau;
                        int testmorceau=0;

                        int idVendu;
                        int resultatVendu;

                        if(ligne.compare("reserve:")!=0){

                            while (getline(iss, morceau, ';' ) )
                            {
                                if(testmorceau==0)//on veut recuperer le 1er morceau pour avoir la valeur du de
                                {

                                    istringstream (morceau) >> idVendu; //resultat = num du de
                                    //cout<<"num du de :"<<idVendu<<endl;


                                }
                                else        //testmorceau =1 -> 2e morceau qui vaut le nombre de marchandise de ce type
                                {

                                    istringstream (morceau) >> resultatVendu; //resultat = nbr de marchandises
                                    //cout<<"nbr de marchandises :"<<resultatVendu<<endl;
                                    joueur.setVendu(idVendu-1,resultatVendu);

                                }
                                testmorceau=testmorceau+1;

                                //1er morceau = dé
                                //2eme morceau = le nombre
                            }

                        }


                    }
                     //test d'acces au marchandises Vendues du joueurs
                    //cout<<"tabVendu[0]= march1 :"<<joueur.getNbMarchVendu(0)<<endl;
                    //cout<<"tabVendu[1]= march2 :"<<joueur.getNbMarchVendu(1)<<endl;
                    //cout<<"tabVendu[2]= march3 :"<<joueur.getNbMarchVendu(2)<<endl;
                    //cout<<"tabVendu[3]= march4 :"<<joueur.getNbMarchVendu(3)<<endl;
                    //cout<<"tabVendu[4]= march5 :"<<joueur.getNbMarchVendu(4)<<endl;
                    //cout<<"tabVendu[5]= march6 :"<<joueur.getNbMarchVendu(5)<<endl;

                    //cout<<ligne<<endl;

                }

                //LA RESERVE
                if(ligne.compare("reserve:")==0){
                    //cout<<"test reserve"<<endl;
                    int testNbTuiles=0; //le test pour savoir si c'est la 1,2 ou 3e tuiles dans la reserve du joueur
                    while(ligne.compare("plateau:")!=0)
                    {
                        getline(monFlux2, ligne);
                        if(ligne.compare("plateau:")!=0){
                            joueur.setReserve(testNbTuiles,ligne);
                        }
                        testNbTuiles=testNbTuiles+1;
                    }

                //cout<<"Reserve[0] :"<<joueur.getReserve(0)<<endl;
                //cout<<"Reserve[1] :"<<joueur.getReserve(1)<<endl;
                //cout<<"Reserve[2] :"<<joueur.getReserve(2)<<endl;

                }

                //LE PLATEAU
                if(ligne.compare("plateau:")==0){
                    //cout<<"test plateau"<<endl;
                    for(int i=0;i<37;i++)//on travaille sur 37 lignes = 37 cases
                    {
                        getline(monFlux2, ligne);
                        istringstream iss( ligne );
                        string morceau;

                        int test=0;
                        while (getline(iss, morceau, ';' ) )//on decoupe les lignes du doc
                        {
                            if(test==1)//on veut recuperer que le 2eme morceau pour avoir la valeur du de ou la tuile
                            {

                                //cout<<"case du plateau:"<<morceau<<endl;
                                if(morceau.at(0)!='d'){
                                    //cout<<morceau<<endl;
                                    Case chgt = joueur.getCase(i);
                                    //cout<<"type :"<<morceau<<endl;
                                    chgt.setType(morceau);
                                    joueur.setCaseDisponible(i);
                                    joueur.setCase(i,chgt);

                                }


                            }
                            test=test+1;
                        }
                    }
                }

                //LES OUVRIERS
                if(ligne.compare("ouvrier:")==0){
                    //cout<<"test ligne ouvrier"<<endl;
                    getline(monFlux2, ligne);
                    istringstream iss( ligne );
                    int resultat;
                    iss >> resultat; //resultat = nbr d'ouvrier
                    joueur.setOuvrier(resultat);

                    //cout<<ligne<<endl;
                }

                //LE SCORE
                if(ligne.compare("score:")==0){
                    //cout<<"test ligne ouvrier"<<endl;
                    getline(monFlux2, ligne);
                    istringstream iss( ligne );
                    int resultat;
                    iss >> resultat; //resultat = nbr d'ouvrier
                    joueur.setScore(resultat);

                    //cout<<ligne<<endl;
                }





            }
            //on test des trucs du joueurs
            /*Case test =joueur.getCase(2);
            cout<<"case 3 (id:2) du plateau :"<<test.getnumDe()<<"/"<<test.getType()<<endl;
            test =joueur.getCase(10);
            cout<<"case 11 (id:10) du plateau :"<<test.getnumDe()<<"/"<<test.getType()<<endl;
            int test2=joueur.getPepite();
            cout<<"pepite du joueur:"<<test2<<endl;
            test2=joueur.getOuvrier();
            cout<<"ouvrier du joueur:"<<test2<<endl;*/

            //on modifie le joueur
            if(Joueur.compare("J1")==0)
            {
                J1=joueur;
            }
            if(Joueur.compare("J2")==0)
            {
                J2=joueur;
            }

            //init.setJoueur(id,joueur);

            //on ferme le fichier
            monFlux2.close();
            cout<<"fichier ferme"<<endl;
        }
        else
        {
            cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
        }
    }

    PlateauJoueur Partie::getJoueur(int id)
    {
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

    PlateauCentral Partie::getMarche()
    {
        return marche;
    }
    void Partie::updatePhaseTourMarche(PlateauCentral m){
        marche.setPhase(m.getPhase());
        marche.setTour(m.getTour());
    }
