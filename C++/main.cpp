#include <iostream>
#include <string>
#include <stack>
#include <time.h>
#include <stdlib.h>
#include "Tuiles.h"
#include "De.h"
#include "Initialisation.h"
#include "affichageTest.h"


using namespace std;

int main()
{
    srand(time(NULL));

//----------------------------------------------------------------------------------------
    //section de test
    AffichageTest affichetest;

    //lancer de 10 dés pour voir si le random marche
    De tabDe[10];
    for(int i=0;i<10;i++){
        tabDe[i]=De();
        affichetest.AffichageDe(tabDe[i]);
        cout<<endl;
    }

    //Initialisation
    Initialisation init;
        cout<<endl;
        return 0;
}
