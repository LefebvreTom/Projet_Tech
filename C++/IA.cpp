#include "IA.h"

using namespace std;

IA :: IA(){
    partie.MajPlateauJoueur("J1");
    partie.MajPlateauJoueur("J2");
    simulateur = Simulateur();
};

IA :: ~IA(){}

void IA::Monte_Carlo(){
    vector<string> tours =createListeTourPossible(1);
    cout<<"nombre de coup possible: "<<tours.size()<<endl;
    /*for(int i = 0; i<tours.size(); i++) {
        cout << tours[i] << endl;
    }*/
    createListeSuccesseur(tours,partie.getJoueur(1),1,partie.getMarche());
    /*while(partie.getMarche().getPhase() < 6){
            PlateauCentral test = partie.getMarche();
            simulateur.finDeTour(test);
            //cout<<"Phase : "<<test.getPhase()<<"Tour : "<<test.getTour() <<endl;
            partie.updatePhaseTourMarche(test);
    }
    cout<<partie.getJoueur(1).getNbMarchVendu(1)<<endl;*/
    //cout<<"java"<<endl;
}
vector<Noeud> IA::createListeSuccesseur(vector<string> tours,PlateauJoueur joueur,int id, PlateauCentral marche){
    vector<Noeud> succ;
    int pos = 0;
    for(int i = 0; i<tours.size(); i++) {
        Noeud n(partie.getJoueur(1),partie.getJoueur(2),partie.getMarche());
        PlateauJoueur j =n.getJoueur(1);
        PlateauCentral m =n.getMarche();

        //IMPORTANT pas bouger!!!
        //p.setJoueur(J1Alex,1);

        string tour = tours[i];
        while ((pos = tour.find(",")) != string::npos) {
            string coup = tour.substr(0, pos);
            jouerCoup(j,m,coup);
            tour.erase(0, pos + 1);
        }
        //cout << tour << endl;
        n.setJoueur(j,1);
        n.setMarche(m);

        succ.push_back(n);
    }
    return succ;
}
void IA::jouerCoup(PlateauJoueur &j,PlateauCentral &m,string coup){
            if(coup.compare("0a") == 0){
                int rien =0;
            }
            else if(coup.compare("p0") == 0){
                simulateur.achatPepite(j,m,0);
            }
            else if(coup.compare("p1") == 0){
                simulateur.achatPepite(j,m,1);
            }
            else if(coup.compare("p2") == 0){
                simulateur.achatPepite(j,m,2);
            }
            else if(coup.compare("p3") == 0){
                simulateur.achatPepite(j,m,3);
            }
            else if(coup.compare("vendMde1") == 0){
                simulateur.venteMarchandise(j,1);
            }
            else if(coup.compare("vendMde1plus1") == 0){
                simulateur.utilisationOuvrier(j,1,1,true);
                simulateur.venteMarchandise(j,1);
            }
            else if(coup.compare("vendMde1moins1") == 0){
                simulateur.utilisationOuvrier(j,1,1,false);
                simulateur.venteMarchandise(j,1);
            }
            else if(coup.compare("vendMde1plus2") == 0){
                simulateur.utilisationOuvrier(j,1,2,true);
                simulateur.venteMarchandise(j,1);
            }
            else if(coup.compare("vendMde1moins2") == 0){
                simulateur.utilisationOuvrier(j,1,2,false);
                simulateur.venteMarchandise(j,1);
            }
            else if(coup.compare("vendMde1plus3") == 0){
                simulateur.utilisationOuvrier(j,1,3,true);
                simulateur.venteMarchandise(j,1);
            }
            else if(coup.compare("vendMde1moins3") == 0){
                simulateur.utilisationOuvrier(j,1,3,false);
                simulateur.venteMarchandise(j,1);
            }
            else if(coup.compare("vendMde2") == 0){
                simulateur.venteMarchandise(j,2);
            }
            else if(coup.compare("vendMde2plus1") == 0){
                simulateur.utilisationOuvrier(j,2,1,true);
                simulateur.venteMarchandise(j,2);
            }
            else if(coup.compare("vendMde2moins1") == 0){
                simulateur.utilisationOuvrier(j,2,1,false);
                simulateur.venteMarchandise(j,2);
            }
            else if(coup.compare("vendMde2plus2") == 0){
                simulateur.utilisationOuvrier(j,2,2,true);
                simulateur.venteMarchandise(j,2);
            }
            else if(coup.compare("vendMde2moins2") == 0){
                simulateur.utilisationOuvrier(j,2,2,false);
                simulateur.venteMarchandise(j,2);
            }
            else if(coup.compare("vendMde2plus3") == 0){
                simulateur.utilisationOuvrier(j,2,3,true);
                simulateur.venteMarchandise(j,2);
            }
            else if(coup.compare("vendMde2moins3") == 0){
                simulateur.utilisationOuvrier(j,2,3,false);
                simulateur.venteMarchandise(j,2);
            }
            else if(coup.compare("vend_de1") == 0){
                simulateur.venteDe(j,1);
            }
            else if(coup.compare("vend_de2") == 0){
                simulateur.venteDe(j,2);
            }
            else{
                string diff = coup.substr(0,3);
                if(diff.compare("de1") == 0){
                    coup.erase(0, 3);
                    if(coup.find("a0")!=string::npos){
                        coup.erase(0, 2);
                        if(m.getTuileMarche(j.getde(1)-1,6).compare(coup)==0){
                            simulateur.achatTuile(j,m,1,6);
                        }
                        else if(m.getTuileMarche(j.getde(1)-1,7).compare(coup)==0){
                            simulateur.achatTuile(j,m,1,7);
                        }
                    }
                    else if(coup.find("aplus1")!=string::npos){
                        simulateur.utilisationOuvrier(j,1,1,true);
                        coup.erase(0, 6);
                        if(m.getTuileMarche(j.getde(1)-1,6).compare(coup)==0){
                            simulateur.achatTuile(j,m,1,6);
                        }
                        else if(m.getTuileMarche(j.getde(1)-1,7).compare(coup)==0){
                            simulateur.achatTuile(j,m,1,7);
                        }
                    }
                    else if(coup.find("amoins1")!=string::npos){
                        simulateur.utilisationOuvrier(j,1,1,false);
                        coup.erase(0, 7);
                        if(m.getTuileMarche(j.getde(1)-1,6).compare(coup)==0){
                            simulateur.achatTuile(j,m,1,6);
                        }
                        else if(m.getTuileMarche(j.getde(1)-1,7).compare(coup)==0){
                            simulateur.achatTuile(j,m,1,7);
                        }
                    }
                    else if(coup.find("aplus2")!=string::npos){
                        simulateur.utilisationOuvrier(j,1,2,true);
                        coup.erase(0, 6);
                        if(m.getTuileMarche(j.getde(1)-1,6).compare(coup)==0){
                            simulateur.achatTuile(j,m,1,6);
                        }
                        else if(m.getTuileMarche(j.getde(1)-1,7).compare(coup)==0){
                            simulateur.achatTuile(j,m,1,7);
                        }
                    }
                    else if(coup.find("amoins2")!=string::npos){
                        simulateur.utilisationOuvrier(j,1,2,false);
                        coup.erase(0, 7);
                        if(m.getTuileMarche(j.getde(1)-1,6).compare(coup)==0){
                            simulateur.achatTuile(j,m,1,6);
                        }
                        else if(m.getTuileMarche(j.getde(1)-1,7).compare(coup)==0){
                            simulateur.achatTuile(j,m,1,7);
                        }
                    }
                    else if(coup.find("aplus3")!=string::npos){
                        simulateur.utilisationOuvrier(j,1,3,true);
                        coup.erase(0, 6);
                        if(m.getTuileMarche(j.getde(1)-1,6).compare(coup)==0){
                            simulateur.achatTuile(j,m,1,6);
                        }
                        else if(m.getTuileMarche(j.getde(1)-1,7).compare(coup)==0){
                            simulateur.achatTuile(j,m,1,7);
                        }
                    }
                    else if(coup.find("amoins3")!=string::npos){
                        simulateur.utilisationOuvrier(j,1,3,false);
                        coup.erase(0, 7);
                        if(m.getTuileMarche(j.getde(1)-1,6).compare(coup)==0){
                            simulateur.achatTuile(j,m,1,6);
                        }
                        else if(m.getTuileMarche(j.getde(1)-1,7).compare(coup)==0){
                            simulateur.achatTuile(j,m,1,7);
                        }
                    }
                    else if(coup.find("p0")!=string::npos){
                        coup.erase(0, 3);
                        string sReserve = coup.substr(0,1);
                        coup.erase(0, 5);
                        stringstream sR;
                        stringstream sT;
                        int reserve;
                        int tuile;
                        sR << sReserve;
                        sR >> reserve;
                        sT << coup;
                        sT >> tuile;
                        simulateur.posageTuile(j,1,reserve,tuile);
                    }
                    else if(coup.find("pplus1")!=string::npos){
                        simulateur.utilisationOuvrier(j,1,1,true);
                        coup.erase(0, 7);
                        string sReserve = coup.substr(0,1);
                        coup.erase(0, 5);
                        stringstream sR;
                        stringstream sT;
                        int reserve;
                        int tuile;
                        sR << sReserve;
                        sR >> reserve;
                        sT << coup;
                        sT >> tuile;
                        simulateur.posageTuile(j,1,reserve,tuile);
                    }
                    else if(coup.find("pmoins1")!=string::npos){
                        simulateur.utilisationOuvrier(j,1,1,false);
                        coup.erase(0, 8);
                        string sReserve = coup.substr(0,1);
                        coup.erase(0, 5);
                        stringstream sR;
                        stringstream sT;
                        int reserve;
                        int tuile;
                        sR << sReserve;
                        sR >> reserve;
                        sT << coup;
                        sT >> tuile;
                        simulateur.posageTuile(j,1,reserve,tuile);
                    }
                    else if(coup.find("pplus2")!=string::npos){
                        simulateur.utilisationOuvrier(j,1,2,true);
                        coup.erase(0, 7);
                        string sReserve = coup.substr(0,1);
                        coup.erase(0, 5);
                        stringstream sR;
                        stringstream sT;
                        int reserve;
                        int tuile;
                        sR << sReserve;
                        sR >> reserve;
                        sT << coup;
                        sT >> tuile;
                        simulateur.posageTuile(j,1,reserve,tuile);
                    }
                    else if(coup.find("pmoins2")!=string::npos){
                        simulateur.utilisationOuvrier(j,1,2,false);
                        coup.erase(0, 8);
                        string sReserve = coup.substr(0,1);
                        coup.erase(0, 5);
                        stringstream sR;
                        stringstream sT;
                        int reserve;
                        int tuile;
                        sR << sReserve;
                        sR >> reserve;
                        sT << coup;
                        sT >> tuile;
                        simulateur.posageTuile(j,1,reserve,tuile);
                    }
                    else if(coup.find("pplus3")!=string::npos){
                        simulateur.utilisationOuvrier(j,1,3,true);
                        coup.erase(0, 7);
                        string sReserve = coup.substr(0,1);
                        coup.erase(0, 5);
                        stringstream sR;
                        stringstream sT;
                        int reserve;
                        int tuile;
                        sR << sReserve;
                        sR >> reserve;
                        sT << coup;
                        sT >> tuile;
                        simulateur.posageTuile(j,1,reserve,tuile);
                    }
                    else if(coup.find("pmoins3")!=string::npos){
                        simulateur.utilisationOuvrier(j,1,3,false);
                        coup.erase(0, 8);
                        string sReserve = coup.substr(0,1);
                        coup.erase(0, 5);
                        stringstream sR;
                        stringstream sT;
                        int reserve;
                        int tuile;
                        sR << sReserve;
                        sR >> reserve;
                        sT << coup;
                        sT >> tuile;
                        simulateur.posageTuile(j,1,reserve,tuile);
                    }
                    else{
                        cout<<coup<<endl;
                    }
                }
                else if(diff.compare("de2") == 0){
                    coup.erase(0, 3);
                    if(coup.find("a0")!=string::npos){
                        coup.erase(0, 2);
                        if(m.getTuileMarche(j.getde(2)-1,6).compare(coup)==0){
                            simulateur.achatTuile(j,m,2,6);
                        }
                        else if(m.getTuileMarche(j.getde(2)-1,7).compare(coup)==0){
                            simulateur.achatTuile(j,m,2,7);
                        }
                    }
                    else if(coup.find("aplus1")!=string::npos){
                        simulateur.utilisationOuvrier(j,2,1,true);
                        coup.erase(0, 6);
                        if(m.getTuileMarche(j.getde(2)-1,6).compare(coup)==0){
                            simulateur.achatTuile(j,m,2,6);
                        }
                        else if(m.getTuileMarche(j.getde(2)-1,7).compare(coup)==0){
                            simulateur.achatTuile(j,m,2,7);
                        }
                    }
                    else if(coup.find("amoins1")!=string::npos){
                        simulateur.utilisationOuvrier(j,2,1,false);
                        coup.erase(0, 7);
                        if(m.getTuileMarche(j.getde(2)-1,6).compare(coup)==0){
                            simulateur.achatTuile(j,m,2,6);
                        }
                        else if(m.getTuileMarche(j.getde(2)-1,7).compare(coup)==0){
                            simulateur.achatTuile(j,m,2,7);
                        }
                    }
                    else if(coup.find("aplus2")!=string::npos){
                        simulateur.utilisationOuvrier(j,2,2,true);
                        coup.erase(0, 6);
                        if(m.getTuileMarche(j.getde(2)-1,6).compare(coup)==0){
                            simulateur.achatTuile(j,m,2,6);
                        }
                        else if(m.getTuileMarche(j.getde(2)-1,7).compare(coup)==0){
                            simulateur.achatTuile(j,m,2,7);
                        }
                    }
                    else if(coup.find("amoins2")!=string::npos){
                        simulateur.utilisationOuvrier(j,2,2,false);
                        coup.erase(0, 7);
                        if(m.getTuileMarche(j.getde(2)-1,6).compare(coup)==0){
                            simulateur.achatTuile(j,m,2,6);
                        }
                        else if(m.getTuileMarche(j.getde(2)-1,7).compare(coup)==0){
                            simulateur.achatTuile(j,m,2,7);
                        }
                    }
                    else if(coup.find("aplus3")!=string::npos){
                        simulateur.utilisationOuvrier(j,2,3,true);
                        coup.erase(0, 6);
                        if(m.getTuileMarche(j.getde(2)-1,6).compare(coup)==0){
                            simulateur.achatTuile(j,m,2,6);
                        }
                        else if(m.getTuileMarche(j.getde(2)-1,7).compare(coup)==0){
                            simulateur.achatTuile(j,m,2,7);
                        }
                    }
                    else if(coup.find("amoins3")!=string::npos){
                        simulateur.utilisationOuvrier(j,2,3,false);
                        coup.erase(0, 7);
                        if(m.getTuileMarche(j.getde(2)-1,6).compare(coup)==0){
                            simulateur.achatTuile(j,m,2,6);
                        }
                        else if(m.getTuileMarche(j.getde(2)-1,7).compare(coup)==0){
                            simulateur.achatTuile(j,m,2,7);
                        }
                    }
                    else if(coup.find("p0")!=string::npos){
                        coup.erase(0, 3);
                        string sReserve = coup.substr(0,1);
                        coup.erase(0, 5);
                        stringstream sR;
                        stringstream sT;
                        int reserve;
                        int tuile;
                        sR << sReserve;
                        sR >> reserve;
                        sT << coup;
                        sT >> tuile;
                        simulateur.posageTuile(j,2,reserve,tuile);
                    }
                    else if(coup.find("pplus1")!=string::npos){
                        simulateur.utilisationOuvrier(j,2,1,true);
                        coup.erase(0, 7);
                        string sReserve = coup.substr(0,1);
                        coup.erase(0, 5);
                        stringstream sR;
                        stringstream sT;
                        int reserve;
                        int tuile;
                        sR << sReserve;
                        sR >> reserve;
                        sT << coup;
                        sT >> tuile;
                        simulateur.posageTuile(j,2,reserve,tuile);
                    }
                    else if(coup.find("pmoins1")!=string::npos){
                        simulateur.utilisationOuvrier(j,2,1,false);
                        coup.erase(0, 8);
                        string sReserve = coup.substr(0,1);
                        coup.erase(0, 5);
                        stringstream sR;
                        stringstream sT;
                        int reserve;
                        int tuile;
                        sR << sReserve;
                        sR >> reserve;
                        sT << coup;
                        sT >> tuile;
                        simulateur.posageTuile(j,2,reserve,tuile);
                    }
                    else if(coup.find("pplus2")!=string::npos){
                        simulateur.utilisationOuvrier(j,2,2,true);
                        coup.erase(0, 7);
                        string sReserve = coup.substr(0,1);
                        coup.erase(0, 5);
                        stringstream sR;
                        stringstream sT;
                        int reserve;
                        int tuile;
                        sR << sReserve;
                        sR >> reserve;
                        sT << coup;
                        sT >> tuile;
                        simulateur.posageTuile(j,2,reserve,tuile);
                    }
                    else if(coup.find("pmoins2")!=string::npos){
                        simulateur.utilisationOuvrier(j,2,2,false);
                        coup.erase(0, 8);
                        string sReserve = coup.substr(0,1);
                        coup.erase(0, 5);
                        stringstream sR;
                        stringstream sT;
                        int reserve;
                        int tuile;
                        sR << sReserve;
                        sR >> reserve;
                        sT << coup;
                        sT >> tuile;
                        simulateur.posageTuile(j,2,reserve,tuile);
                    }
                    else if(coup.find("pplus3")!=string::npos){
                        simulateur.utilisationOuvrier(j,2,3,true);
                        coup.erase(0, 7);
                        string sReserve = coup.substr(0,1);
                        coup.erase(0, 5);
                        stringstream sR;
                        stringstream sT;
                        int reserve;
                        int tuile;
                        sR << sReserve;
                        sR >> reserve;
                        sT << coup;
                        sT >> tuile;
                        simulateur.posageTuile(j,2,reserve,tuile);
                    }
                    else if(coup.find("pmoins3")!=string::npos){
                        simulateur.utilisationOuvrier(j,2,3,false);
                        coup.erase(0, 8);
                        string sReserve = coup.substr(0,1);
                        coup.erase(0, 5);
                        stringstream sR;
                        stringstream sT;
                        int reserve;
                        int tuile;
                        sR << sReserve;
                        sR >> reserve;
                        sT << coup;
                        sT >> tuile;
                        simulateur.posageTuile(j,2,reserve,tuile);
                    }
                    else{
                        cout<<coup<<endl;
                    }
                }
                else{
                    cout<<coup<<endl;
                }
            }

}
vector<string> IA::createListeTourPossible(int id){
    vector<string> test =vecteurBranche(id);
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
                                    //cout<<tuile1<<"java"<<tuile2<<endl;
                                    int d1;
                                    int d2;
                                    if(tuile1.compare("de1")==0){
                                        d1 = partie.getJoueur(1).getde(1);
                                        tuile2 =tuile2.substr(3,tuile2.length());
                                        if(tuile2.compare("plus1")==0)d2 = partie.getJoueur(id).getde(2)+1;
                                        if(tuile2.compare("plus2")==0)d2 = partie.getJoueur(id).getde(2)+2;
                                        if(tuile2.compare("plus3")==0)d2 = partie.getJoueur(id).getde(2)+3;
                                        if(tuile2.compare("moins1")==0)d2 = partie.getJoueur(id).getde(2)-1;
                                        if(tuile2.compare("moins2")==0)d2 = partie.getJoueur(id).getde(2)-2;
                                        if(tuile2.compare("moins3")==0)d2 = partie.getJoueur(id).getde(2)+3;
                                        if(d1 != d2){
                                            string coup = autre[i]+","+de1[j]+","+de2[k];
                                            tour.push_back(coup);
                                        }
                                    }
                                    if(tuile2.compare("de2")==0){
                                        d2 = partie.getJoueur(1).getde(2);
                                        tuile1 =tuile1.substr(3,tuile1.length());
                                        if(tuile1.compare("plus1")==0)d1 = partie.getJoueur(id).getde(1)+1;
                                        if(tuile1.compare("plus2")==0)d1 = partie.getJoueur(id).getde(1)+2;
                                        if(tuile1.compare("plus3")==0)d1 = partie.getJoueur(id).getde(1)+3;
                                        if(tuile1.compare("moins1")==0)d1 = partie.getJoueur(id).getde(1)-1;
                                        if(tuile1.compare("moins2")==0)d1 = partie.getJoueur(id).getde(1)-2;
                                        if(tuile1.compare("moins3")==0)d1 = partie.getJoueur(id).getde(1)+3;
                                        if(d1 != d2){
                                            string coup = autre[i]+","+de1[j]+","+de2[k];
                                            tour.push_back(coup);
                                        }
                                    }
                                }
                                else if(de1[j].find("r")!=string::npos && de2[k].find("r")!=string::npos){
                                    string indice1 =de1[j].substr(de1[j].find("r")+1,de1[j].length());
                                    string indice2 =de2[k].substr(de2[k].find("r")+1,de2[k].length());
                                    indice1 = indice1[0];
                                    indice2 = indice2[0];
                                    if(indice1.compare(indice2)!= 0){
                                        string coup = autre[i]+","+de1[j]+","+de2[k];
                                        //cout<<coup<<endl;
                                        tour.push_back(coup);
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
                                    int d1;
                                    int d2;
                                    if(tuile1.compare("de1")==0){
                                        d1 = partie.getJoueur(1).getde(1);
                                        tuile2 =tuile2.substr(3,tuile2.length());
                                        if(tuile2.compare("plus1")==0)d2 = partie.getJoueur(id).getde(2)+1;
                                        if(tuile2.compare("plus2")==0)d2 = partie.getJoueur(id).getde(2)+2;
                                        if(tuile2.compare("plus3")==0)d2 = partie.getJoueur(id).getde(2)+3;
                                        if(tuile2.compare("moins1")==0)d2 = partie.getJoueur(id).getde(2)-1;
                                        if(tuile2.compare("moins2")==0)d2 = partie.getJoueur(id).getde(2)-2;
                                        if(tuile2.compare("moins3")==0)d2 = partie.getJoueur(id).getde(2)+3;
                                        if(d1 != d2){
                                            string coup = autre[i]+","+de2[j]+","+de1[k];
                                            tour.push_back(coup);
                                        }
                                    }
                                    if(tuile2.compare("de2")==0){
                                        d2 = partie.getJoueur(1).getde(2);
                                        tuile1 =tuile1.substr(3,tuile1.length());
                                        if(tuile1.compare("plus1")==0)d1 = partie.getJoueur(id).getde(1)+1;
                                        if(tuile1.compare("plus2")==0)d1 = partie.getJoueur(id).getde(1)+2;
                                        if(tuile1.compare("plus3")==0)d1 = partie.getJoueur(id).getde(1)+3;
                                        if(tuile1.compare("moins1")==0)d1 = partie.getJoueur(id).getde(1)-1;
                                        if(tuile1.compare("moins2")==0)d1 = partie.getJoueur(id).getde(1)-2;
                                        if(tuile1.compare("moins3")==0)d1 = partie.getJoueur(id).getde(1)+3;
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
    //cout<<"test"<<endl;
    return tour;
}

/*int IA::simulationNFindeTour(int id, Partie configFils){
    int victoire=0;
    //Partie configActuel;
    Partie configActuel = Partie(simulateur.copieJoueur(configFils.getJoueur(1)),simulateur.copieJoueur(configFils.getJoueur(2)),simulateur.copieMarche(configFils.getMarche()));

    while(configActuel.getMarche().getPhase()<6){
        //on joue aléatoirement
    }
    if(id==1){
        if(configActuel.getJoueur(1).getScore()>configActuel.getJoueur(2).getScore()){
            victoire=1;
        }
    }
    else{
        if(configActuel.getJoueur(1).getScore()<configActuel.getJoueur(2).getScore()){
            victoire=1;
        }
    }
    return victoire;
}*/

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
            if(partie.getJoueur(id).getReserve(i).compare("")!=0){
                for(int j=0;j<37;j++){
                    if(simulateur.testPosageTuile(partie.getJoueur(id), partie.getJoueur(id).getde(1), i, j)){
                        stringstream s1;
                        stringstream s2;
                        string idI;
                        string idJ;
                        s1 << i;
                        s1 >> idI;
                        s2 << j;
                        s2 >> idJ;
                        succ.push_back("de1p0r" + idI + "case" + idJ);
                    }
                    if(simulateur.testPosageTuile(partie.getJoueur(id), partie.getJoueur(id).getde(2), i, j)){
                        stringstream s1;
                        stringstream s2;
                        string idI;
                        string idJ;
                        s1 << i;
                        s1 >> idI;
                        s2 << j;
                        s2 >> idJ;
                        succ.push_back("de2p0r" + idI + "case" + idJ);
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
            if(partie.getJoueur(id).getReserve(i).compare("")!=0){
                for(int j=0;j<37;j++){
                    if(simulateur.testPosageTuile(partie.getJoueur(id), de, i, j)){
                        stringstream s1;
                        stringstream s2;
                        string idI;
                        string idJ;
                        s1 << i;
                        s1 >> idI;
                        s2 << j;
                        s2 >> idJ;
                        succ.push_back("de1pplus1r" + idI + "case" + idJ); // dé 1 +1 pose la tuile i du reservoir sur la case j
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
            if(partie.getJoueur(id).getReserve(i).compare("")!=0){
                for(int j=0;j<37;j++){
                    if(simulateur.testPosageTuile(partie.getJoueur(id), de, i, j)){
                        stringstream s1;
                        stringstream s2;
                        string idI;
                        string idJ;
                        s1 << i;
                        s1 >> idI;
                        s2 << j;
                        s2 >> idJ;
                        succ.push_back("de1pmoins1r" + idI + "case" + idJ); // dé 1 -1 pose la tuile i du reservoir sur la case j
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
            if(partie.getJoueur(id).getReserve(i).compare("")!=0){
                for(int j=0;j<37;j++){
                    if(simulateur.testPosageTuile(partie.getJoueur(id), de, i, j)){
                        stringstream s1;
                        stringstream s2;
                        string idI;
                        string idJ;
                        s1 << i;
                        s1 >> idI;
                        s2 << j;
                        s2 >> idJ;
                        succ.push_back("de2pplus1r" + idI + "case" + idJ); // dé 2 +1 pose la tuile i du reservoir sur la case j
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
            if(partie.getJoueur(id).getReserve(i).compare("")!=0){
                for(int j=0;j<37;j++){
                    if(simulateur.testPosageTuile(partie.getJoueur(id), de, i, j)){
                        stringstream s1;
                        stringstream s2;
                        string idI;
                        string idJ;
                        s1 << i;
                        s1 >> idI;
                        s2 << j;
                        s2 >> idJ;
                        cout<<idI<<" Tom "<<idJ<<endl;
                        succ.push_back("de2pmoins1r" + idI + "case" + idJ); // dé 2 -1 pose la tuile i du reservoir sur la case j
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
            if(partie.getJoueur(id).getReserve(i).compare("")!=0){
                for(int j=0;j<37;j++){
                    if(simulateur.testPosageTuile(partie.getJoueur(id), de, i, j)){
                        stringstream s1;
                        stringstream s2;
                        string idI;
                        string idJ;
                        s1 << i;
                        s1 >> idI;
                        s2 << j;
                        s2 >> idJ;
                        succ.push_back("de1pplus2r" + idI + "case" + idJ); // dé 1 +2 pose la tuile i du reservoir sur la case j
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
            if(partie.getJoueur(id).getReserve(i).compare("")!=0){
                for(int j=0;j<37;j++){
                    if(simulateur.testPosageTuile(partie.getJoueur(id), de, i, j)){
                        stringstream s1;
                        stringstream s2;
                        string idI;
                        string idJ;
                        s1 << i;
                        s1 >> idI;
                        s2 << j;
                        s2 >> idJ;
                        succ.push_back("de1pmoins2r" + idI + "case" + idJ); // dé 1 -2 pose la tuile i du reservoir sur la case j
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
            if(partie.getJoueur(id).getReserve(i).compare("")!=0){
                for(int j=0;j<37;j++){
                    if(simulateur.testPosageTuile(partie.getJoueur(id), de, i, j)){
                        stringstream s1;
                        stringstream s2;
                        string idI;
                        string idJ;
                        s1 << i;
                        s1 >> idI;
                        s2 << j;
                        s2 >> idJ;
                        succ.push_back("de2pplus2r" + idI + "case" + idJ); // dé 2 +2 pose la tuile i du reservoir sur la case j
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
            if(partie.getJoueur(id).getReserve(i).compare("")!=0){
                for(int j=0;j<37;j++){
                    if(simulateur.testPosageTuile(partie.getJoueur(id), de, i, j)){
                        stringstream s1;
                        stringstream s2;
                        string idI;
                        string idJ;
                        s1 << i;
                        s1 >> idI;
                        s2 << j;
                        s2 >> idJ;
                        succ.push_back("de2pmoins2r" + idI + "case" + idJ); // dé 2 -2 pose la tuile i du reservoir sur la case j
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
            if(partie.getJoueur(id).getReserve(i).compare("")!=0){
                for(int j=0;j<37;j++){
                    if(simulateur.testPosageTuile(partie.getJoueur(id), de, i, j)){
                        stringstream s1;
                        stringstream s2;
                        string idI;
                        string idJ;
                        s1 << i;
                        s1 >> idI;
                        s2 << j;
                        s2 >> idJ;
                        succ.push_back("de1pplus3r" + idI + "case" + idJ); // dé 1 +3 pose la tuile i du reservoir sur la case j
                    }
                }
            }
        }

        //-3 dé1
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
            if(partie.getJoueur(id).getReserve(i).compare("")!=0){
                for(int j=0;j<37;j++){
                    if(simulateur.testPosageTuile(partie.getJoueur(id), de, i, j)){
                        stringstream s1;
                        stringstream s2;
                        string idI;
                        string idJ;
                        s1 << i;
                        s1 >> idI;
                        s2 << j;
                        s2 >> idJ;
                        succ.push_back("de1pmoins3r" + idI + "case" + idJ); // dé 1 -3 pose la tuile i du reservoir sur la case j
                    }
                }
            }
        }

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
            if(partie.getJoueur(id).getReserve(i).compare("")!=0){
                for(int j=0;j<37;j++){
                    if(simulateur.testPosageTuile(partie.getJoueur(id), de, i, j)){
                        stringstream s1;
                        stringstream s2;
                        string idI;
                        string idJ;
                        s1 << i;
                        s1 >> idI;
                        s2 << j;
                        s2 >> idJ;
                        succ.push_back("de2pplus3r" +idI + "case" + idJ); // dé 2 +3 pose la tuile i du reservoir sur la case j
                    }
                }
            }
        }

        //-3 dé2
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
            if(partie.getJoueur(id).getReserve(i).compare("")!=0){
                for(int j=0;j<37;j++){
                    if(simulateur.testPosageTuile(partie.getJoueur(id), de, i, j)){
                        stringstream s1;
                        stringstream s2;
                        string idI;
                        string idJ;
                        s1 << i;
                        s1 >> idI;
                        s2 << j;
                        s2 >> idJ;
                        succ.push_back("de12pmoins3r" + idI + "case" + idJ); // dé 2 -3 pose la tuile i du reservoir sur la case j
                    }
                }
            }
        }

    }

    return succ;
}
