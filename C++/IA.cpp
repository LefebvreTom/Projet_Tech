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
