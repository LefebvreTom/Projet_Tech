#include "IA.h"

using namespace std;

IA :: IA(){
    partie.MajPlateauJoueur("J1");
    partie.MajPlateauJoueur("J2");
    simulateur = Simulateur();
};

IA :: ~IA(){}

void IA::Monte_Carlo(){
    Noeud configActuel(partie.getJoueur(1),partie.getJoueur(2),partie.getMarche());
    vector<string> tours =createListeTourPossible(1, configActuel);
    cout<<"nombre de coup possible: "<<tours.size()<<endl;
    for(int i = 0; i<tours.size(); i++) {
        cout << tours[i] << endl;
    }
    //createListeSuccesseur(tours,partie.getJoueur(1),1,partie.getMarche());
    //coupAleatoire(tours,partie.getJoueur(1),1,partie.getMarche());
    /*while(partie.getMarche().getPhase() < 6){
            PlateauCentral test = partie.getMarche();
            simulateur.finDeTour(test);
            //cout<<"Phase : "<<test.getPhase()<<"Tour : "<<test.getTour() <<endl;
            partie.updatePhaseTourMarche(test);
    }
    cout<<partie.getJoueur(1).getNbMarchVendu(1)<<endl;*/
    //cout<<"java"<<endl;
    int Max=0;
    int Min=20;
    vector<Noeud> toutesConfigFils = createListeSuccesseur(tours,partie.getJoueur(1),partie.getJoueur(2),1,partie.getMarche());
    vector<string> choixCoupMax={};
    vector<string> choixCoupMin={};
    vector<string> tour={};
    do{
        int gain=0;
        //jouerCoup(PlateauJoueur &j,PlateauCentral &m,string coup);
        Noeud configFils = toutesConfigFils.back();
        for(int j=0; j<20; j++){
            cout<<"               "<<j<<endl;
            gain += simulationNFindeTour(1,configFils);
        }
        if(gain>Max){
            Max=gain;
            choixCoupMax = tour;
        }
        if(gain<Min){
            Min=gain;
            choixCoupMin = tour;
        }
        toutesConfigFils.pop_back();
    }while(toutesConfigFils.size()>0);
    cout<<"Max :"<<Max<<endl;
    cout<<"Min :"<<Min<<endl;
    //for(int i = 0; i<choixCoup.size(); i++) {
    //  cout << choixCoup[i] << endl;
    //}
}


vector<Noeud> IA::createListeSuccesseur(vector<string> tours,PlateauJoueur joueur1,PlateauJoueur joueur2,int id, PlateauCentral marche){
    vector<Noeud> succ={};
    int pos = 0;
    for(int i = 0; i<tours.size(); i++) {
        Noeud n(joueur1,joueur2,marche);
        PlateauJoueur jc;
        PlateauJoueur jr;
        if(id == 1){
            jc =n.getJoueur(id);
            jr =n.getJoueur(id+1);
        }
        if(id == 2){
            jc =n.getJoueur(id);
            jr =n.getJoueur(id-1);
        }

        PlateauCentral m =n.getMarche();

        string tour = tours[i];
        while ((pos = tour.find(",")) != string::npos) {
            string coup = tour.substr(0, pos);
            jouerCoup(jc,m,coup);
            tour.erase(0, pos + 1);
        }
        jouerCoup(jc,m,tour);
        //cout << tour << endl;
        //Peut etre à déplacer
        simulateur.finDeTour(m,jc,jr);
        if(id == 1){
            n.setJoueur(jc,id);
            n.setJoueur(jr,id+1);
        }
        if(id == 2){
            n.setJoueur(jc,id);
            n.setJoueur(jr,id-1);
        }
        n.setMarche(m);

        succ.push_back(n);
    }
    //cout<<succ.size()<<endl;
    return succ;
}

Noeud IA::coupAleatoire(vector<string> tours,PlateauJoueur joueur1,PlateauJoueur joueur2,int id, PlateauCentral marche){
    Noeud succ(joueur1,joueur2,marche);
    PlateauJoueur jc;
    PlateauJoueur jr;
    if(id == 1){
        jc =succ.getJoueur(id);
        jr =succ.getJoueur(id+1);
    }
    if(id == 2){
        jc =succ.getJoueur(id);
        jr =succ.getJoueur(id-1);
    }
    PlateauCentral m =succ.getMarche();
    int r=(rand()%tours.size()-1)+1;
    int pos = 0;
    string tour = tours[r];
    while ((pos = tour.find(",")) != string::npos) {
            string coup = tour.substr(0, pos);
            //cout<<coup<<endl;
            jouerCoup(jc,m,coup);
            tour.erase(0, pos + 1);
    }
    //cout<<tour<<endl;
    jouerCoup(jc,m,tour);
    simulateur.finDeTour(m,jc,jr);
    if(id == 1){
        succ.setJoueur(jc,id);
        succ.setJoueur(jr,id+1);
    }
    if(id == 2){
        succ.setJoueur(jc,id);
        succ.setJoueur(jr,id-1);
    }
    succ.setMarche(m);
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
                        if(m.getTuileMarche(modifValeurDe(j.getde(1)-1),6).compare(coup)==0){
                            simulateur.achatTuile(j,m,1,6);
                        }
                        else if(m.getTuileMarche(modifValeurDe(j.getde(1)-1),7).compare(coup)==0){
                            simulateur.achatTuile(j,m,1,7);
                        }
                    }
                    else if(coup.find("aplus1")!=string::npos){
                        simulateur.utilisationOuvrier(j,1,1,true);
                        coup.erase(0, 6);
                        if(m.getTuileMarche(modifValeurDe(j.getde(1)-1),6).compare(coup)==0){
                            simulateur.achatTuile(j,m,1,6);
                        }
                        else if(m.getTuileMarche(modifValeurDe(j.getde(1)-1),7).compare(coup)==0){
                            simulateur.achatTuile(j,m,1,7);
                        }
                    }
                    else if(coup.find("amoins1")!=string::npos){
                        simulateur.utilisationOuvrier(j,1,1,false);
                        coup.erase(0, 7);
                        if(m.getTuileMarche(modifValeurDe(j.getde(1)-1),6).compare(coup)==0){
                            simulateur.achatTuile(j,m,1,6);
                        }
                        else if(m.getTuileMarche(modifValeurDe(j.getde(1)-1),7).compare(coup)==0){
                            simulateur.achatTuile(j,m,1,7);
                        }
                    }
                    else if(coup.find("aplus2")!=string::npos){
                        simulateur.utilisationOuvrier(j,1,2,true);
                        coup.erase(0, 6);
                        if(m.getTuileMarche(modifValeurDe(j.getde(1)-1),6).compare(coup)==0){
                            simulateur.achatTuile(j,m,1,6);
                        }
                        else if(m.getTuileMarche(modifValeurDe(j.getde(1)-1),7).compare(coup)==0){
                            simulateur.achatTuile(j,m,1,7);
                        }
                    }
                    else if(coup.find("amoins2")!=string::npos){
                        simulateur.utilisationOuvrier(j,1,2,false);
                        coup.erase(0, 7);
                        if(m.getTuileMarche(modifValeurDe(j.getde(1))-1,6).compare(coup)==0){
                            simulateur.achatTuile(j,m,1,6);
                        }
                        else if(m.getTuileMarche(modifValeurDe(j.getde(1)-1),7).compare(coup)==0){
                            simulateur.achatTuile(j,m,1,7);
                        }
                    }
                    else if(coup.find("aplus3")!=string::npos){
                        simulateur.utilisationOuvrier(j,1,3,true);
                        coup.erase(0, 6);
                        if(m.getTuileMarche(modifValeurDe(j.getde(1)-1),6).compare(coup)==0){
                            simulateur.achatTuile(j,m,1,6);
                        }
                        else if(m.getTuileMarche(modifValeurDe(j.getde(1)-1),7).compare(coup)==0){
                            simulateur.achatTuile(j,m,1,7);
                        }
                    }
                    else if(coup.find("amoins3")!=string::npos){
                        simulateur.utilisationOuvrier(j,1,3,false);
                        coup.erase(0, 7);
                        if(m.getTuileMarche(modifValeurDe(j.getde(1)-1),6).compare(coup)==0){
                            simulateur.achatTuile(j,m,1,6);
                        }
                        else if(m.getTuileMarche(modifValeurDe(j.getde(1)-1),7).compare(coup)==0){
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
                        simulateur.gestionDistrict(j,m,tuile);
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
                        simulateur.gestionDistrict(j,m,tuile);
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
                        simulateur.gestionDistrict(j,m,tuile);
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
                        simulateur.gestionDistrict(j,m,tuile);
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
                        simulateur.gestionDistrict(j,m,tuile);
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
                        simulateur.gestionDistrict(j,m,tuile);
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
                        simulateur.gestionDistrict(j,m,tuile);
                    }
                    else{
                        cout<<coup<<endl;
                    }
                }
                else if(diff.compare("de2") == 0){
                    coup.erase(0, 3);
                    if(coup.find("a0")!=string::npos){
                        coup.erase(0, 2);
                        if(m.getTuileMarche(modifValeurDe(j.getde(2)-1),6).compare(coup)==0){
                            simulateur.achatTuile(j,m,2,6);
                        }
                        else if(m.getTuileMarche(modifValeurDe(j.getde(2)-1),7).compare(coup)==0){
                            simulateur.achatTuile(j,m,2,7);
                        }
                    }
                    else if(coup.find("aplus1")!=string::npos){
                        simulateur.utilisationOuvrier(j,2,1,true);
                        coup.erase(0, 6);
                        if(m.getTuileMarche(modifValeurDe(j.getde(2)-1),6).compare(coup)==0){
                            simulateur.achatTuile(j,m,2,6);
                        }
                        else if(m.getTuileMarche(modifValeurDe(j.getde(2)-1),7).compare(coup)==0){
                            simulateur.achatTuile(j,m,2,7);
                        }
                    }
                    else if(coup.find("amoins1")!=string::npos){
                        simulateur.utilisationOuvrier(j,2,1,false);
                        coup.erase(0, 7);
                        if(m.getTuileMarche(modifValeurDe(j.getde(2)-1),6).compare(coup)==0){
                            simulateur.achatTuile(j,m,2,6);
                        }
                        else if(m.getTuileMarche(modifValeurDe(j.getde(2)-1),7).compare(coup)==0){
                            simulateur.achatTuile(j,m,2,7);
                        }
                    }
                    else if(coup.find("aplus2")!=string::npos){
                        simulateur.utilisationOuvrier(j,2,2,true);
                        coup.erase(0, 6);
                        if(m.getTuileMarche(modifValeurDe(j.getde(2)-1),6).compare(coup)==0){
                            simulateur.achatTuile(j,m,2,6);
                        }
                        else if(m.getTuileMarche(modifValeurDe(j.getde(2)-1),7).compare(coup)==0){
                            simulateur.achatTuile(j,m,2,7);
                        }
                    }
                    else if(coup.find("amoins2")!=string::npos){
                        simulateur.utilisationOuvrier(j,2,2,false);
                        coup.erase(0, 7);
                        if(m.getTuileMarche(modifValeurDe(j.getde(2)-1),6).compare(coup)==0){
                            simulateur.achatTuile(j,m,2,6);
                        }
                        else if(m.getTuileMarche(modifValeurDe(j.getde(2)-1),7).compare(coup)==0){
                            simulateur.achatTuile(j,m,2,7);
                        }
                    }
                    else if(coup.find("aplus3")!=string::npos){
                        simulateur.utilisationOuvrier(j,2,3,true);
                        coup.erase(0, 6);
                        if(m.getTuileMarche(modifValeurDe(j.getde(2)-1),6).compare(coup)==0){
                            simulateur.achatTuile(j,m,2,6);
                        }
                        else if(m.getTuileMarche(modifValeurDe(j.getde(2)-1),7).compare(coup)==0){
                            simulateur.achatTuile(j,m,2,7);
                        }
                    }
                    else if(coup.find("amoins3")!=string::npos){
                        simulateur.utilisationOuvrier(j,2,3,false);
                        coup.erase(0, 7);
                        if(m.getTuileMarche(modifValeurDe(j.getde(2)-1),6).compare(coup)==0){
                            simulateur.achatTuile(j,m,2,6);
                        }
                        else if(m.getTuileMarche(modifValeurDe(j.getde(2)-1),7).compare(coup)==0){
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
                        simulateur.gestionDistrict(j,m,tuile);
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
                        simulateur.gestionDistrict(j,m,tuile);
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
                        simulateur.gestionDistrict(j,m,tuile);
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
                        simulateur.gestionDistrict(j,m,tuile);
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
                        simulateur.gestionDistrict(j,m,tuile);
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
                        simulateur.gestionDistrict(j,m,tuile);
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
                        simulateur.gestionDistrict(j,m,tuile);
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


vector<string> IA::createListeTourPossible(int id, Noeud configActuel){
    vector<string> test = vecteurBranche( id, configActuel);
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

int IA::simulationNFindeTour(int id, Noeud configFils){
    int victoire=0;
    //Partie configActuel = Partie(simulateur.copieJoueur(configFils.getJoueur(1)),simulateur.copieJoueur(configFils.getJoueur(2)),simulateur.copieMarche(configFils.getMarche()));
    Noeud configActuel(configFils.getJoueur(1),configFils.getJoueur(2),configFils.getMarche());
    PlateauJoueur test1;
    while(configActuel.getMarche().getPhase()<6){
        test1 = configActuel.getJoueur(1);
        //on joue aléatoirement
        int r1=(rand()%6)+1;
        int r2=(rand()%6)+1;
        test1.setde(1,r1);
        test1.setde(2,r2);
        configActuel.setJoueur(test1,1);
        vector<string> tours1 = createListeTourPossible(1, configActuel);
        configActuel = coupAleatoire(tours1,configActuel.getJoueur(1),configActuel.getJoueur(2),1,configActuel.getMarche());
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
}

int IA::modifValeurDe(int de){
    int res = (de+6)%6;
    if(res==0){
        res=6;
    }
    return(res);
}


vector<string> IA::vecteurBranche(int id, Noeud configActuel){


    vector<string> succ={};

    //ACHAT Pépite
    succ.push_back("0a"); //on ne fait pas d'achat avec les pépites
    for(int i=0; i<4; i++){
        if(simulateur.testAchatPepite(configActuel.getJoueur(id), configActuel.getMarche(), i)){ //si on peut acheter la case (elle est libre)
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
        if(simulateur.testVenteMarchandise(configActuel.getJoueur(id), configActuel.getJoueur(id).getde(1), configActuel.getMarche())){
            succ.push_back("vendMde1"); //vente de la marchandise avec le dé 1
        }
        if(simulateur.testVenteMarchandise(configActuel.getJoueur(id), configActuel.getJoueur(id).getde(2), configActuel.getMarche())){
            succ.push_back("vendMde2"); //vente de la marchandise avec le dé 1
        }
        //achat marche valeur case 1 et 2
        if(configActuel.getMarche().getTuileMarche(configActuel.getJoueur(id).getde(1)-1,6)!=""){
            succ.push_back("de1a0" + configActuel.getMarche().getTuileMarche(configActuel.getJoueur(id).getde(1)-1,6)); //le dé 1 non modifié permet l'achat de la case 1
        }
        if(configActuel.getMarche().getTuileMarche(configActuel.getJoueur(id).getde(1)-1,7)!=""){
            succ.push_back("de1a0" + configActuel.getMarche().getTuileMarche(configActuel.getJoueur(id).getde(1)-1,7)); //le dé 1 non modifié permet l'achat de la case 2
        }
        if(configActuel.getMarche().getTuileMarche(configActuel.getJoueur(id).getde(2)-1,6)!=""){
            succ.push_back("de2a0" + configActuel.getMarche().getTuileMarche(configActuel.getJoueur(id).getde(2)-1,6)); //le dé 2 non modifié permet l'achat de la case 1
        }
        if(configActuel.getMarche().getTuileMarche(configActuel.getJoueur(id).getde(2)-1,7)!=""){
            succ.push_back("de2a0" + configActuel.getMarche().getTuileMarche(configActuel.getJoueur(id).getde(2)-1,7)); //le dé 2 non modifié permet l'achat de la case 2
        }
        //poser une des cases
        for(int i=0;i<3;i++){
            if(configActuel.getJoueur(id).getReserve(i).compare("")!=0){
                for(int j=0;j<37;j++){
                    if(simulateur.testPosageTuile(configActuel.getJoueur(id), configActuel.getJoueur(id).getde(1), i, j)){
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
                    if(simulateur.testPosageTuile(configActuel.getJoueur(id), configActuel.getJoueur(id).getde(2), i, j)){
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
    if(configActuel.getJoueur(id).getOuvrier()>=1){
        //+1 dé1
        de = configActuel.getJoueur(id).getde(1) +1;
        de = modifValeurDe(de);
        if(simulateur.testVenteMarchandise(configActuel.getJoueur(id), de, configActuel.getMarche())){
            succ.push_back("vendMde1plus1");
        }
        if(configActuel.getMarche().getTuileMarche(de-1,6)!=""){
            succ.push_back("de1aplus1" + configActuel.getMarche().getTuileMarche(de-1,6)); //le dé 1 +1 permet l'achat de la case 1
        }
        if(configActuel.getMarche().getTuileMarche(de-1,7)!=""){
            succ.push_back("de1aplus1" + configActuel.getMarche().getTuileMarche(de-1,7)); //le dé 1 +1 permet l'achat de la case 2
        }
        for(int i=0;i<3;i++){
            if(configActuel.getJoueur(id).getReserve(i).compare("")!=0){
                for(int j=0;j<37;j++){
                    if(simulateur.testPosageTuile(configActuel.getJoueur(id), de, i, j)){
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
        de = configActuel.getJoueur(id).getde(1) -1;
        de = modifValeurDe(de);
        if(simulateur.testVenteMarchandise(configActuel.getJoueur(id), de, configActuel.getMarche())){
            succ.push_back("vendMde1moins1");
        }
        if(configActuel.getMarche().getTuileMarche(de-1,6)!=""){
            succ.push_back("de1amoins1" + configActuel.getMarche().getTuileMarche(de-1,6)); //le dé 1 -1 permet l'achat de la case 1
        }
        if(configActuel.getMarche().getTuileMarche(de-1,7)!=""){
            succ.push_back("de1amoins1" + configActuel.getMarche().getTuileMarche(de-1,7)); //le dé 1 -1 permet l'achat de la case 2
        }
        for(int i=0;i<3;i++){
            if(configActuel.getJoueur(id).getReserve(i).compare("")!=0){
                for(int j=0;j<37;j++){
                    if(simulateur.testPosageTuile(configActuel.getJoueur(id), de, i, j)){
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
        de = configActuel.getJoueur(id).getde(2) +1;
        de = modifValeurDe(de);
        if(simulateur.testVenteMarchandise(configActuel.getJoueur(id), de, configActuel.getMarche())){
            succ.push_back("vendMde2plus1");
        }
        if(configActuel.getMarche().getTuileMarche(de-1,6)!=""){
            succ.push_back("de2aplus1" + configActuel.getMarche().getTuileMarche(de-1,6)); //le dé 2 +1 permet l'achat de la case 1
        }
        if(configActuel.getMarche().getTuileMarche(de-1,7)!=""){
            succ.push_back("de2aplus1" + configActuel.getMarche().getTuileMarche(de-1,7)); //le dé 2 +1 permet l'achat de la case 2
        }
        for(int i=0;i<3;i++){
            if(configActuel.getJoueur(id).getReserve(i).compare("")!=0){
                for(int j=0;j<37;j++){
                    if(simulateur.testPosageTuile(configActuel.getJoueur(id), de, i, j)){
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
        de = configActuel.getJoueur(id).getde(2) -1;
        de = modifValeurDe(de);
        if(simulateur.testVenteMarchandise(configActuel.getJoueur(id), de, configActuel.getMarche())){
            succ.push_back("vendMde2moins1");
        }
        if(configActuel.getMarche().getTuileMarche(de-1,6)!=""){
            succ.push_back("de2amoins1" + configActuel.getMarche().getTuileMarche(de-1,6)); //le dé 2 -1 permet l'achat de la case 1
        }
        if(configActuel.getMarche().getTuileMarche(de-1,7)!=""){
            succ.push_back("de2amoins1" + configActuel.getMarche().getTuileMarche(de-1,7)); //le dé 2 -1 permet l'achat de la case 2
        }
        for(int i=0;i<3;i++){
            if(configActuel.getJoueur(id).getReserve(i).compare("")!=0){
                for(int j=0;j<37;j++){
                    if(simulateur.testPosageTuile(configActuel.getJoueur(id), de, i, j)){
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
    if(configActuel.getJoueur(id).getOuvrier()>=2){
        //+2 dé1
        de = configActuel.getJoueur(id).getde(1) +2;
        de = modifValeurDe(de);
        cout<<de<<endl;
        if(simulateur.testVenteMarchandise(configActuel.getJoueur(id), de, configActuel.getMarche())){
            succ.push_back("vendMde1plus2");
        }
        if(configActuel.getMarche().getTuileMarche(de-1,6)!=""){
            succ.push_back("de1aplus2" + configActuel.getMarche().getTuileMarche(de-1,6)); //le dé 1 +2 permet l'achat de la case 1
        }
        if(configActuel.getMarche().getTuileMarche(de-1,7)!=""){
            succ.push_back("de1aplus2" + configActuel.getMarche().getTuileMarche(de-1,7)); //le dé 1 +2 permet l'achat de la case 2
        }
        for(int i=0;i<3;i++){
            if(configActuel.getJoueur(id).getReserve(i).compare("")!=0){
                for(int j=0;j<37;j++){
                    if(simulateur.testPosageTuile(configActuel.getJoueur(id), de, i, j)){
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
        de = configActuel.getJoueur(id).getde(1) -2;
        de = modifValeurDe(de);
        if(simulateur.testVenteMarchandise(configActuel.getJoueur(id), de, configActuel.getMarche())){
            succ.push_back("vendMde1moins2");
        }
        if(configActuel.getMarche().getTuileMarche(de-1,6)!=""){
            succ.push_back("de1amoins2" + configActuel.getMarche().getTuileMarche(de-1,6)); //le dé 1 -2 permet l'achat de la case 1
        }
        if(configActuel.getMarche().getTuileMarche(de-1,7)!=""){
            succ.push_back("de1amoins2" + configActuel.getMarche().getTuileMarche(de-1,7)); //le dé 1 -2 permet l'achat de la case 2
        }
        for(int i=0;i<3;i++){
            if(configActuel.getJoueur(id).getReserve(i).compare("")!=0){
                for(int j=0;j<37;j++){
                    if(simulateur.testPosageTuile(configActuel.getJoueur(id), de, i, j)){
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
        de = configActuel.getJoueur(id).getde(2) +2;
        de = modifValeurDe(de);
        if(simulateur.testVenteMarchandise(configActuel.getJoueur(id), de, configActuel.getMarche())){
            succ.push_back("vendMde2plus2");
        }
        if(configActuel.getMarche().getTuileMarche(de-1,6)!=""){
            succ.push_back("de2aplus2" + configActuel.getMarche().getTuileMarche(de-1,6)); //le dé 2 +2 permet l'achat de la case 1
        }
        if(configActuel.getMarche().getTuileMarche(de-1,7)!=""){
            succ.push_back("de2aplus2" + configActuel.getMarche().getTuileMarche(de-1,7)); //le dé 2 +2 permet l'achat de la case 2
        }
        for(int i=0;i<3;i++){
            if(configActuel.getJoueur(id).getReserve(i).compare("")!=0){
                for(int j=0;j<37;j++){
                    if(simulateur.testPosageTuile(configActuel.getJoueur(id), de, i, j)){
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
        de = configActuel.getJoueur(id).getde(2) -2;
        de = modifValeurDe(de);
        if(simulateur.testVenteMarchandise(configActuel.getJoueur(id), de, configActuel.getMarche())){
            succ.push_back("vendMde2moins2");
        }
        cout<<"test47-1"<<endl;
        if(configActuel.getMarche().getTuileMarche(de-1,6)!=""){
            succ.push_back("de2amoins2" + configActuel.getMarche().getTuileMarche(de-1,6)); //le dé 2 -2 permet l'achat de la case 1
        }
        if(configActuel.getMarche().getTuileMarche(de-1,7)!=""){
            succ.push_back("de2amoins2" + configActuel.getMarche().getTuileMarche(de-1,7)); //le dé 2 -2 permet l'achat de la case 2
        }
        for(int i=0;i<3;i++){
            if(configActuel.getJoueur(id).getReserve(i).compare("")!=0){
                for(int j=0;j<37;j++){
                    if(simulateur.testPosageTuile(configActuel.getJoueur(id), de, i, j)){
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
    if(configActuel.getJoueur(id).getOuvrier()>=3){
        //+3 dé1
        de = configActuel.getJoueur(id).getde(1) +3;
        de = modifValeurDe(de);
        if(simulateur.testVenteMarchandise(configActuel.getJoueur(id), de, configActuel.getMarche())){
            succ.push_back("vendMde1plus3");
        }
        if(configActuel.getMarche().getTuileMarche(de-1,6)!=""){
            succ.push_back("de1aplus3" + configActuel.getMarche().getTuileMarche(de-1,6)); //le dé 1 +3 permet l'achat de la case 1
        }
        if(configActuel.getMarche().getTuileMarche(de-1,7)!=""){
            succ.push_back("de1aplus3" + configActuel.getMarche().getTuileMarche(de-1,7)); //le dé 1 +3 permet l'achat de la case 2
        }
        for(int i=0;i<3;i++){
            if(configActuel.getJoueur(id).getReserve(i).compare("")!=0){
                for(int j=0;j<37;j++){
                    if(simulateur.testPosageTuile(configActuel.getJoueur(id), de, i, j)){
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
        de = configActuel.getJoueur(id).getde(1) -3;
        de = modifValeurDe(de);
        cout<<de<<endl;
        if(simulateur.testVenteMarchandise(configActuel.getJoueur(id), de, configActuel.getMarche())){
            succ.push_back("vendMde1moins3");
        }
        if(configActuel.getMarche().getTuileMarche(de-1,6)!=""){
            succ.push_back("de1amoins3" + configActuel.getMarche().getTuileMarche(de-1,6)); //le dé 1 -3 permet l'achat de la case 1
        }
        if(configActuel.getMarche().getTuileMarche(de-1,7)!=""){
            succ.push_back("de1amoins3" + configActuel.getMarche().getTuileMarche(de-1,7)); //le dé 1 -3 permet l'achat de la case 2
        }
        for(int i=0;i<3;i++){
            if(configActuel.getJoueur(id).getReserve(i).compare("")!=0){
                for(int j=0;j<37;j++){
                    if(simulateur.testPosageTuile(configActuel.getJoueur(id), de, i, j)){
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
        de = configActuel.getJoueur(id).getde(2) +3;
        de = modifValeurDe(de);
        cout<<de<<endl;
        if(simulateur.testVenteMarchandise(configActuel.getJoueur(id), de, configActuel.getMarche())){
            succ.push_back("vendMde2plus3");
        }
        if(configActuel.getMarche().getTuileMarche(de-1,6)!=""){
            succ.push_back("de2aplus3" + configActuel.getMarche().getTuileMarche(de-1,6)); //le dé 2 +3 permet l'achat de la case 1
        }
        if(configActuel.getMarche().getTuileMarche(de-1,7)!=""){
            succ.push_back("de2aplus3" + configActuel.getMarche().getTuileMarche(de-1,7)); //le dé 2 +3 permet l'achat de la case 2
        }
        for(int i=0;i<3;i++){
            if(configActuel.getJoueur(id).getReserve(i).compare("")!=0){
                for(int j=0;j<37;j++){
                    if(simulateur.testPosageTuile(configActuel.getJoueur(id), de, i, j)){
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
        de = configActuel.getJoueur(id).getde(2) -3;
        de = modifValeurDe(de);
        cout<<de<<endl;
        if(simulateur.testVenteMarchandise(configActuel.getJoueur(id), de, configActuel.getMarche())){
            succ.push_back("vendMde2moins3");
        }
        if(configActuel.getMarche().getTuileMarche(de-1,6)!=""){
            succ.push_back("de2amoins3" + configActuel.getMarche().getTuileMarche(de-1,6)); //le dé 2 -3 permet l'achat de la case 1
        }
        if(configActuel.getMarche().getTuileMarche(de-1,7)!=""){
            succ.push_back("de2amoins3" + configActuel.getMarche().getTuileMarche(de-1,7)); //le dé 2 -3 permet l'achat de la case 2
        }
        for(int i=0;i<3;i++){
            if(configActuel.getJoueur(id).getReserve(i).compare("")!=0){
                for(int j=0;j<37;j++){
                    if(simulateur.testPosageTuile(configActuel.getJoueur(id), de, i, j)){
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
