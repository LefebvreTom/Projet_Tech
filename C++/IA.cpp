#include "IA.h"

using namespace std;

IA :: IA(){
    partie.MajPlateauJoueur("J1");
    partie.MajPlateauJoueur("J2");
    simulateur = Simulateur();
};

IA :: ~IA(){}

void IA::Monte_Carlo(){
    vector<string> test =vecteurBranche(1);
    vector<string> de1;
    vector<string> de2;
    vector<string> autre;
    vector<string> tour;
    string mov;
    do{
        mov = test.back();
        test.pop_back();
        if (mov.find("de1") != string::npos) {
            de1.push_back(mov);
        }
        else if (mov.find("de2") != string::npos) {
            de2.push_back(mov);
        }
        else{
            autre.push_back(mov);
        }
    }while(test.size()>0);

    for(int i = 0; i<autre.size(); i++) {
            for(int j = 0; j<de1.size(); j++) {
                    for(int k = 0; k<de2.size(); k++) {
                            if (de1[j].find("t")!=string::npos && de2[k].find("t")!=string::npos){
                                string tuile1 =de1[j].substr(de1[j].find("t"),de1[j].length());
                                string tuile2 =de2[k].substr(de2[k].find("t"),de2[k].length());
                                if(tuile1.compare(tuile2)!=0){
                                        string coup = autre[i]+","+de1[j]+","+de2[k];
                                        tour.push_back(coup);
                                }
                            }
                            //
                            else if(de1[j].find("t")==string::npos && de2[k].find("t")==string::npos){
                                if(de1[j].find("M")!=string::npos && de2[k].find("M")!=string::npos){
                                    string tuile1 =de1[j].substr(de1[j].find("M")+1,de1[j].length());
                                    string tuile2 =de2[k].substr(de2[k].find("M")+1,de2[k].length());
                                    cout<<tuile1<<"java"<<tuile2<<endl;
                                    int d1;
                                    int d2;
                                    if(tuile1.compare("de1")==0){
                                        d1 = partie.getJoueur(1).getde(1);
                                        tuile2 =tuile2.substr(3,tuile2.length());
                                        if(tuile2.compare("plus1")==0)d2 = partie.getJoueur(1).getde(2)+1;
                                        if(tuile2.compare("plus2")==0)d2 = partie.getJoueur(1).getde(2)+2;
                                        if(tuile2.compare("plus3")==0)d2 = partie.getJoueur(1).getde(2)+3;
                                        if(tuile2.compare("moins1")==0)d2 = partie.getJoueur(1).getde(2)-1;
                                        if(tuile2.compare("moins2")==0)d2 = partie.getJoueur(1).getde(2)-2;
                                        if(tuile2.compare("moins3")==0)d2 = partie.getJoueur(1).getde(2)+3;
                                        if(d1 != d2){
                                            string coup = autre[i]+","+de1[j]+","+de2[k];
                                            tour.push_back(coup);
                                        }
                                    }
                                    if(tuile2.compare("de2")==0){
                                        d2 = partie.getJoueur(1).getde(2);
                                        tuile1 =tuile1.substr(3,tuile1.length());
                                        if(tuile1.compare("plus1")==0)d1 = partie.getJoueur(1).getde(1)+1;
                                        if(tuile1.compare("plus2")==0)d1 = partie.getJoueur(1).getde(1)+2;
                                        if(tuile1.compare("plus3")==0)d1 = partie.getJoueur(1).getde(1)+3;
                                        if(tuile1.compare("moins1")==0)d1 = partie.getJoueur(1).getde(1)-1;
                                        if(tuile1.compare("moins2")==0)d1 = partie.getJoueur(1).getde(1)-2;
                                        if(tuile1.compare("moins3")==0)d1 = partie.getJoueur(1).getde(1)+3;
                                        if(d1 != d2){
                                            string coup = autre[i]+","+de1[j]+","+de2[k];
                                            tour.push_back(coup);
                                        }
                                    }
                                }
                                else{
                                    string coup = autre[i]+","+de1[j]+","+de2[k];
                                    tour.push_back(coup);
                                }
                            }
                            else{
                                string coup = autre[i]+","+de1[j]+","+de2[k];
                                tour.push_back(coup);
                            }
                    }
            }

            for(int j = 0; j<de2.size(); j++) {
                    for(int k = 0; k<de1.size(); k++) {
                          if (de1[k].find("t")!=string::npos && de2[j].find("t")!=string::npos){
                                string tuile1 =de1[k].substr(de1[k].find("t"),de1[k].length());
                                string tuile2 =de2[j].substr(de2[j].find("t"),de2[j].length());
                                if(tuile1.compare(tuile2)!=0){
                                        string coup = autre[i]+","+de2[j]+","+de1[k];
                                        tour.push_back(coup);
                                }
                            }
                            //
                            else if(de1[k].find("t")==string::npos && de2[j].find("t")==string::npos){
                                if(de1[k].find("M")!=string::npos && de2[j].find("M")!=string::npos){
                                    string tuile1 =de1[k].substr(de1[k].find("M")+1,de1[k].length());
                                    string tuile2 =de2[j].substr(de2[j].find("M")+1,de2[j].length());
                                    cout<<tuile1<<"java"<<tuile2<<endl;
                                    int d1;
                                    int d2;
                                    if(tuile1.compare("de1")==0){
                                        d1 = partie.getJoueur(1).getde(1);
                                        tuile2 =tuile2.substr(3,tuile2.length());
                                        if(tuile2.compare("plus1")==0)d2 = partie.getJoueur(1).getde(2)+1;
                                        if(tuile2.compare("plus2")==0)d2 = partie.getJoueur(1).getde(2)+2;
                                        if(tuile2.compare("plus3")==0)d2 = partie.getJoueur(1).getde(2)+3;
                                        if(tuile2.compare("moins1")==0)d2 = partie.getJoueur(1).getde(2)-1;
                                        if(tuile2.compare("moins2")==0)d2 = partie.getJoueur(1).getde(2)-2;
                                        if(tuile2.compare("moins3")==0)d2 = partie.getJoueur(1).getde(2)+3;
                                        if(d1 != d2){
                                            string coup = autre[i]+","+de2[j]+","+de1[k];
                                            tour.push_back(coup);
                                        }
                                    }
                                    if(tuile2.compare("de2")==0){
                                        d2 = partie.getJoueur(1).getde(2);
                                        tuile1 =tuile1.substr(3,tuile1.length());
                                        if(tuile1.compare("plus1")==0)d1 = partie.getJoueur(1).getde(1)+1;
                                        if(tuile1.compare("plus2")==0)d1 = partie.getJoueur(1).getde(1)+2;
                                        if(tuile1.compare("plus3")==0)d1 = partie.getJoueur(1).getde(1)+3;
                                        if(tuile1.compare("moins1")==0)d1 = partie.getJoueur(1).getde(1)-1;
                                        if(tuile1.compare("moins2")==0)d1 = partie.getJoueur(1).getde(1)-2;
                                        if(tuile1.compare("moins3")==0)d1 = partie.getJoueur(1).getde(1)+3;
                                        if(d1 != d2){
                                            string coup = autre[i]+","+de2[j]+","+de1[k];
                                            tour.push_back(coup);
                                        }
                                    }
                                }
                                else{
                                    string coup = autre[i]+","+de2[j]+","+de1[k];
                                    tour.push_back(coup);
                                }
                            }
                            else{
                                string coup = autre[i]+","+de2[j]+","+de1[k];
                                tour.push_back(coup);
                            }
                    }
            }
    }
    for(int i = 0; i<tour.size(); i++) {
        cout << tour[i] << endl;
    }
    /*while(partie.getMarche().getPhase() < 6){
            PlateauCentral test = partie.getMarche();
            simulateur.finDeTour(test);
            //cout<<"Phase : "<<test.getPhase()<<"Tour : "<<test.getTour() <<endl;
            partie.updatePhaseTourMarche(test);
    }
    cout<<partie.getJoueur(1).getNbMarchVendu(1)<<endl;*/
    //cout<<"java"<<endl;
}

int IA::modifValeurDe(int de){
    int res = de%6;
    if(res==0){
        res=6;
    }
    return(res);
}



vector<string> IA::vecteurBranche(int id){
    vector<string> succ;
    //ACHAT Pépite

    succ.push_back("0a"); //on ne fait pas d'achat avec les pépites
    for(int i=0; i<4; i++){
        if(simulateur.testAchatPepite(partie.getJoueur(id), partie.getMarche(), i)){ //si on peut acheter la case (elle est libre)
            cout<<"1"<<endl;
            stringstream ss;
            string id;
            ss << i;
            ss >> id;
            string s = "p" + id;
            succ.push_back(s);
        }
    }


    //Aucune modif ouvrier
        //vente marchandise
        if(simulateur.testVenteMarchandise(partie.getJoueur(id), partie.getJoueur(id).getde(1), partie.getMarche())){
            succ.push_back("vendMde1"); //vente de la marchandise avec le dé 1
        }
        if(simulateur.testVenteMarchandise(partie.getJoueur(id), partie.getJoueur(id).getde(2), partie.getMarche())){
            succ.push_back("vendMde2"); //vente de la marchandise avec le dé 1
        }
        //achat marche valeur case 1 et 2
        if(partie.getMarche().getTuileMarche(partie.getJoueur(id).getde(1)-1,6)!=""){
            succ.push_back("de1a0" + partie.getMarche().getTuileMarche(partie.getJoueur(id).getde(1)-1,6)); //le dé 1 non modifié permet l'achat de la case 1
        }
        if(partie.getMarche().getTuileMarche(partie.getJoueur(id).getde(1)-1,7)!=""){
            succ.push_back("de1a0" + partie.getMarche().getTuileMarche(partie.getJoueur(id).getde(1)-1,7)); //le dé 1 non modifié permet l'achat de la case 2
        }
        if(partie.getMarche().getTuileMarche(partie.getJoueur(id).getde(2)-1,6)!=""){

            succ.push_back("de2a0" + partie.getMarche().getTuileMarche(partie.getJoueur(id).getde(2)-1,6)); //le dé 2 non modifié permet l'achat de la case 1
        }
        if(partie.getMarche().getTuileMarche(partie.getJoueur(id).getde(2)-1,7)!=""){
            succ.push_back("de2a0" + partie.getMarche().getTuileMarche(partie.getJoueur(id).getde(2)-1,7)); //le dé 2 non modifié permet l'achat de la case 2
        }
        //poser une des cases
        for(int i=0;i<3;i++){
            if(joueur.getReserve(i).compare("")!=0){
                for(int j=0;j<37;j++){
                    if(testPosageTuile(partie.getJoueur(id), partie.getJoueur(id).getde(1)-1, joueur.getReserve(i), joueur.getCase(j))){
                        succ.push_back("de1p0r" + std::to_string(i) + "case" + std::to_string(j))
                    }
                    if(testPosageTuile(partie.getJoueur(id), partie.getJoueur(id).getde(2)-1, joueur.getReserve(i), joueur.getCase(j))){
                        succ.push_back("de2p0r" + std::to_string(i) + "case" + std::to_string(j))
                    }
                }
            }
        }

        //vendre le de
        succ.push_back("vend_de1"); //vend le dé 1 pour 2 ouvriers
        succ.push_back("vend_de2"); //vend le dé 2 pour 2 ouvriers


        //Modification ouvrier
    //+/- 1
    int de;
    if(partie.getJoueur(id).getOuvrier()>=1){
        //+1 dé1
        de = partie.getJoueur(id).getde(1) +1;
        de = modifValeurDe(de);
        if(simulateur.testVenteMarchandise(partie.getJoueur(id), de, partie.getMarche())){
            succ.push_back("vendMde1plus1");
        }
        if(partie.getMarche().getTuileMarche(de-1,6)!=""){
            succ.push_back("de1aplus1" + partie.getMarche().getTuileMarche(de-1,6)); //le dé 1 +1 permet l'achat de la case 1
        }
        if(partie.getMarche().getTuileMarche(de-1,7)!=""){
            succ.push_back("de1aplus1" + partie.getMarche().getTuileMarche(de-1,7)); //le dé 1 +1 permet l'achat de la case 2
        }
        for(int i=0;i<3;i++){
            if(joueur.getReserve(i).compare("")!=0){
                for(int j=0;j<37;j++){
                    if(testPosageTuile(partie.getJoueur(id), de-1, joueur.getReserve(i), joueur.getCase(j))){
                        succ.push_back("de1pplus1r" + std::to_string(i) + "case" + std::to_string(j)) // dé 1 +1 pose la tuile i du reservoir sur la case j
                    }
                }
            }
        }

        //-1 dé1
        de = partie.getJoueur(id).getde(1) -1;
        de = modifValeurDe(de);
        if(simulateur.testVenteMarchandise(partie.getJoueur(id), de, partie.getMarche())){
            succ.push_back("vendMde1moins1");
        }
        if(partie.getMarche().getTuileMarche(de-1,6)!=""){
            succ.push_back("de1amoins1" + partie.getMarche().getTuileMarche(de-1,6)); //le dé 1 -1 permet l'achat de la case 1
        }
        if(partie.getMarche().getTuileMarche(de-1,7)!=""){
            succ.push_back("de1amoins1" + partie.getMarche().getTuileMarche(de-1,7)); //le dé 1 -1 permet l'achat de la case 2
        }
        for(int i=0;i<3;i++){
            if(joueur.getReserve(i).compare("")!=0){
                for(int j=0;j<37;j++){
                    if(testPosageTuile(partie.getJoueur(id), de-1, joueur.getReserve(i), joueur.getCase(j))){
                        succ.push_back("de1pmoins1r" + std::to_string(i) + "case" + std::to_string(j)) // dé 1 -1 pose la tuile i du reservoir sur la case j
                    }
                }
            }
        }

        //+1 dé2
        de = partie.getJoueur(id).getde(2) +1;
        de = modifValeurDe(de);
        if(simulateur.testVenteMarchandise(partie.getJoueur(id), de, partie.getMarche())){
            succ.push_back("vendMde2plus1");
        }
        if(partie.getMarche().getTuileMarche(de-1,6)!=""){
            succ.push_back("de2aplus1" + partie.getMarche().getTuileMarche(de-1,6)); //le dé 2 +1 permet l'achat de la case 1
        }
        if(partie.getMarche().getTuileMarche(de-1,7)!=""){
            succ.push_back("de2aplus1" + partie.getMarche().getTuileMarche(de-1,7)); //le dé 2 +1 permet l'achat de la case 2
        }
        for(int i=0;i<3;i++){
            if(joueur.getReserve(i).compare("")!=0){
                for(int j=0;j<37;j++){
                    if(testPosageTuile(partie.getJoueur(id), de-1, joueur.getReserve(i), joueur.getCase(j))){
                        succ.push_back("de2pplus1r" + std::to_string(i) + "case" + std::to_string(j)) // dé 2 +1 pose la tuile i du reservoir sur la case j
                    }
                }
            }
        }

        //-1 dé2
        de = partie.getJoueur(id).getde(2) -1;
        de = modifValeurDe(de);
        if(simulateur.testVenteMarchandise(partie.getJoueur(id), de, partie.getMarche())){
            succ.push_back("vendMde2moins1");
        }
        if(partie.getMarche().getTuileMarche(de-1,6)!=""){
            succ.push_back("de2amoins1" + partie.getMarche().getTuileMarche(de-1,6)); //le dé 2 -1 permet l'achat de la case 1
        }
        if(partie.getMarche().getTuileMarche(de-1,7)!=""){
            succ.push_back("de2amoins1" + partie.getMarche().getTuileMarche(de-1,7)); //le dé 2 -1 permet l'achat de la case 2
        }
        for(int i=0;i<3;i++){
            if(joueur.getReserve(i).compare("")!=0){
                for(int j=0;j<37;j++){
                    if(testPosageTuile(partie.getJoueur(id), de-1, joueur.getReserve(i), joueur.getCase(j))){
                        succ.push_back("de2pmoins1r" + std::to_string(i) + "case" + std::to_string(j)) // dé 2 -1 pose la tuile i du reservoir sur la case j
                    }
                }
            }
        }

    }


    //+/- 2
    if(partie.getJoueur(id).getOuvrier()>=2){
        //+2 dé1
        de = partie.getJoueur(id).getde(1) +2;
        de = modifValeurDe(de);
        if(simulateur.testVenteMarchandise(partie.getJoueur(id), de, partie.getMarche())){
            succ.push_back("vendMde1plus2");
        }
        if(partie.getMarche().getTuileMarche(de-1,6)!=""){
            succ.push_back("de1aplus2" + partie.getMarche().getTuileMarche(de-1,6)); //le dé 1 +2 permet l'achat de la case 1
        }
        if(partie.getMarche().getTuileMarche(de-1,7)!=""){
            succ.push_back("de1aplus2" + partie.getMarche().getTuileMarche(de-1,7)); //le dé 1 +2 permet l'achat de la case 2
        }
        for(int i=0;i<3;i++){
            if(joueur.getReserve(i).compare("")!=0){
                for(int j=0;j<37;j++){
                    if(testPosageTuile(partie.getJoueur(id), de-1, joueur.getReserve(i), joueur.getCase(j))){
                        succ.push_back("de1pplus2r" + std::to_string(i) + "case" + std::to_string(j)) // dé 1 +2 pose la tuile i du reservoir sur la case j
                    }
                }
            }
        }

        //-2 dé1
        de = partie.getJoueur(id).getde(1) -2;
        de = modifValeurDe(de);
        if(simulateur.testVenteMarchandise(partie.getJoueur(id), de, partie.getMarche())){
            succ.push_back("vendMde1moins2");
        }
        if(partie.getMarche().getTuileMarche(de-1,6)!=""){
            succ.push_back("de1amoins2" + partie.getMarche().getTuileMarche(de-1,6)); //le dé 1 -2 permet l'achat de la case 1
        }
        if(partie.getMarche().getTuileMarche(de-1,7)!=""){
            succ.push_back("de1amoins2" + partie.getMarche().getTuileMarche(de-1,7)); //le dé 1 -2 permet l'achat de la case 2
        }
        for(int i=0;i<3;i++){
            if(joueur.getReserve(i).compare("")!=0){
                for(int j=0;j<37;j++){
                    if(testPosageTuile(partie.getJoueur(id), de-1, joueur.getReserve(i), joueur.getCase(j))){
                        succ.push_back("de1pmoins2r" + std::to_string(i) + "case" + std::to_string(j)) // dé 1 -2 pose la tuile i du reservoir sur la case j
                    }
                }
            }
        }

        //+2 dé2
        de = partie.getJoueur(id).getde(2) +2;
        de = modifValeurDe(de);
        if(simulateur.testVenteMarchandise(partie.getJoueur(id), de, partie.getMarche())){
            succ.push_back("vendMde2plus2");
        }
        if(partie.getMarche().getTuileMarche(de-1,6)!=""){
            succ.push_back("de2aplus2" + partie.getMarche().getTuileMarche(de-1,6)); //le dé 2 +2 permet l'achat de la case 1
        }
        if(partie.getMarche().getTuileMarche(de-1,7)!=""){
            succ.push_back("de2aplus2" + partie.getMarche().getTuileMarche(de-1,7)); //le dé 2 +2 permet l'achat de la case 2
        }
        for(int i=0;i<3;i++){
            if(joueur.getReserve(i).compare("")!=0){
                for(int j=0;j<37;j++){
                    if(testPosageTuile(partie.getJoueur(id), de-1, joueur.getReserve(i), joueur.getCase(j))){
                        succ.push_back("de2pplus2r" + std::to_string(i) + "case" + std::to_string(j)) // dé 2 +2 pose la tuile i du reservoir sur la case j
                    }
                }
            }
        }

        //-2 dé2
        de = partie.getJoueur(id).getde(2) -2;
        de = modifValeurDe(de);
        if(simulateur.testVenteMarchandise(partie.getJoueur(id), de, partie.getMarche())){
            succ.push_back("vendMde2moins2");
        }
        if(partie.getMarche().getTuileMarche(de-1,6)!=""){
            succ.push_back("de2amoins2" + partie.getMarche().getTuileMarche(de-1,6)); //le dé 2 -2 permet l'achat de la case 1
        }
        if(partie.getMarche().getTuileMarche(de-1,7)!=""){
            succ.push_back("de2amoins2" + partie.getMarche().getTuileMarche(de-1,7)); //le dé 2 -2 permet l'achat de la case 2
        }
        for(int i=0;i<3;i++){
            if(joueur.getReserve(i).compare("")!=0){
                for(int j=0;j<37;j++){
                    if(testPosageTuile(partie.getJoueur(id), de-1, joueur.getReserve(i), joueur.getCase(j))){
                        succ.push_back("de2pmoins2r" + std::to_string(i) + "case" + std::to_string(j)) // dé 2 -2 pose la tuile i du reservoir sur la case j
                    }
                }
            }
        }
    }


        //+/- 3
    if(partie.getJoueur(id).getOuvrier()>=3){
        //+3 dé1
        de = partie.getJoueur(id).getde(1) +3;
        de = modifValeurDe(de);
        if(simulateur.testVenteMarchandise(partie.getJoueur(id), de, partie.getMarche())){
            succ.push_back("vendMde1plus3");
        }
        if(partie.getMarche().getTuileMarche(de-1,6)!=""){
            succ.push_back("de1aplus3" + partie.getMarche().getTuileMarche(de-1,6)); //le dé 1 +3 permet l'achat de la case 1
        }
        if(partie.getMarche().getTuileMarche(de-1,7)!=""){
            succ.push_back("de1aplus3" + partie.getMarche().getTuileMarche(de-1,7)); //le dé 1 +3 permet l'achat de la case 2
        }
        for(int i=0;i<3;i++){
            if(joueur.getReserve(i).compare("")!=0){
                for(int j=0;j<37;j++){
                    if(testPosageTuile(partie.getJoueur(id), de-1, joueur.getReserve(i), joueur.getCase(j))){
                        succ.push_back("de1pplus3r" + std::to_string(i) + "case" + std::to_string(j)) // dé 1 +3 pose la tuile i du reservoir sur la case j
                    }
                }
            }
        }

        /*//-3 dé1
        de = partie.getJoueur(id).getde(1) -3;
        de = modifValeurDe(de);
        if(simulateur.testVenteMarchandise(partie.getJoueur(id), de, partie.getMarche())){
            succ.push_back("vendMde1moins3");
        }
        if(partie.getMarche().getTuileMarche(de-1,6)!=""){
            succ.push_back("de1amoins3" + partie.getMarche().getTuileMarche(de-1,6)); //le dé 1 -3 permet l'achat de la case 1
        }
        if(partie.getMarche().getTuileMarche(de-1,7)!=""){
            succ.push_back("de1amoins3" + partie.getMarche().getTuileMarche(de-1,7)); //le dé 1 -3 permet l'achat de la case 2
        }
        for(int i=0;i<3;i++){
            if(joueur.getReserve(i).compare("")!=0){
                for(int j=0;j<37;j++){
                    if(testPosageTuile(partie.getJoueur(id), de-1, joueur.getReserve(i), joueur.getCase(j))){
                        succ.push_back("de1pmoins3r" + std::to_string(i) + "case" + std::to_string(j)) // dé 1 -3 pose la tuile i du reservoir sur la case j
                    }
                }
            }
        }*/

        //+3 dé2
        de = partie.getJoueur(id).getde(2) +3;
        de = modifValeurDe(de);
        if(simulateur.testVenteMarchandise(partie.getJoueur(id), de, partie.getMarche())){
            succ.push_back("vendMde2plus3");
        }
        if(partie.getMarche().getTuileMarche(de-1,6)!=""){
            succ.push_back("de2aplus3" + partie.getMarche().getTuileMarche(de-1,6)); //le dé 2 +3 permet l'achat de la case 1
        }
        if(partie.getMarche().getTuileMarche(de-1,7)!=""){
            succ.push_back("de2aplus3" + partie.getMarche().getTuileMarche(de-1,7)); //le dé 2 +3 permet l'achat de la case 2
        }
        for(int i=0;i<3;i++){
            if(joueur.getReserve(i).compare("")!=0){
                for(int j=0;j<37;j++){
                    if(testPosageTuile(partie.getJoueur(id), de-1, joueur.getReserve(i), joueur.getCase(j))){
                        succ.push_back("de2pplus3r" + std::to_string(i) + "case" + std::to_string(j)) // dé 2 +3 pose la tuile i du reservoir sur la case j
                    }
                }
            }
        }

        /*//-3 dé2
        de = partie.getJoueur(id).getde(2) -3;
        de = modifValeurDe(de);
        if(simulateur.testVenteMarchandise(partie.getJoueur(id), de, partie.getMarche())){
            succ.push_back("vendMde2moins3");
        }
        if(partie.getMarche().getTuileMarche(de-1,6)!=""){
            succ.push_back("de2amoins3" + partie.getMarche().getTuileMarche(de-1,6)); //le dé 2 -3 permet l'achat de la case 1
        }
        if(partie.getMarche().getTuileMarche(de-1,7)!=""){
            succ.push_back("de2amoins3" + partie.getMarche().getTuileMarche(de-1,7)); //le dé 2 -3 permet l'achat de la case 2
        }
        for(int i=0;i<3;i++){
            if(joueur.getReserve(i).compare("")!=0){
                for(int j=0;j<37;j++){
                    if(testPosageTuile(partie.getJoueur(id), de-1, joueur.getReserve(i), joueur.getCase(j))){
                        succ.push_back("de12pmoins3r" + std::to_string(i) + "case" + std::to_string(j)) // dé 2 -3 pose la tuile i du reservoir sur la case j
                    }
                }
            }
        }*/

    }

    return succ;
}
