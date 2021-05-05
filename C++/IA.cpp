#include "IA.h"

using namespace std;

IA :: IA(){
    partie.MajPlateauJoueur("J1");
    partie.MajPlateauJoueur("J2");
    simulateur = Simulateur();
};

IA :: ~IA(){}

void IA::Monte_Carlo(){
    while(partie.getMarche().getPhase() < 6){
            PlateauCentral test = partie.getMarche();
            simulateur.finDeTour(test);
            //cout<<"Phase : "<<test.getPhase()<<"Tour : "<<test.getTour() <<endl;
            partie.updatePhaseTourMarche(test);
    }
    cout<<partie.getJoueur(1).getNbMarchVendu(1)<<endl;
    cout<<"java"<<endl;
}
/*vector<string> IA::vecteurBranche(int id){
    vector<string> succ;

    //ACHAT Pépite
    succ.push_back("0a"); //on ne fait pas d'achat avec les pépites
    for(int i=0; i<4; i++){
        if(simulateur.testPepite(partie.getJoueur(id), partie.getMarche(), i)){ //si on peut acheter la case (elle est libre)
            //string s = "p" + string(i);
            succ.push_back("s");
        }
    }


    //Aucune modif ouvrier
        //vente marchandise
        if(simulateur.testVenteMarchandise(partie.getJoueur(id), partie.getJoueur(id).getde(1), partie.getMarche())){
            succ.push_back("venteMde1");
        }
        if(simulateur.testVenteMarchandise(partie.getJoueur(id), partie.getJoueur(id).getde(2), partie.getMarche())){
            succ.push_back("venteMde2");
        }
        //achat marche valeur case 1 et 2

        //poser une des cases
        //vendre le de
        succ.push_back("vend1");
        succ.push_back("vend2");
        //Modification ouvrier
    //+/- 1
    int de;
    if(partie.getJoueur(id).getOuvrier()>=1){
        //+1 dé1
        de = partie.getJoueur(id).getde(1) +1;
        if(simulateur.testVenteMarchandise(partie.getJoueur(id), de, partie.getMarche())){
            succ.push_back("venteMde1plus1");
        }

        //-1 dé1
        de = partie.getJoueur(id).getde(1) -1;
        if(simulateur.testVenteMarchandise(partie.getJoueur(id), de, partie.getMarche())){
            succ.push_back("venteMde1moins1");
        }

        //+1 dé2
        de = partie.getJoueur(id).getde(2) +1;
        if(simulateur.testVenteMarchandise(partie.getJoueur(id), de, partie.getMarche())){
            succ.push_back("venteMde2plus1");
        }

        //-1 dé2
        de = partie.getJoueur(id).getde(2) -1;
        if(simulateur.testVenteMarchandise(partie.getJoueur(id), de, partie.getMarche())){
            succ.push_back("venteMde2moins1");
        }

    }

    //+/- 2
    if(partie.getJoueur(id).getOuvrier()>=2){
        //+2 dé1
        de = partie.getJoueur(id).getde(1) +2;
        if(simulateur.testVenteMarchandise(partie.getJoueur(id), de, partie.getMarche())){
            succ.push_back("venteMde1plus2");
        }

        //-2 dé1
        de = partie.getJoueur(id).getde(1) -2;
        if(simulateur.testVenteMarchandise(partie.getJoueur(id), de, partie.getMarche())){
            succ.push_back("venteMde1moins2");
        }

        //+2 dé2
        de = partie.getJoueur(id).getde(2) +2;
        if(simulateur.testVenteMarchandise(partie.getJoueur(id), de, partie.getMarche())){
            succ.push_back("venteMde2plus2");
        }

        //-2 dé2
        de = partie.getJoueur(id).getde(2) -2;
        if(simulateur.testVenteMarchandise(partie.getJoueur(id), de, partie.getMarche())){
            succ.push_back("venteMde2moins2");
        }
    }
        //+/- 3
    if(partie.getJoueur(id).getOuvrier()>=3){
        //+3 dé1
        de = partie.getJoueur(id).getde(1) +3;
        if(simulateur.testVenteMarchandise(partie.getJoueur(id), de, partie.getMarche())){
            succ.push_back("venteMde1plus3");
        }

        //-3 dé1
        de = partie.getJoueur(id).getde(1) -3;
        if(simulateur.testVenteMarchandise(partie.getJoueur(id), de, partie.getMarche())){
            succ.push_back("venteMde1moins3");
        }

        //+3 dé2
        de = partie.getJoueur(id).getde(2) +3;
        if(simulateur.testVenteMarchandise(partie.getJoueur(id), de, partie.getMarche())){
            succ.push_back("venteMde2plus3");
        }

        //-3 dé2
        de = partie.getJoueur(id).getde(2) -3;
        if(simulateur.testVenteMarchandise(partie.getJoueur(id), de, partie.getMarche())){
            succ.push_back("venteMde2moins3");
        }

    }

    return succ;
}*/
