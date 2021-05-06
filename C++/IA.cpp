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

int IA::modifValeurDe(int de){
    int res = de%6;
    if(res==0){
        res=6;
    }
    return(res);
}



/*vector<string> IA::vecteurBranche(int id){
    vector<string> succ;

    //ACHAT Pépite
    succ.push_back("0a"); //on ne fait pas d'achat avec les pépites
    for(int i=0; i<4; i++){
        if(simulateur.testPepite(partie.getJoueur(id), partie.getMarche(), i)){ //si on peut acheter la case (elle est libre)
            string s = "p" + string(i);
            succ.push_back("s");
        }
    }


    //Aucune modif ouvrier
        //vente marchandise
        if(simulateur.testVenteMarchandise(partie.getJoueur(id), partie.getJoueur(id).getde(1), partie.getMarche())){
            succ.push_back("venteMde1"); //vente de la marchandise avec le dé 1
        }
        if(simulateur.testVenteMarchandise(partie.getJoueur(id), partie.getJoueur(id).getde(2), partie.getMarche())){
            succ.push_back("venteMde2"); //vente de la marchandise avec le dé 1
        }
        //achat marche valeur case 1 et 2
        if(partie.getMarche().getTuileMarche(partie.getJoueur(id).getde(1),6)!=""){
            succ.push_back("de1a0" + partie.getMarche().getTuileMarche(partie.getJoueur(id).getde(1),6)); //le dé 1 non modifié permet l'achat de la case 1
        }
        if(partie.getMarche().getTuileMarche(partie.getJoueur(id).getde(1),7)!=""){
            succ.push_back("de1a0" + partie.getMarche().getTuileMarche(partie.getJoueur(id).getde(1),7)); //le dé 1 non modifié permet l'achat de la case 2
        }
        if(partie.getMarche().getTuileMarche(partie.getJoueur(id).getde(2),6)!=""){
            succ.push_back("de2a0" + partie.getMarche().getTuileMarche(partie.getJoueur(id).getde(2),6)); //le dé 2 non modifié permet l'achat de la case 1
        }
        if(partie.getMarche().getTuileMarche(partie.getJoueur(id).getde(2),7)!=""){
            succ.push_back("de2a0" + partie.getMarche().getTuileMarche(partie.getJoueur(id).getde(2),7)); //le dé 2 non modifié permet l'achat de la case 2
        }
        //poser une des cases
        //vendre le de
        succ.push_back("vend1"); //vend le dé 1 pour 2 ouvriers
        succ.push_back("vend2"); //vend le dé 2 pour 2 ouvriers


        //Modification ouvrier
    //+/- 1
    int de;
    if(partie.getJoueur(id).getOuvrier()>=1){
        //+1 dé1
        de = partie.getJoueur(id).getde(1) +1;
        de = modifValeurDe(de);
        if(simulateur.testVenteMarchandise(partie.getJoueur(id), de, partie.getMarche())){
            succ.push_back("venteMde1plus1");
        }
        if(partie.getMarche().getTuileMarche(de,6)!=""){
            succ.push_back("de1aplus1" + partie.getMarche().getTuileMarche(de,6)); //le dé 1 +1 permet l'achat de la case 1
        }
        if(partie.getMarche().getTuileMarche(de,7)!=""){
            succ.push_back("de1aplus1" + partie.getMarche().getTuileMarche(de,7)); //le dé 1 +1 permet l'achat de la case 2
        }

        //-1 dé1
        de = partie.getJoueur(id).getde(1) -1;
        de = modifValeurDe(de);
        if(simulateur.testVenteMarchandise(partie.getJoueur(id), de, partie.getMarche())){
            succ.push_back("venteMde1moins1");
        }
        if(partie.getMarche().getTuileMarche(de,6)!=""){
            succ.push_back("de1amoins1" + partie.getMarche().getTuileMarche(de,6)); //le dé 1 -1 permet l'achat de la case 1
        }
        if(partie.getMarche().getTuileMarche(de,7)!=""){
            succ.push_back("de1amoins1" + partie.getMarche().getTuileMarche(de,7)); //le dé 1 -1 permet l'achat de la case 2
        }

        //+1 dé2
        de = partie.getJoueur(id).getde(2) +1;
        de = modifValeurDe(de);
        if(simulateur.testVenteMarchandise(partie.getJoueur(id), de, partie.getMarche())){
            succ.push_back("venteMde2plus1");
        }
        if(partie.getMarche().getTuileMarche(de,6)!=""){
            succ.push_back("de2aplus1" + partie.getMarche().getTuileMarche(de,6)); //le dé 2 +1 permet l'achat de la case 1
        }
        if(partie.getMarche().getTuileMarche(de,7)!=""){
            succ.push_back("de2aplus1" + partie.getMarche().getTuileMarche(de,7)); //le dé 2 +1 permet l'achat de la case 2
        }

        //-1 dé2
        de = partie.getJoueur(id).getde(2) -1;
        de = modifValeurDe(de);
        if(simulateur.testVenteMarchandise(partie.getJoueur(id), de, partie.getMarche())){
            succ.push_back("venteMde2moins1");
        }
        if(partie.getMarche().getTuileMarche(de,6)!=""){
            succ.push_back("de2amoins1" + partie.getMarche().getTuileMarche(de,6)); //le dé 2 -1 permet l'achat de la case 1
        }
        if(partie.getMarche().getTuileMarche(de,7)!=""){
            succ.push_back("de2amoins1" + partie.getMarche().getTuileMarche(de,7)); //le dé 2 -1 permet l'achat de la case 2
        }

    }

    //+/- 2
    if(partie.getJoueur(id).getOuvrier()>=2){
        //+2 dé1
        de = partie.getJoueur(id).getde(1) +2;
        de = modifValeurDe(de);
        if(simulateur.testVenteMarchandise(partie.getJoueur(id), de, partie.getMarche())){
            succ.push_back("venteMde1plus2");
        }
        if(partie.getMarche().getTuileMarche(de,6)!=""){
            succ.push_back("de1aplus2" + partie.getMarche().getTuileMarche(de,6)); //le dé 1 +2 permet l'achat de la case 1
        }
        if(partie.getMarche().getTuileMarche(de,7)!=""){
            succ.push_back("de1aplus2" + partie.getMarche().getTuileMarche(de,7)); //le dé 1 +2 permet l'achat de la case 2
        }

        //-2 dé1
        de = partie.getJoueur(id).getde(1) -2;
        de = modifValeurDe(de);
        if(simulateur.testVenteMarchandise(partie.getJoueur(id), de, partie.getMarche())){
            succ.push_back("venteMde1moins2");
        }
        if(partie.getMarche().getTuileMarche(de,6)!=""){
            succ.push_back("de1amoins2" + partie.getMarche().getTuileMarche(de,6)); //le dé 1 -2 permet l'achat de la case 1
        }
        if(partie.getMarche().getTuileMarche(de,7)!=""){
            succ.push_back("de1amoins2" + partie.getMarche().getTuileMarche(de,7)); //le dé 1 -2 permet l'achat de la case 2
        }

        //+2 dé2
        de = partie.getJoueur(id).getde(2) +2;
        de = modifValeurDe(de);
        if(simulateur.testVenteMarchandise(partie.getJoueur(id), de, partie.getMarche())){
            succ.push_back("venteMde2plus2");
        }
        if(partie.getMarche().getTuileMarche(de,6)!=""){
            succ.push_back("de2aplus2" + partie.getMarche().getTuileMarche(de,6)); //le dé 2 +2 permet l'achat de la case 1
        }
        if(partie.getMarche().getTuileMarche(de,7)!=""){
            succ.push_back("de2aplus2" + partie.getMarche().getTuileMarche(de,7)); //le dé 2 +2 permet l'achat de la case 2
        }

        //-2 dé2
        de = partie.getJoueur(id).getde(2) -2;
        de = modifValeurDe(de);
        if(simulateur.testVenteMarchandise(partie.getJoueur(id), de, partie.getMarche())){
            succ.push_back("venteMde2moins2");
        }
        if(partie.getMarche().getTuileMarche(de,6)!=""){
            succ.push_back("de2amoins2" + partie.getMarche().getTuileMarche(de,6)); //le dé 2 -2 permet l'achat de la case 1
        }
        if(partie.getMarche().getTuileMarche(de,7)!=""){
            succ.push_back("de2amoins2" + partie.getMarche().getTuileMarche(de,7)); //le dé 2 -2 permet l'achat de la case 2
        }
    }
        //+/- 3
    if(partie.getJoueur(id).getOuvrier()>=3){
        //+3 dé1
        de = partie.getJoueur(id).getde(1) +3;
        de = modifValeurDe(de);
        if(simulateur.testVenteMarchandise(partie.getJoueur(id), de, partie.getMarche())){
            succ.push_back("venteMde1plus3");
        }
        if(partie.getMarche().getTuileMarche(de,6)!=""){
            succ.push_back("de1aplus3" + partie.getMarche().getTuileMarche(de,6)); //le dé 1 +3 permet l'achat de la case 1
        }
        if(partie.getMarche().getTuileMarche(de,7)!=""){
            succ.push_back("de1aplus3" + partie.getMarche().getTuileMarche(de,7)); //le dé 1 +3 permet l'achat de la case 2
        }

        //-3 dé1
        de = partie.getJoueur(id).getde(1) -3;
        de = modifValeurDe(de);
        if(simulateur.testVenteMarchandise(partie.getJoueur(id), de, partie.getMarche())){
            succ.push_back("venteMde1moins3");
        }
        if(partie.getMarche().getTuileMarche(de,6)!=""){
            succ.push_back("de1amoins3" + partie.getMarche().getTuileMarche(de,6)); //le dé 1 -3 permet l'achat de la case 1
        }
        if(partie.getMarche().getTuileMarche(de,7)!=""){
            succ.push_back("de1amoins3" + partie.getMarche().getTuileMarche(de,7)); //le dé 1 -3 permet l'achat de la case 2
        }

        //+3 dé2
        de = partie.getJoueur(id).getde(2) +3;
        de = modifValeurDe(de);
        if(simulateur.testVenteMarchandise(partie.getJoueur(id), de, partie.getMarche())){
            succ.push_back("venteMde2plus3");
        }
        if(partie.getMarche().getTuileMarche(de,6)!=""){
            succ.push_back("de2aplus3" + partie.getMarche().getTuileMarche(de,6)); //le dé 2 +3 permet l'achat de la case 1
        }
        if(partie.getMarche().getTuileMarche(de,7)!=""){
            succ.push_back("de2aplus3" + partie.getMarche().getTuileMarche(de,7)); //le dé 2 +3 permet l'achat de la case 2
        }

        //-3 dé2
        de = partie.getJoueur(id).getde(2) -3;
        de = modifValeurDe(de);
        if(simulateur.testVenteMarchandise(partie.getJoueur(id), de, partie.getMarche())){
            succ.push_back("venteMde2moins3");
        }
        if(partie.getMarche().getTuileMarche(de,6)!=""){
            succ.push_back("de2amoins3" + partie.getMarche().getTuileMarche(de,6)); //le dé 2 -3 permet l'achat de la case 1
        }
        if(partie.getMarche().getTuileMarche(de,7)!=""){
            succ.push_back("de2amoins3" + partie.getMarche().getTuileMarche(de,7)); //le dé 2 -3 permet l'achat de la case 2
        }

    }

    return succ;
}*/
