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
    cout<<"nombre de coup possible: "<<tours.size()<<endl<<endl<<endl;
    cout<<"Merci de bien vouloir patienter, nous determinons le meilleur coup a faire dans cette situation"<<endl<<endl<<endl;
    cout<<"Pas de panique, l'action peut prendre quelques minute en fonction de la situation."<<endl<<endl<<endl<<endl;
    /*for(int i = 0; i<tours.size(); i++) {
        cout << tours[i] << endl;
    }*/
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
    string choixCoupMax="";
    string choixCoupMin="";
    string tour={};
    do{
        int gain=0;
        //jouerCoup(PlateauJoueur &j,PlateauCentral &m,string coup);
        Noeud configFils = toutesConfigFils.back();
        tour = tours.back();
        for(int j=0; j<20; j++){
            //cout<<""<<j<<endl;
            gain += simulationNFindeTour(2,configFils);

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
        tours.pop_back();
    }while(toutesConfigFils.size()>0);

    PlateauJoueur j = partie.getJoueur(1);
    PlateauCentral m = partie.getMarche();
    int pos = 0;
    choixCoupMax += ",";
    choixCoupMin += ",";
    cout<<"Merci de votre patience. Le meilleur coup est :"<<endl;
    string meilleurCoup;
    while ((pos = choixCoupMax.find(',')) != string::npos) {
        string coup = choixCoupMax.substr(0, pos);
        meilleurCoup += significationCoup(j,m,coup);
        choixCoupMax.erase(0, pos + 1);
    }
    cout<<meilleurCoup<<endl;
    cout<<"Taux de victoire : "<<Max<<"/20"<<endl;

    cout<<endl<<"Et le pire coup est :"<<endl;
    string pireCoup;
    while ((pos = choixCoupMin.find(',')) != string::npos) {
        string coup = choixCoupMin.substr(0, pos);
        pireCoup += significationCoup(j,m,coup);
        choixCoupMin.erase(0, pos + 1);
    }
    cout<<pireCoup<<endl;
    cout<<"Taux de victoire : "<<Min<<"/20"<<endl;
    cout<<endl;
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
                                        string ouvrier1;
                                        string ouvrier2;
                                        int ouvrier =0;
                                        if (de1[j].find("pl")!=string::npos){
                                            ouvrier1 =de1[j].substr(de1[j].find("pl"),5);
                                        }
                                        else if (de1[j].find("mo")!=string::npos){
                                            ouvrier1 =de1[j].substr(de1[j].find("mo"),6);
                                        }
                                        if (de2[k].find("pl")!=string::npos){
                                            ouvrier2 =de2[k].substr(de2[k].find("pl"),5);
                                        }
                                        else if (de2[k].find("mo")!=string::npos){
                                            ouvrier2 =de2[k].substr(de2[k].find("mo"),6);
                                        }
                                        ouvrier += verifValeur(ouvrier1);
                                        ouvrier += verifValeur(ouvrier2);
                                        if(ouvrier <= configActuel.getJoueur(id).getOuvrier()){
                                            string coup = autre[i]+","+de1[j]+","+de2[k];
                                            tour.push_back(coup);
                                        }
                                        else{
                                            string coup = autre[i]+","+de1[j]+","+de2[k];
                                            //cout<<coup<<endl;
                                        }
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
                                            string ouvrier1;
                                        string ouvrier2;
                                        int ouvrier =0;
                                        if (de1[j].find("pl")!=string::npos){
                                            ouvrier1 =de1[j].substr(de1[j].find("pl"),5);
                                        }
                                        else if (de1[j].find("mo")!=string::npos){
                                            ouvrier1 =de1[j].substr(de1[j].find("mo"),6);
                                        }
                                        if (de2[k].find("pl")!=string::npos){
                                            ouvrier2 =de2[k].substr(de2[k].find("pl"),5);
                                        }
                                        else if (de2[k].find("mo")!=string::npos){
                                            ouvrier2 =de2[k].substr(de2[k].find("mo"),6);
                                        }
                                        ouvrier += verifValeur(ouvrier1);
                                        ouvrier += verifValeur(ouvrier2);
                                        if(ouvrier <= configActuel.getJoueur(id).getOuvrier()){
                                            string coup = autre[i]+","+de1[j]+","+de2[k];
                                            //cout<<"valide : "<<coup<<endl;
                                            tour.push_back(coup);
                                        }
                                        else{
                                            string coup = autre[i]+","+de1[j]+","+de2[k];
                                            //cout<<"refus : "<<coup<<endl;
                                        }
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
                                            string ouvrier1;
                                        string ouvrier2;
                                        int ouvrier =0;
                                        if (de1[j].find("pl")!=string::npos){
                                            ouvrier1 =de1[j].substr(de1[j].find("pl"),5);
                                        }
                                        else if (de1[j].find("mo")!=string::npos){
                                            ouvrier1 =de1[j].substr(de1[j].find("mo"),6);
                                        }
                                        if (de2[k].find("pl")!=string::npos){
                                            ouvrier2 =de2[k].substr(de2[k].find("pl"),5);
                                        }
                                        else if (de2[k].find("mo")!=string::npos){
                                            ouvrier2 =de2[k].substr(de2[k].find("mo"),6);
                                        }
                                        ouvrier += verifValeur(ouvrier1);
                                        ouvrier += verifValeur(ouvrier2);
                                        if(ouvrier <= configActuel.getJoueur(id).getOuvrier()){
                                            string coup = autre[i]+","+de1[j]+","+de2[k];
                                            //cout<<"valide : "<<coup<<endl;
                                            tour.push_back(coup);
                                        }
                                        else{
                                            string coup = autre[i]+","+de1[j]+","+de2[k];
                                            //cout<<"refus : "<<coup<<endl;
                                        }
                                        }
                                    }
                                }
                                else if(de1[j].find("r")!=string::npos && de2[k].find("r")!=string::npos){
                                    string indice1 =de1[j].substr(de1[j].find("r")+1,de1[j].length());
                                    string indice2 =de2[k].substr(de2[k].find("r")+1,de2[k].length());
                                    indice1 = indice1[0];
                                    indice2 = indice2[0];
                                    if(indice1.compare(indice2)!= 0){
                                        string ouvrier1;
                                        string ouvrier2;
                                        int ouvrier =0;
                                        if (de1[j].find("pl")!=string::npos){
                                            ouvrier1 =de1[j].substr(de1[j].find("pl"),5);
                                        }
                                        else if (de1[j].find("mo")!=string::npos){
                                            ouvrier1 =de1[j].substr(de1[j].find("mo"),6);
                                        }
                                        if (de2[k].find("pl")!=string::npos){
                                            ouvrier2 =de2[k].substr(de2[k].find("pl"),5);
                                        }
                                        else if (de2[k].find("mo")!=string::npos){
                                            ouvrier2 =de2[k].substr(de2[k].find("mo"),6);
                                        }
                                        ouvrier += verifValeur(ouvrier1);
                                        ouvrier += verifValeur(ouvrier2);
                                        if(ouvrier <= configActuel.getJoueur(id).getOuvrier()){
                                            string coup = autre[i]+","+de1[j]+","+de2[k];
                                            //cout<<"valide : "<<coup<<endl;
                                            tour.push_back(coup);
                                        }
                                        else{
                                            string coup = autre[i]+","+de1[j]+","+de2[k];
                                            //cout<<"refus : "<<coup<<endl;
                                        }
                                    }
                                }
                                else{
                                    string ouvrier1;
                                        string ouvrier2;
                                        int ouvrier =0;
                                        if (de1[j].find("pl")!=string::npos){
                                            ouvrier1 =de1[j].substr(de1[j].find("pl"),5);
                                        }
                                        else if (de1[j].find("mo")!=string::npos){
                                            ouvrier1 =de1[j].substr(de1[j].find("mo"),6);
                                        }
                                        if (de2[k].find("pl")!=string::npos){
                                            ouvrier2 =de2[k].substr(de2[k].find("pl"),5);
                                        }
                                        else if (de2[k].find("mo")!=string::npos){
                                            ouvrier2 =de2[k].substr(de2[k].find("mo"),6);
                                        }
                                        ouvrier += verifValeur(ouvrier1);
                                        ouvrier += verifValeur(ouvrier2);
                                        if(ouvrier <= configActuel.getJoueur(id).getOuvrier()){
                                            string coup = autre[i]+","+de1[j]+","+de2[k];
                                            //cout<<"valide : "<<coup<<endl;
                                            tour.push_back(coup);
                                        }
                                        else{
                                            string coup = autre[i]+","+de1[j]+","+de2[k];
                                            //cout<<"refus : "<<coup<<endl;
                                        }
                                }
                            }
                            else{
                                string ouvrier1;
                                        string ouvrier2;
                                        int ouvrier =0;
                                        if (de1[j].find("pl")!=string::npos){
                                            ouvrier1 =de1[j].substr(de1[j].find("pl"),5);
                                        }
                                        else if (de1[j].find("mo")!=string::npos){
                                            ouvrier1 =de1[j].substr(de1[j].find("mo"),6);
                                        }
                                        if (de2[k].find("pl")!=string::npos){
                                            ouvrier2 =de2[k].substr(de2[k].find("pl"),5);
                                        }
                                        else if (de2[k].find("mo")!=string::npos){
                                            ouvrier2 =de2[k].substr(de2[k].find("mo"),6);
                                        }
                                        ouvrier += verifValeur(ouvrier1);
                                        ouvrier += verifValeur(ouvrier2);
                                        if(ouvrier <= configActuel.getJoueur(id).getOuvrier()){
                                            string coup = autre[i]+","+de1[j]+","+de2[k];
                                            //cout<<"valide : "<<coup<<endl;
                                            tour.push_back(coup);
                                        }
                                        else{
                                            string coup = autre[i]+","+de1[j]+","+de2[k];
                                            //cout<<"refus : "<<coup<<endl;
                                        }
                            }
                    }
            }

            for(int j = 0; j<de2.size(); j++) {
                    for(int k = 0; k<de1.size(); k++) {
                          if (de1[k].find("t")!=string::npos && de2[j].find("t")!=string::npos){
                                string tuile1 =de1[k].substr(de1[k].find("t"),de1[k].length());
                                string tuile2 =de2[j].substr(de2[j].find("t"),de2[j].length());
                                if(tuile1.compare(tuile2)!=0){
                                        string ouvrier1;
                                        string ouvrier2;
                                        int ouvrier =0;
                                        if (de1[k].find("pl")!=string::npos){
                                            ouvrier1 =de1[k].substr(de1[k].find("pl"),5);
                                        }
                                        else if (de1[k].find("mo")!=string::npos){
                                            ouvrier1 =de1[k].substr(de1[k].find("mo"),6);
                                        }
                                        if (de2[j].find("pl")!=string::npos){
                                            ouvrier2 =de2[j].substr(de2[j].find("pl"),5);
                                        }
                                        else if (de2[j].find("mo")!=string::npos){
                                            ouvrier2 =de2[j].substr(de2[j].find("mo"),6);
                                        }
                                        ouvrier += verifValeur(ouvrier1);
                                        ouvrier += verifValeur(ouvrier2);
                                        if(ouvrier <= configActuel.getJoueur(id).getOuvrier()){
                                            string coup = autre[i]+","+de2[j]+","+de1[k];
                                            //cout<<"valide : "<<coup<<endl;
                                            tour.push_back(coup);
                                        }
                                        else{
                                            string coup = autre[i]+","+de2[j]+","+de1[k];
                                            //cout<<"refus : "<<coup<<endl;
                                        }
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
                                            string ouvrier1;
                                        string ouvrier2;
                                        int ouvrier =0;
                                        if (de1[k].find("pl")!=string::npos){
                                            ouvrier1 =de1[k].substr(de1[k].find("pl"),5);
                                        }
                                        else if (de1[k].find("mo")!=string::npos){
                                            ouvrier1 =de1[k].substr(de1[k].find("mo"),6);
                                        }
                                        if (de2[j].find("pl")!=string::npos){
                                            ouvrier2 =de2[j].substr(de2[j].find("pl"),5);
                                        }
                                        else if (de2[j].find("mo")!=string::npos){
                                            ouvrier2 =de2[j].substr(de2[j].find("mo"),6);
                                        }
                                        ouvrier += verifValeur(ouvrier1);
                                        ouvrier += verifValeur(ouvrier2);
                                        if(ouvrier <= configActuel.getJoueur(id).getOuvrier()){
                                            string coup = autre[i]+","+de2[j]+","+de1[k];
                                            //cout<<"valide : "<<coup<<endl;
                                            tour.push_back(coup);
                                        }
                                        else{
                                            string coup = autre[i]+","+de2[j]+","+de1[k];
                                            //cout<<"refus : "<<coup<<endl;
                                        }
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
                                            string ouvrier1;
                                        string ouvrier2;
                                        int ouvrier =0;
                                        if (de1[k].find("pl")!=string::npos){
                                            ouvrier1 =de1[k].substr(de1[k].find("pl"),5);
                                        }
                                        else if (de1[k].find("mo")!=string::npos){
                                            ouvrier1 =de1[k].substr(de1[k].find("mo"),6);
                                        }
                                        if (de2[j].find("pl")!=string::npos){
                                            ouvrier2 =de2[j].substr(de2[j].find("pl"),5);
                                        }
                                        else if (de2[j].find("mo")!=string::npos){
                                            ouvrier2 =de2[j].substr(de2[j].find("mo"),6);
                                        }
                                        ouvrier += verifValeur(ouvrier1);
                                        ouvrier += verifValeur(ouvrier2);
                                        if(ouvrier <= configActuel.getJoueur(id).getOuvrier()){
                                            string coup = autre[i]+","+de2[j]+","+de1[k];
                                            //cout<<"valide : "<<coup<<endl;
                                            tour.push_back(coup);
                                        }
                                        else{
                                            string coup = autre[i]+","+de2[j]+","+de1[k];
                                            //cout<<"refus : "<<coup<<endl;
                                        }
                                        }
                                    }
                                }
                                else{
                                    string ouvrier1;
                                        string ouvrier2;
                                        int ouvrier =0;
                                        if (de1[k].find("pl")!=string::npos){
                                            ouvrier1 =de1[k].substr(de1[k].find("pl"),5);
                                        }
                                        else if (de1[k].find("mo")!=string::npos){
                                            ouvrier1 =de1[k].substr(de1[k].find("mo"),6);
                                        }
                                        if (de2[j].find("pl")!=string::npos){
                                            ouvrier2 =de2[j].substr(de2[j].find("pl"),5);
                                        }
                                        else if (de2[j].find("mo")!=string::npos){
                                            ouvrier2 =de2[j].substr(de2[j].find("mo"),6);
                                        }
                                        ouvrier += verifValeur(ouvrier1);
                                        ouvrier += verifValeur(ouvrier2);
                                        if(ouvrier <= configActuel.getJoueur(id).getOuvrier()){
                                            string coup = autre[i]+","+de2[j]+","+de1[k];
                                            //cout<<"valide : "<<coup<<endl;
                                            tour.push_back(coup);
                                        }
                                        else{
                                            string coup = autre[i]+","+de2[j]+","+de1[k];
                                            //cout<<"refus : "<<coup<<endl;
                                        }
                                }
                            }
                            else{
                                string ouvrier1;
                                        string ouvrier2;
                                        int ouvrier =0;
                                        if (de1[k].find("pl")!=string::npos){
                                            ouvrier1 =de1[k].substr(de1[k].find("pl"),5);
                                        }
                                        else if (de1[k].find("mo")!=string::npos){
                                            ouvrier1 =de1[k].substr(de1[k].find("mo"),6);
                                        }
                                        if (de2[j].find("pl")!=string::npos){
                                            ouvrier2 =de2[j].substr(de2[j].find("pl"),5);
                                        }
                                        else if (de2[j].find("mo")!=string::npos){
                                            ouvrier2 =de2[j].substr(de2[j].find("mo"),6);
                                        }
                                        ouvrier += verifValeur(ouvrier1);
                                        ouvrier += verifValeur(ouvrier2);
                                        if(ouvrier <= configActuel.getJoueur(id).getOuvrier()){
                                            string coup = autre[i]+","+de2[j]+","+de1[k];
                                            //cout<<"valide : "<<coup<<endl;
                                            tour.push_back(coup);
                                        }
                                        else{
                                            string coup = autre[i]+","+de2[j]+","+de1[k];
                                            //cout<<"refus : "<<coup<<endl;
                                        }
                            }
                    }
            }
    }
    //cout<<"test"<<endl;
    return tour;
}

int IA::verifValeur(string s){
    if(s.compare("moins1")==0){
        return 1;
    }
    else if(s.compare("plus1")==0){
        return 1;
    }
    else if(s.compare("moins2")==0){
        return 2;
    }
    else if(s.compare("plus2")==0){
        return 2;
    }
    else if(s.compare("moins3")==0){
        return 3;
    }
    else if(s.compare("plus3")==0){
        return 3;
    }
    return 0;
}

int IA::simulationNFindeTour(int id, Noeud configFils){
    int victoire=0;
    //Partie configActuel = Partie(simulateur.copieJoueur(configFils.getJoueur(1)),simulateur.copieJoueur(configFils.getJoueur(2)),simulateur.copieMarche(configFils.getMarche()));
    Noeud configActuel(configFils.getJoueur(1),configFils.getJoueur(2),configFils.getMarche());
    PlateauJoueur test1;
    bool tourIA =false;
    while(configActuel.getMarche().getPhase()<6){
        if(!tourIA){
            if(id == 1){
                test1 = configActuel.getJoueur(id);
            }
            if(id == 2){
                test1 = configActuel.getJoueur(id);
            }
        }
        if(tourIA){
            if(id == 1){
                test1 = configActuel.getJoueur(id+1);
            }
            if(id == 2){
                test1 = configActuel.getJoueur(id-1);
            }
        }
        //on joue aléatoirement
        int r1=(rand()%6)+1;
        int r2=(rand()%6)+1;
        test1.setde(1,r1);
        test1.setde(2,r2);
        if(!tourIA){
            if(id == 1){
                configActuel.setJoueur(test1,id);
                vector<string> tours1 = createListeTourPossible(id, configActuel);
                configActuel = coupAleatoire(tours1,configActuel.getJoueur(1),configActuel.getJoueur(2),id,configActuel.getMarche());
            }
            if(id == 2){
                configActuel.setJoueur(test1,id);
                vector<string> tours1 = createListeTourPossible(id, configActuel);
                configActuel = coupAleatoire(tours1,configActuel.getJoueur(1),configActuel.getJoueur(2),id,configActuel.getMarche());
            }

        }
        if(tourIA){
            if(id == 1){
                configActuel.setJoueur(test1,id+1);
                vector<string> tours1 = createListeTourPossible(id+1, configActuel);
                configActuel = coupAleatoire(tours1,configActuel.getJoueur(1),configActuel.getJoueur(2),id+1,configActuel.getMarche());
            }
            if(id == 2){
                configActuel.setJoueur(test1,id-1);
                vector<string> tours1 = createListeTourPossible(id-1, configActuel);
                configActuel = coupAleatoire(tours1,configActuel.getJoueur(1),configActuel.getJoueur(2),id-1,configActuel.getMarche());
            }
        }


        if(!tourIA){
            PlateauCentral marche;
            PlateauJoueur J1;
            PlateauJoueur J2;
            J1 = configActuel.getJoueur(1);
            J2 = configActuel.getJoueur(2);
            marche = configActuel.getMarche();
            simulateur.finDeTour(marche,J1,J2);
            configActuel.setJoueur(J1,1);
            configActuel.setJoueur(J2,2);
            configActuel.setMarche(marche);
            tourIA=true;
        }
        if(tourIA)tourIA=false;
    }
    //score final
    PlateauJoueur J1;
    PlateauJoueur J2;
    J1 = configActuel.getJoueur(1);
    J2 = configActuel.getJoueur(2);
    simulateur.scoreFinal(J1);
    simulateur.scoreFinal(J2);
    configActuel.setJoueur(J1,1);
    configActuel.setJoueur(J2,2);
    if(id==1){
        if(configActuel.getJoueur(1).getScore()<configActuel.getJoueur(2).getScore()){
            victoire=1;
        }
    }
    else{
        if(configActuel.getJoueur(1).getScore()>configActuel.getJoueur(2).getScore()){
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

string IA::significationCoup(PlateauJoueur &j, PlateauCentral &m, string coup){
    string res = "";

            if(coup.compare("0a") == 0){
                res += "N'utilisez pas vos pepites,";
            }
            else if(coup.compare("p0") == 0){
                res += "Achetez la case du haut du marché noir,";
            }
            else if(coup.compare("p1") == 0){
                res += "Achetez la case de droite du marché noir,";
            }
            else if(coup.compare("p2") == 0){
                res += "Achetez la case du bas du marché noir,";
            }
            else if(coup.compare("p3") == 0){
                res += "Achetez la case de gauche du marché noir,";
            }
            else if(coup.compare("vendMde1") == 0){
                res += "vendez la pile de marchandise de votre de 1,";
            }
            else if(coup.compare("vendMde1plus1") == 0){
                res += "vendez la pile de marchandise de votre de 1 en y enlevant 1,";
            }
            else if(coup.compare("vendMde1moins1") == 0){
                res += "vendez la pile de marchandise de votre de 1 en y ajoutant 1,";
            }
            else if(coup.compare("vendMde1plus2") == 0){
                res += "vendez la pile de marchandise de votre de 1 en y ajoutant 2,";
            }
            else if(coup.compare("vendMde1moins2") == 0){
                res += "vendez la pile de marchandise de votre de 1 en y enlevant 2,";
            }
            else if(coup.compare("vendMde1plus3") == 0){
                res += "vendez la pile de marchandise de votre de 1 en y ajoutant 3,";
            }
            else if(coup.compare("vendMde1moins3") == 0){
                res += "vendez la pile de marchandise de votre de 1 en y enlevant 3,";
            }
            else if(coup.compare("vendMde2") == 0){
                res += "vendez la pile de marchandise de votre de 2,";
            }
            else if(coup.compare("vendMde2plus1") == 0){
                res += "vendez la pile de marchandise de votre de 2 en y ajoutant 1,";
            }
            else if(coup.compare("vendMde2moins1") == 0){
                res += "vendez la pile de marchandise de votre de 2 en y enlevant 1,";
            }
            else if(coup.compare("vendMde2plus2") == 0){
                res += "vendez la pile de marchandise de votre de 2 en y ajoutant 2,";
            }
            else if(coup.compare("vendMde2moins2") == 0){
                res += "vendez la pile de marchandise de votre de 2 en y enlevant 2,";
            }
            else if(coup.compare("vendMde2plus3") == 0){
                res += "vendez la pile de marchandise de votre de 2 en y ajoutant 3,";
            }
            else if(coup.compare("vendMde2moins3") == 0){
                res += "vendez la pile de marchandise de votre de 2 en y enlevant 3,";
            }
            else if(coup.compare("vend_de1") == 0){
                res += "sacrifiez votre de 1 pour 2 ouvriers,";
            }
            else if(coup.compare("vend_de2") == 0){
                res += "sacrifiez votre de 2 pour 2 ouvriers,";
            }
            else{
                string diff = coup.substr(0,3);
                if(diff.compare("de1") == 0){
                    coup.erase(0, 3);
                    if(coup.find("a0")!=string::npos){
                        coup.erase(0, 2);
                        if(m.getTuileMarche(modifValeurDe(j.getde(1)-1),6).compare(coup)==0){
                            string c = afficherCase(coup);
                            res += "avec votre de 1 achetez la case " + c + " de la zone correspondante,";
                        }
                        else if(m.getTuileMarche(modifValeurDe(j.getde(1)-1),7).compare(coup)==0){
                            string c = afficherCase(coup);
                            res += "avec votre de 1 achetez la case " + c + " de la zone correspondante,";
                        }
                    }
                    else if(coup.find("aplus1")!=string::npos){
                        coup.erase(0, 6);
                        if(m.getTuileMarche(modifValeurDe(j.getde(1)-1),6).compare(coup)==0){
                            string c = afficherCase(coup);
                            res += "avec votre de 1 achetez la case " + c + " de la zone correspondante,";
                        }
                        else if(m.getTuileMarche(modifValeurDe(j.getde(1)-1),7).compare(coup)==0){
                            string c = afficherCase(coup);
                            res += "avec votre de 1 achetez la case " + c + " de la zone correspondante,";
                        }
                    }
                    else if(coup.find("amoins1")!=string::npos){
                        coup.erase(0, 7);
                        if(m.getTuileMarche(modifValeurDe(j.getde(1)-1),6).compare(coup)==0){
                            string c = afficherCase(coup);
                            res += "avec votre de 1 achetez la case " + c + " de la zone correspondante,";
                        }
                        else if(m.getTuileMarche(modifValeurDe(j.getde(1)-1),7).compare(coup)==0){
                            string c = afficherCase(coup);
                            res += "avec votre de 1 achetez la case " + c + " de la zone correspondante,";
                        }
                    }
                    else if(coup.find("aplus2")!=string::npos){
                        coup.erase(0, 6);
                        if(m.getTuileMarche(modifValeurDe(j.getde(1)-1),6).compare(coup)==0){
                            string c = afficherCase(coup);
                            res += "avec votre de 1 achetez la case " + c + " de la zone correspondante,";
                        }
                        else if(m.getTuileMarche(modifValeurDe(j.getde(1)-1),7).compare(coup)==0){
                            string c = afficherCase(coup);
                            res += "avec votre de 1 achetez la case " + c + " de la zone correspondante,";
                        }
                    }
                    else if(coup.find("amoins2")!=string::npos){;
                        coup.erase(0, 7);
                        if(m.getTuileMarche(modifValeurDe(j.getde(1))-1,6).compare(coup)==0){
                            string c = afficherCase(coup);
                            res += "avec votre de 1 achetez la case " + c + " de la zone correspondante,";
                        }
                        else if(m.getTuileMarche(modifValeurDe(j.getde(1)-1),7).compare(coup)==0){
                            string c = afficherCase(coup);
                            res += "avec votre de 1 achetez la case " + c + " de la zone correspondante,";
                        }
                    }
                    else if(coup.find("aplus3")!=string::npos){
                        coup.erase(0, 6);
                        if(m.getTuileMarche(modifValeurDe(j.getde(1)-1),6).compare(coup)==0){
                            string c = afficherCase(coup);
                            res += "avec votre de 1 achetez la case " + c + " de la zone correspondante,";
                        }
                        else if(m.getTuileMarche(modifValeurDe(j.getde(1)-1),7).compare(coup)==0){
                            string c = afficherCase(coup);
                            res += "avec votre de 1 achetez la case " + c + " de la zone correspondante,";
                        }
                    }
                    else if(coup.find("amoins3")!=string::npos){
                        coup.erase(0, 7);
                        if(m.getTuileMarche(modifValeurDe(j.getde(1)-1),6).compare(coup)==0){
                            string c = afficherCase(coup);
                            res += "avec votre de 1 achetez la case " + c + " de la zone correspondante,";
                        }
                        else if(m.getTuileMarche(modifValeurDe(j.getde(1)-1),7).compare(coup)==0){
                            string c = afficherCase(coup);
                            res += "avec votre de 1 achetez la case " + c + " de la zone correspondante,";
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
                        res += "avec votre de 1 posez la tuile en reserve a l'indice " + sReserve + " sur la case " + coup + ",";
                    }
                    else if(coup.find("pplus1")!=string::npos){
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
                        res += "avec votre de 1 plus 1 posez la tuile en reserve a l'indice " + sReserve + " sur la case " + coup + ",";
                    }
                    else if(coup.find("pmoins1")!=string::npos){
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
                        res += "avec votre de 1 moins 1 posez la tuile en reserve a l'indice " + sReserve + " sur la case " + coup + ",";
                    }
                    else if(coup.find("pplus2")!=string::npos){
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
                        res += "avec votre de 1 plus 3 posez la tuile en reserve a l'indice " + sReserve + " sur la case " + coup + ",";
                    }
                    else if(coup.find("pmoins2")!=string::npos){
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
                        res += "avec votre de 1 moins 2 posez la tuile en reserve a l'indice " + sReserve + " sur la case " + coup + ",";
                    }
                    else if(coup.find("pplus3")!=string::npos){
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
                        res += "avec votre de 1 plus 3 posez la tuile en reserve a l'indice " + sReserve + " sur la case " + coup + ",";
                    }
                    else if(coup.find("pmoins3")!=string::npos){
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
                        res += "avec votre de 1 moins 3 posez la tuile en reserve a l'indice " + sReserve + " sur la case " + coup + ",";
                    }
                    else{
                        //cout<<coup<<endl;
                    }
                }
                else if(diff.compare("de2") == 0){
                    coup.erase(0, 3);
                    if(coup.find("a0")!=string::npos){
                        coup.erase(0, 2);
                        if(m.getTuileMarche(modifValeurDe(j.getde(2)-1),6).compare(coup)==0){
                            string c = afficherCase(coup);
                            res += "avec votre de 1 achetez la case " + c + " de la zone correspondante,";
                        }
                        else if(m.getTuileMarche(modifValeurDe(j.getde(2)-1),7).compare(coup)==0){
                            string c = afficherCase(coup);
                            res += "avec votre de 1 achetez la case " + c + " de la zone correspondante,";
                        }
                    }
                    else if(coup.find("aplus1")!=string::npos){
                        coup.erase(0, 6);
                        if(m.getTuileMarche(modifValeurDe(j.getde(2)-1),6).compare(coup)==0){
                            string c = afficherCase(coup);
                            res += "avec votre de 1 achetez la case " + c + " de la zone correspondante,";
                        }
                        else if(m.getTuileMarche(modifValeurDe(j.getde(2)-1),7).compare(coup)==0){
                            string c = afficherCase(coup);
                            res += "avec votre de 1 achetez la case " + c + " de la zone correspondante,";
                        }
                    }
                    else if(coup.find("amoins1")!=string::npos){
                        coup.erase(0, 7);
                        if(m.getTuileMarche(modifValeurDe(j.getde(2)-1),6).compare(coup)==0){
                            string c = afficherCase(coup);
                            res += "avec votre de 1 achetez la case " + c + " de la zone correspondante,";
                        }
                        else if(m.getTuileMarche(modifValeurDe(j.getde(2)-1),7).compare(coup)==0){
                            string c = afficherCase(coup);
                            res += "avec votre de 1 achetez la case " + c + " de la zone correspondante,";
                        }
                    }
                    else if(coup.find("aplus2")!=string::npos){
                        coup.erase(0, 6);
                        if(m.getTuileMarche(modifValeurDe(j.getde(2)-1),6).compare(coup)==0){
                            string c = afficherCase(coup);
                            res += "avec votre de 1 achetez la case " + c + " de la zone correspondante,";
                        }
                        else if(m.getTuileMarche(modifValeurDe(j.getde(2)-1),7).compare(coup)==0){
                            string c = afficherCase(coup);
                            res += "avec votre de 1 achetez la case " + c + " de la zone correspondante,";
                        }
                    }
                    else if(coup.find("amoins2")!=string::npos){
                        coup.erase(0, 7);
                        if(m.getTuileMarche(modifValeurDe(j.getde(2)-1),6).compare(coup)==0){
                            string c = afficherCase(coup);
                            res += "avec votre de 1 achetez la case " + c + " de la zone correspondante,";
                        }
                        else if(m.getTuileMarche(modifValeurDe(j.getde(2)-1),7).compare(coup)==0){
                            string c = afficherCase(coup);
                            res += "avec votre de 1 achetez la case " + c + " de la zone correspondante,";
                        }
                    }
                    else if(coup.find("aplus3")!=string::npos){
                        coup.erase(0, 6);
                        if(m.getTuileMarche(modifValeurDe(j.getde(2)-1),6).compare(coup)==0){
                            string c = afficherCase(coup);
                            res += "avec votre de 1 achetez la case " + c + " de la zone correspondante,";
                        }
                        else if(m.getTuileMarche(modifValeurDe(j.getde(2)-1),7).compare(coup)==0){
                            string c = afficherCase(coup);
                            res += "avec votre de 1 achetez la case " + c + " de la zone correspondante,";
                        }
                    }
                    else if(coup.find("amoins3")!=string::npos){
                        coup.erase(0, 7);
                        if(m.getTuileMarche(modifValeurDe(j.getde(2)-1),6).compare(coup)==0){
                            string c = afficherCase(coup);
                            res += "avec votre de 1 achetez la case " + c + " de la zone correspondante,";
                        }
                        else if(m.getTuileMarche(modifValeurDe(j.getde(2)-1),7).compare(coup)==0){
                            string c = afficherCase(coup);
                            res += "avec votre de 1 achetez la case " + c + " de la zone correspondante,";
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
                        res += "avec votre de 2 posez la tuile en reserve a l'indice " + sReserve + " sur la case " + coup + ",";
                    }
                    else if(coup.find("pplus1")!=string::npos){
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
                        res += "avec votre de 2 plus 1 posez la tuile en reserve a l'indice " + sReserve + " sur la case " + coup + ",";
                    }
                    else if(coup.find("pmoins1")!=string::npos){
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
                        res += "avec votre de 2 moins 1 posez la tuile en reserve a l'indice " + sReserve + " sur la case " + coup + ",";
                    }
                    else if(coup.find("pplus2")!=string::npos){
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
                        res += "avec votre de 2 plus 2 posez la tuile en reserve a l'indice " + sReserve + " sur la case " + coup + ",";
                    }
                    else if(coup.find("pmoins2")!=string::npos){
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
                        res += "avec votre de 2 moins 2 posez la tuile en reserve a l'indice " + sReserve + " sur la case " + coup + ",";
                    }
                    else if(coup.find("pplus3")!=string::npos){
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
                        res += "avec votre de 2 plus 3 posez la tuile en reserve a l'indice " + sReserve + " sur la case " + coup + ", ";
                    }
                    else if(coup.find("pmoins3")!=string::npos){
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
                        res += "avec votre de 2 moins 3 posez la tuile en reserve a l'indice " + sReserve + " sur la case " + coup + ",";
                    }
                    else{
                    }
                }
                else{
                }
            }
    return res;
}


std::string IA::afficherCase( std::string c ){
    if(c=="ts")return"Navire Normale";
    else if(c=="tsb")return"Navire Noire";
    else if(c=="tb1")return"Entrepot";
    else if(c=="tb1b")return"Entrepot(Noire)";
    else if(c=="tb2")return"Atelier de menuiserie";
    else if(c=="tb2b")return"Atelier de menuiserie(Noire)";
    else if(c=="tb3")return"Eglise";
	else if(c=="tb3b")return"Eglise(Noire)";
    else if(c=="tb4")return"Marche";
	else if(c=="tb4b")return"Marche(Noire)";
    else if(c=="tb5")return"Pension";
    else if(c=="tb5b")return"Pension (Noire)";
	else if(c=="tb6")return"Banque";
    else if(c=="tb6b")return"Banque (Noire)";
    else if(c=="tb7")return"Hotel de ville";
    else if(c=="tb7b")return"Hotel de ville(Noire)";
    else if(c=="tb8")return"Tour de guet";
    else if(c=="tb8b")return"Tour de guet(Noire)";
    else if(c=="tm")return"Mine normale";
	else if(c=="tac2")return"2 cochon";
	else if(c=="tac3")return"3 cochon";
    else if(c=="tac4")return"4 cochon";
	else if(c=="tac3b")return"3 cochon(Noire)";
    else if(c=="tac4b")return"4 cochon(Noire)";
    else if(c=="tam2")return"2 mouton";
    else if(c=="tam3")return"3 mouton";
	else if(c=="tam4")return"4 mouton";
	else if(c=="tam3b")return"3 mouton(Noire)";
	else if(c=="tam4b")return"4 mouton(Noire)";
	else if(c=="tap2")return"2 poule";
    else if(c=="tap3")return"3 poule";
	else if(c=="tap4")return"4 poule";
    else if(c=="tap3b")return"3 poule(Noire)";
	else if(c=="tap4b")return"4 poule(Noire)";
	else if(c=="tav2")return"2 vache";
    else if(c=="tav3")return"3 vache";
    else if(c=="tav4")return"4 vache";
	else if(c=="tav3b")return"3 vache(Noire)";
    else if(c=="tav4b")return"4 vache(Noire)";
	else if(c=="tk1")return"Autorisation multi batiments dans chaque ville";
	else if(c=="tk2")return"Obtention ouvrier mine";
	else if(c=="tk3")return"Boost vente marchandise";
	else if(c=="tk4")return"Obtention ouvrier vente marchandise";
    else if(c=="tk5")return"Boost navires";
	else if(c=="tk6")return"Achat boostee";
	else if(c=="tk7b")return"Boost tuile animal(Noire)";
    else if(c=="tk8")return"Boost ouvrier";
    else if(c=="tk9")return"Boost ajustement batiments";
    else if(c=="tk10")return"Boost ajustement navires/animaux";
	else if(c=="tk11")return"Ajustement gratuit Chateau mine connaissance";
	else if(c=="tk12b")return"Ajustement gratuit Marche(Noire)";
	else if(c=="tk13")return"Obtention pepite vente de De";
    else if(c=="tk14b")return"Boost vente des De (Noire)";
	else if(c=="tk15b")return"3 point victoire par type marchandise vendu";
	else if(c=="tk16")return"Boost point victoire entrepot";
	else if(c=="tk17")return"Boost point victoire tour de guet";
	else if(c=="tk18")return"Boost point victoire atelier de menuiserie";
    else if(c=="tk19")return"Boost point victoire eglise";
    else if(c=="tk20")return"Boost point victoire marche";
	else if(c=="tk21")return"Boost point victoire pension";
    else if(c=="tk22")return"Boost point victoire banque";
    else if(c=="tk23")return"Boost point victoire hotel de ville";
	else if(c=="tk24b")return"Boost point victoire type animaux";
    else if(c=="tk25b")return"Boost point victoire marchandise vendu(Noire)";
    else if(c=="tk26")return"Boost point victoire tuile bonus";
    else if(c=="tc")return"Chateau normale";
    else if(c=="tcb")return"Chateau noire";
    else{return"";}
}
