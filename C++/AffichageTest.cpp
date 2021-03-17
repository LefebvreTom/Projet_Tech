#include "AffichageTest.h"

using namespace std;

AffichageTest::AffichageTest()
{
}


void AffichageTest::AffichageMarch(Marchandise march)
{
    cout<<"Marchandise couleur:"<<march.getCouleur()<<" id:"<<march.getIdCouleur()<<endl;

}
void AffichageTest::AffichageDe(De de)

{
    int resultatDe = de.getResultat();
    cout<<"resultat:"<<resultatDe<<endl;
}

void AffichageTest::AffichagePile(stack<Marchandise> Stack)
{

    Marchandise march = Stack.top();
    cout << "La pile contient " << Stack.size() << " marchandises de couleur : " << march.getCouleur();
}
