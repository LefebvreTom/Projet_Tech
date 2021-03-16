#include <iostream>
#include "De.h"
#include "Marchandise.h"

using namespace std;

int main()
{

    //section de test
    De test;
    int resultatDe = test.getResultat();
    cout<<"resultat:"<<resultatDe<<endl;

    Marchandise march1 = Marchandise(1);
    Marchandise march2 = Marchandise(2);
    Marchandise march3 = Marchandise(3);
    Marchandise march4 = Marchandise(4);
    Marchandise march5 = Marchandise(5);
    Marchandise march6 = Marchandise(6);

    cout<<"Marchandise bleu couleur:"<<march1.getCouleur()<<" id:"<<march1.getIdCouleur()<<endl;
    cout<<"Marchandise rouge couleur:"<<march4.getCouleur()<<" id:"<<march4.getIdCouleur()<<endl;
}
