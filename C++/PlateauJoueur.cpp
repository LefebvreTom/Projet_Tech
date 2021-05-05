#include "PlateauJoueur.h"

using namespace std;

    //constructeur

    PlateauJoueur::PlateauJoueur(){}

    PlateauJoueur ::PlateauJoueur(int idJoueur)
    {
        Id=idJoueur;
        Type = "joueur";
        for (int i = 0; i < 37; ++i){
            tabIdCaseDisponible[i] = 0;
        }
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
        tabCase[18] = Case(18,6,"vert fonce");
        tabCase[19] = Case(19,3,"marron");
        tabCase[20] = Case(20,5,"marron");
        tabCase[21] = Case(21,3,"marron");
        tabCase[22] = Case(22,5,"vert fonce");
        tabCase[23] = Case(23,6,"vert fonce");
        tabCase[24] = Case(24,1,"jaune");
        tabCase[25] = Case(25,5,"bleu");
        tabCase[26] = Case(26,1,"marron");
        tabCase[27] = Case(27,6,"marron");
        tabCase[28] = Case(28,4,"vert fonce");
        tabCase[29] = Case(29,5,"jaune");
        tabCase[30] = Case(30,2,"marron");
        tabCase[31] = Case(31,4,"bleu");
        tabCase[32] = Case(32,2,"vert");
        tabCase[33] = Case(33,3,"jaune");
        tabCase[34] = Case(34,4,"marron");
        tabCase[35] = Case(35,3,"marron");
        tabCase[36] = Case(36,1,"bleu");

        district_batiment1[0] = Case(1,2,"marron");
        district_batiment1[1] = Case(2,6,"marron");
        district_batiment1[2] = Case(6,5,"marron");

        district_batiment2[0] = Case(17,3,"marron");

        district_batiment3[0] = Case(19,3,"marron");
        district_batiment3[1] = Case(20,5,"marron");
        district_batiment3[2] = Case(21,3,"marron");
        district_batiment3[3] = Case(26,1,"marron");
        district_batiment3[4] = Case(27,6,"marron");

        district_batiment4[0] = Case(30,2,"marron");
        district_batiment4[1] = Case(34,4,"marron");
        district_batiment4[2] = Case(35,3,"marron");

        district_bateaux1[0] = Case(0,6,"bleu");
        district_bateaux1[1] = Case(5,1,"bleu");
        district_bateaux1[2] = Case(11,2,"bleu");

        district_bateaux2[0] = Case(25,5,"bleu");
        district_bateaux2[1] = Case(31,4,"bleu");
        district_bateaux2[2] = Case(36,1,"bleu");

        district_connaissance1[0] = Case(8,4,"jaune");
        district_connaissance1[1] = Case(13,2,"jaune");
        district_connaissance1[2] = Case(14,1,"jaune");

        district_connaissance2[0] = Case(24,1,"jaune");
        district_connaissance2[1] = Case(29,5,"jaune");
        district_connaissance2[2] = Case(33,3,"jaune");

        district_animaux1[0] = Case(4,5,"vert");
        district_animaux1[1] = Case(9,2,"vert");
        district_animaux1[2] = Case(10,4,"vert");
        district_animaux1[3] = Case(15,6,"vert");
        district_animaux1[4] = Case(16,1,"vert");

        district_animaux2[0] = Case(32,2,"vert");

        district_mine[0] = Case(3,3,"gris");
        district_mine[1] = Case(7,1,"gris");
        district_mine[2] = Case(12,4,"gris");

        district_chateaux[0] = Case(22,5,"vert fonce");
        district_chateaux[1] = Case(23,6,"vert fonce");
        district_chateaux[2] = Case(28,4,"vert fonce");

        //création du tableau de marchandises du joueur et de la reserve
        for(int i=0;i<3;i++){
            tabMarch[i][0]=0;
            tabMarch[i][1]=0;
            Reserve[i]="";

        }

        score = 0;

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

    int PlateauJoueur::getScore(){
        return score;
    };

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
        //tabIdCaseDisponible[i]=1;
        switch(i) {

            case 1: case 2: case 6:
                if(i == 1) district_batiment1[0]=resultat;
                if(i == 2) district_batiment1[1]=resultat;
                if(i == 6) district_batiment1[2]=resultat;
            break;

            case 17:
                district_batiment2[0]=resultat;
            break;

            case 19: case 20: case 21: case 26: case 27:
                if(i == 19) district_batiment3[0]=resultat;
                if(i == 20) district_batiment3[1]=resultat;
                if(i == 21) district_batiment3[2]=resultat;
                if(i == 26) district_batiment3[3]=resultat;
                if(i == 27) district_batiment3[4]=resultat;
            break;

            case 30: case 34: case 35:
                if(i == 30) district_batiment4[0]=resultat;
                if(i == 34) district_batiment4[1]=resultat;
                if(i == 35) district_batiment4[2]=resultat;
            break;

            case 0: case 5: case 11:
                if(i == 0) district_bateaux1[0]=resultat;
                if(i == 5) district_bateaux1[1]=resultat;
                if(i == 11) district_bateaux1[2]=resultat;
            break;

            case 25: case 31: case 36:
                if(i == 25) district_bateaux2[0]=resultat;
                if(i == 31) district_bateaux2[1]=resultat;
                if(i == 36) district_bateaux2[2]=resultat;
            break;

            case 8: case 13: case 14:
                if(i == 8) district_connaissance1[0]=resultat;
                if(i == 13) district_connaissance1[1]=resultat;
                if(i == 14) district_connaissance1[2]=resultat;
            break;

            case 24: case 29: case 33:
                if(i == 24) district_connaissance2[0]=resultat;
                if(i == 29) district_connaissance2[1]=resultat;
                if(i == 33) district_connaissance2[2]=resultat;
            break;

            case 4: case 9: case 10: case 15: case 16:
                if(i == 4) district_animaux1[0]=resultat;
                if(i == 9) district_animaux1[1]=resultat;
                if(i == 10) district_animaux1[2]=resultat;
                if(i == 15) district_animaux1[3]=resultat;
                if(i == 16) district_animaux1[4]=resultat;
            break;

            case 32:
                district_animaux2[0]=resultat;
            break;

            case 3: case 7: case 12:
                if(i == 3) district_mine[0]=resultat;
                if(i == 7) district_mine[1]=resultat;
                if(i == 12) district_mine[2]=resultat;
            break;

            case 22: case 23: case 28:
                if(i == 22) district_chateaux[0]=resultat;
                if(i == 23) district_chateaux[1]=resultat;
                if(i == 28) district_chateaux[2]=resultat;
            break;
        }
    }

    void PlateauJoueur::setPepite(int resultat){
        Pepite=resultat;
    }

    void PlateauJoueur::setOuvrier(int resultat){
        Ouvrier=resultat;
    }

    void PlateauJoueur::setCaseDisponible(int resultat){
        tabIdCaseDisponible[resultat]=1;
    }

    void PlateauJoueur::setScore(int resultat){
        score=resultat;
    }
    void PlateauJoueur::afficheDispo(){
        for (int i = 0; i < 37; ++i){
            switch(tabIdCaseDisponible[i]){
            case 0:
            cout<<"Case : "<<i<<" disponible"<<endl;
            break;
            case 1:
            cout<<"Case : "<<i<<" pleine"<<endl;
            break;
            case -1:
            cout<<"Case : "<<i<<" indisponible"<<endl;
            break;
            }
        }
    }
    bool PlateauJoueur::updateCaseDisponible(int id){
        switch(id){
        case 0:
            if(tabIdCaseDisponible[1]||tabIdCaseDisponible[4]||tabIdCaseDisponible[5]){
                tabIdCaseDisponible[id]=1;
                return true;
            }
            return false;
        break;
        case 1:
            if(tabIdCaseDisponible[0]||tabIdCaseDisponible[2]||tabIdCaseDisponible[5]||tabIdCaseDisponible[6]){
                tabIdCaseDisponible[id]=1;
                return true;
            }
            return false;
        break;
        case 2:
            if(tabIdCaseDisponible[1]||tabIdCaseDisponible[3]||tabIdCaseDisponible[6]||tabIdCaseDisponible[7]){
                tabIdCaseDisponible[id]=1;
                return true;
            }
            return false;
            break;
        case 3:
            if(tabIdCaseDisponible[2]||tabIdCaseDisponible[7]||tabIdCaseDisponible[8]){
                tabIdCaseDisponible[id]=1;
                return true;
            }
            return false;
            break;
        case 4:
            if(tabIdCaseDisponible[0]||tabIdCaseDisponible[5]||tabIdCaseDisponible[9]||tabIdCaseDisponible[10]){
                tabIdCaseDisponible[id]=1;
                return true;
            }
            return false;
            break;
        case 5:
            if(tabIdCaseDisponible[0]||tabIdCaseDisponible[1]||tabIdCaseDisponible[4]||tabIdCaseDisponible[6]||tabIdCaseDisponible[10]||tabIdCaseDisponible[11]){
                tabIdCaseDisponible[id]=1;
                return true;
            }
            return false;
            break;
        case 6:
            if(tabIdCaseDisponible[1]||tabIdCaseDisponible[2]||tabIdCaseDisponible[5]||tabIdCaseDisponible[7]||tabIdCaseDisponible[11]||tabIdCaseDisponible[12]){
                tabIdCaseDisponible[id]=1;
                return true;
            }
            return false;
            break;
        case 7:
            if(tabIdCaseDisponible[2]||tabIdCaseDisponible[3]||tabIdCaseDisponible[6]||tabIdCaseDisponible[8]||tabIdCaseDisponible[12]||tabIdCaseDisponible[13]){
                tabIdCaseDisponible[id]=1;
                return true;
            }
            return false;
            break;
        case 8:
            if(tabIdCaseDisponible[3]||tabIdCaseDisponible[7]||tabIdCaseDisponible[13]||tabIdCaseDisponible[14]){
                tabIdCaseDisponible[id]=1;
                return true;
            }
            return false;
            break;
        case 9:
            if(tabIdCaseDisponible[4]||tabIdCaseDisponible[10]||tabIdCaseDisponible[15]||tabIdCaseDisponible[16]){
                tabIdCaseDisponible[id]=1;
                return true;
            }
            return false;
            break;
        case 10:
            if(tabIdCaseDisponible[4]||tabIdCaseDisponible[5]||tabIdCaseDisponible[9]||tabIdCaseDisponible[11]||tabIdCaseDisponible[16]||tabIdCaseDisponible[17]){
                tabIdCaseDisponible[id]=1;
                return true;
            }
            return false;
            break;
        case 11:
            if(tabIdCaseDisponible[5]||tabIdCaseDisponible[6]||tabIdCaseDisponible[10]||tabIdCaseDisponible[12]||tabIdCaseDisponible[17]||tabIdCaseDisponible[18]){
                tabIdCaseDisponible[id]=1;
                return true;
            }
            return false;
            break;
        case 12:
            if(tabIdCaseDisponible[6]||tabIdCaseDisponible[7]||tabIdCaseDisponible[11]||tabIdCaseDisponible[13]||tabIdCaseDisponible[18]||tabIdCaseDisponible[19]){
                tabIdCaseDisponible[id]=1;
                return true;
            }
            return false;
            break;
        case 13:
            if(tabIdCaseDisponible[7]||tabIdCaseDisponible[8]||tabIdCaseDisponible[12]||tabIdCaseDisponible[14]||tabIdCaseDisponible[19]||tabIdCaseDisponible[20]){
                tabIdCaseDisponible[id]=1;
                return true;
            }
            return false;
            break;
        case 14:
            if(tabIdCaseDisponible[8]||tabIdCaseDisponible[13]||tabIdCaseDisponible[20]||tabIdCaseDisponible[21]){
                tabIdCaseDisponible[id]=1;
                return true;
            }
            return false;
            break;
        case 15:
            if(tabIdCaseDisponible[9]||tabIdCaseDisponible[16]||tabIdCaseDisponible[22]){
                tabIdCaseDisponible[id]=1;
                return true;
            }
            return false;
            break;
        case 16:
            if(tabIdCaseDisponible[9]||tabIdCaseDisponible[10]||tabIdCaseDisponible[15]||tabIdCaseDisponible[17]||tabIdCaseDisponible[22]||tabIdCaseDisponible[23]){
                tabIdCaseDisponible[id]=1;
                return true;
            }
            return false;
            break;
        case 17:
            if(tabIdCaseDisponible[10]||tabIdCaseDisponible[11]||tabIdCaseDisponible[16]||tabIdCaseDisponible[18]||tabIdCaseDisponible[23]||tabIdCaseDisponible[24]){
                tabIdCaseDisponible[id]=1;
                return true;
            }
            return false;
            break;
        case 18:
            if(tabIdCaseDisponible[11]||tabIdCaseDisponible[12]||tabIdCaseDisponible[17]||tabIdCaseDisponible[19]||tabIdCaseDisponible[24]||tabIdCaseDisponible[25]){
                tabIdCaseDisponible[id]=1;
                return true;
            }
            return false;
            break;
        case 19:
            if(tabIdCaseDisponible[12]||tabIdCaseDisponible[13]||tabIdCaseDisponible[18]||tabIdCaseDisponible[20]||tabIdCaseDisponible[25]||tabIdCaseDisponible[26]){
                tabIdCaseDisponible[id]=1;
                return true;
            }
            return false;
            break;
        case 20:
            if(tabIdCaseDisponible[13]||tabIdCaseDisponible[14]||tabIdCaseDisponible[19]||tabIdCaseDisponible[21]||tabIdCaseDisponible[26]||tabIdCaseDisponible[27]){
                tabIdCaseDisponible[id]=1;
                return true;
            }
            return false;
            break;
        case 21:
            if(tabIdCaseDisponible[14]||tabIdCaseDisponible[20]||tabIdCaseDisponible[27]){
                tabIdCaseDisponible[id]=1;
                return true;
            }
            return false;
            break;
        case 22:
            if(tabIdCaseDisponible[15]||tabIdCaseDisponible[16]||tabIdCaseDisponible[23]||tabIdCaseDisponible[28]){
                tabIdCaseDisponible[id]=1;
                return true;
            }
            return false;
            break;
        case 23:
            if(tabIdCaseDisponible[16]||tabIdCaseDisponible[17]||tabIdCaseDisponible[22]||tabIdCaseDisponible[24]||tabIdCaseDisponible[28]||tabIdCaseDisponible[29]){
                tabIdCaseDisponible[id]=1;
                return true;
            }
            return false;
            break;
        case 24:
            if(tabIdCaseDisponible[17]||tabIdCaseDisponible[18]||tabIdCaseDisponible[23]||tabIdCaseDisponible[25]||tabIdCaseDisponible[29]||tabIdCaseDisponible[30]){
                tabIdCaseDisponible[id]=1;
                return true;
            }
            return false;
            break;
        case 25:
            if(tabIdCaseDisponible[18]||tabIdCaseDisponible[19]||tabIdCaseDisponible[24]||tabIdCaseDisponible[26]||tabIdCaseDisponible[30]||tabIdCaseDisponible[31]){
                tabIdCaseDisponible[id]=1;
                return true;
            }
            return false;
            break;
        case 26:
            if(tabIdCaseDisponible[19]||tabIdCaseDisponible[20]||tabIdCaseDisponible[25]||tabIdCaseDisponible[27]||tabIdCaseDisponible[31]||tabIdCaseDisponible[32]){
                tabIdCaseDisponible[id]=1;
                return true;
            }
            return false;
            break;
        case 27:
            if(tabIdCaseDisponible[20]||tabIdCaseDisponible[21]||tabIdCaseDisponible[26]||tabIdCaseDisponible[32]){
                tabIdCaseDisponible[id]=1;
                return true;
            }
            return false;
            break;
        case 28:
            if(tabIdCaseDisponible[22]||tabIdCaseDisponible[23]||tabIdCaseDisponible[29]||tabIdCaseDisponible[33]){
                tabIdCaseDisponible[id]=1;
                return true;
            }
            return false;
            break;
        case 29:
            if(tabIdCaseDisponible[23]||tabIdCaseDisponible[24]||tabIdCaseDisponible[28]||tabIdCaseDisponible[30]||tabIdCaseDisponible[33]||tabIdCaseDisponible[34]){
                tabIdCaseDisponible[id]=1;
                return true;
            }
            return false;
            break;
        case 30:
            if(tabIdCaseDisponible[24]||tabIdCaseDisponible[25]||tabIdCaseDisponible[29]||tabIdCaseDisponible[31]||tabIdCaseDisponible[34]||tabIdCaseDisponible[35]){
                tabIdCaseDisponible[id]=1;
                return true;
            }
            return false;
            break;
        case 31:
            if(tabIdCaseDisponible[25]||tabIdCaseDisponible[26]||tabIdCaseDisponible[30]||tabIdCaseDisponible[32]||tabIdCaseDisponible[35]||tabIdCaseDisponible[36]){
                tabIdCaseDisponible[id]=1;
                return true;
            }
            return false;
            break;
        case 32:
            if(tabIdCaseDisponible[26]||tabIdCaseDisponible[27]||tabIdCaseDisponible[31]||tabIdCaseDisponible[36]){
                tabIdCaseDisponible[id]=1;
                return true;
            }
            return false;
            break;
        case 33:
            if(tabIdCaseDisponible[28]||tabIdCaseDisponible[29]||tabIdCaseDisponible[34]){
                tabIdCaseDisponible[id]=1;
                return true;
            }
            return false;
            break;
        case 34:
            if(tabIdCaseDisponible[29]||tabIdCaseDisponible[30]||tabIdCaseDisponible[33]||tabIdCaseDisponible[35]){
                tabIdCaseDisponible[id]=1;
                return true;
            }
            return false;
            break;
        case 35:
            if(tabIdCaseDisponible[30]||tabIdCaseDisponible[31]||tabIdCaseDisponible[34]||tabIdCaseDisponible[36]){
                tabIdCaseDisponible[id]=1;
                return true;
            }
            return false;
            break;
        case 36:
            if(tabIdCaseDisponible[31]||tabIdCaseDisponible[32]||tabIdCaseDisponible[35]){
                tabIdCaseDisponible[id]=1;
                return true;
            }
            return false;
            break;
        }
    }

    /*void PlateauJoueur::printDistrict(){
        for(int i = 0; i < 5; i++){
                Case test =district_animaux1[i];
                cout<<test.getType()<<endl;
        }

    }*/
    bool PlateauJoueur::districtPlein(int id){
        switch(id) {

            case 1: case 2: case 6:
                for(int i = 0; i < 3; i++){
                    if(district_batiment1[i].getType().compare("marron") == 0) return false;
                }
                return true;
            break;

            case 17:
                if(district_batiment2[0].getType().compare("marron") == 0) return false;
                return true;

            break;

            case 19: case 20: case 21: case 26: case 27:
                for(int i = 0; i < 5; i++){
                    if(district_batiment3[i].getType().compare("marron") == 0) return false;
                }
                return true;
            break;

            case 30: case 34: case 35:
                for(int i = 0; i < 3; i++){
                    if(district_batiment4[i].getType().compare("marron") == 0) return false;
                }
                return true;
            break;

            case 0: case 5: case 11:
                for(int i = 0; i < 3; i++){
                    if(district_bateaux1[i].getType().compare("bleu") == 0) return false;
                }
                return true;
            break;

            case 25: case 31: case 36:
                for(int i = 0; i < 3; i++){
                    if(district_bateaux2[i].getType().compare("bleu") == 0) return false;
                }
                return true;
            break;

            case 8: case 13: case 14:
                for(int i = 0; i < 3; i++){
                    if(district_connaissance1[i].getType().compare("jaune") == 0) return false;
                }
                return true;
            break;

            case 24: case 29: case 33:
                for(int i = 0; i < 3; i++){
                    if(district_connaissance2[i].getType().compare("jaune") == 0) return false;
                }
                return true;
            break;

            case 4: case 9: case 10: case 15: case 16:
                for(int i = 0; i < 5; i++){
                    if(district_animaux1[i].getType().compare("vert") == 0) return false;
                }
                return true;
            break;

            case 32:
                if(district_animaux2[0].getType().compare("vert") == 0) return false;
                return true;
            break;

            case 3: case 7: case 12:
                for(int i = 0; i < 3; i++){
                    if(district_mine[i].getType().compare("gris") == 0) return false;
                }
                return true;
            break;

            case 22: case 23: case 28:
                for(int i = 0; i < 3; i++){
                    if(district_chateaux[i].getType().compare("vert fonce") == 0) return false;
                }
                return true;
            break;
        }
    }
    bool PlateauJoueur::couleurPlein(int id){
        switch(id) {
            case 1: case 2: case 6: case 17: case 19: case 20: case 21: case 26: case 27: case 30: case 34: case 35:
                for(int i = 0; i < 3; i++){
                    if(district_batiment1[i].getType().compare("marron") == 0) return false;
                }
                if(district_batiment2[0].getType().compare("marron") == 0) return false;
                for(int i = 0; i < 5; i++){
                    if(district_batiment3[i].getType().compare("marron") == 0) return false;
                }
                for(int i = 0; i < 3; i++){
                    if(district_batiment4[i].getType().compare("marron") == 0) return false;
                }
                return true;
            break;

            case 0: case 5: case 11: case 25: case 31: case 36:
                for(int i = 0; i < 3; i++){
                    if(district_bateaux1[i].getType().compare("bleu") == 0) return false;
                }
                for(int i = 0; i < 3; i++){
                    if(district_bateaux2[i].getType().compare("bleu") == 0) return false;
                }
                return true;
            break;

            case 8: case 13: case 14: case 24: case 29: case 33:
                for(int i = 0; i < 3; i++){
                    if(district_connaissance1[i].getType().compare("jaune") == 0) return false;
                }
                for(int i = 0; i < 3; i++){
                    if(district_connaissance2[i].getType().compare("jaune") == 0) return false;
                }
                return true;
            break;

            case 4: case 9: case 10: case 15: case 16: case 32:
                for(int i = 0; i < 5; i++){
                    if(district_animaux1[i].getType().compare("vert") == 0) return false;
                }
                if(district_animaux2[0].getType().compare("vert") == 0) return false;
                return true;
            break;

            case 3: case 7: case 12:
                for(int i = 0; i < 3; i++){
                    if(district_mine[i].getType().compare("gris") == 0) return false;
                }
                return true;
            break;

            case 22: case 23: case 28:
                for(int i = 0; i < 3; i++){
                    if(district_chateaux[i].getType().compare("vert fonce") == 0) return false;
                }
                return true;
            break;
        }
    }


