#include "PlateauJoueur.h"

using namespace std;

    //constructeur

    PlateauJoueur::PlateauJoueur(){}

    PlateauJoueur ::PlateauJoueur(int idJoueur)
    {
        Id=idJoueur;
        Type = "joueur";

        //on remplie les cases du tableaux avec les cases definit du plateau d'un joueur (voir image)
        //Case(id de la case, numero du dé pour poser la tuile sur la case, couleur de la case)
        tabCase[0] = Case(0,6,"bleu");
        tabCase[1] = Case(1,2,"marron");
        tabCase[2] = Case(2,6,"marron");
        tabCase[3] = Case(3,3,"gris");
        tabCase[4] = Case(4,5,"vert");
        tabCase[5] = Case(5,1,"bleu");
        tabCase[6] = Case(6,5,"marron");
        tabCase[7] = Case(7,1,"gris");
        tabCase[8] = Case(8,4,"jaune");
        tabCase[9] = Case(9,2,"vert");
        tabCase[10] = Case(10,4,"vert");
        tabCase[11] = Case(11,2,"bleu");
        tabCase[12] = Case(12,4,"gris");
        tabCase[13] = Case(13,2,"jaune");
        tabCase[14] = Case(14,1,"jaune");
        tabCase[15] = Case(15,6,"vert");
        tabCase[16] = Case(16,1,"vert");
        tabCase[17] = Case(17,3,"marron");
        tabCase[18] = Case(18,6,"vert");
        tabCase[19] = Case(19,3,"marron");
        tabCase[20] = Case(20,5,"marron");
        tabCase[21] = Case(21,3,"marron");
        tabCase[22] = Case(22,5,"vert");
        tabCase[23] = Case(23,6,"vert");
        tabCase[24] = Case(24,1,"jaune");
        tabCase[25] = Case(25,5,"bleu");
        tabCase[26] = Case(26,1,"marron");
        tabCase[27] = Case(27,6,"marron");
        tabCase[28] = Case(28,4,"vert");
        tabCase[29] = Case(29,5,"jaune");
        tabCase[30] = Case(30,2,"marron");
        tabCase[31] = Case(31,4,"bleu");
        tabCase[32] = Case(32,2,"vert");
        tabCase[33] = Case(33,3,"jaune");
        tabCase[34] = Case(34,4,"marron");
        tabCase[35] = Case(35,3,"marron");
        tabCase[36] = Case(36,1,"bleu");

        //création du tableau de marchandises du joueur et de la reserve
        for(int i=0;i<3;i++){
            tabMarch[i][0]=0;
            tabMarch[i][1]=0;
            Reserve[i]="";

        }



        //tableau de marchandises vendues
        for(int i=0;i<6;i++){
            tabVendu[i]=0;
        }


    }

    //destructeur
    PlateauJoueur :: ~PlateauJoueur(){}

    //accesseur
    Case PlateauJoueur::getCase(int id){
        return tabCase[id];
    }


    int PlateauJoueur::getde(int i){
        int resultat;
        if (i==1){
           resultat=de1;
        }
        if (i==2){
           resultat=de2;
        }
        return resultat;
    }

    int PlateauJoueur::getMarch(int i){
        return tabMarch[i][0];
    }

    int PlateauJoueur::getNbMarch(int i){
        return tabMarch[i][1];
    }


    int PlateauJoueur::getNbMarchVendu(int i){
        return tabVendu[i];
    }

    string PlateauJoueur::getReserve(int i){
        return Reserve[i];
    }

    int PlateauJoueur::getPepite(){
        return Pepite;
    }

    int PlateauJoueur::getOuvrier(){
        return Ouvrier;
    }


    //setter

    void PlateauJoueur::setde(int i,int resultat){
        if (i==1){
           de1=resultat;
        }
        if (i==2){
           de2=resultat;
        }
    }

    void PlateauJoueur::setMarch(int i,int j,int resultat){
        tabMarch[i][j]=resultat;
    }

    void PlateauJoueur::setVendu(int i,int resultat){
        tabVendu[i]=resultat;
    }

    void PlateauJoueur::setReserve(int i,string resultat){
        Reserve[i]=resultat;
    }

    void PlateauJoueur::setCase(int i,Case resultat){
        tabCase[i]=resultat;
    }

    void PlateauJoueur::setPepite(int resultat){
        Pepite=resultat;
    }

    void PlateauJoueur::setOuvrier(int resultat){
        Ouvrier=resultat;
    }


