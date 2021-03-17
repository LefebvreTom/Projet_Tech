#include <iostream>
#include "De.h"
#include "Marchandise.h"
#include "affichageTest.h"

#include <time.h>
#include <stdlib.h>

using namespace std;

int main()
{
    srand(time(NULL));





//----------------------------------------------------------------------------------------
    //section de test
    AffichageTest affichetest;

    De tabDe[10];
    for(int i=0;i<10;i++){
        tabDe[i]=De();
        affichetest.AffichageDe(tabDe[i]);
    }

    Marchandise tabMarchandise[6];
    for(int i=0;i<6;i++){
        tabMarchandise[i] = Marchandise(i+1);
        affichetest.AffichageMarch(tabMarchandise[i]);

    }

    Marchandise Stack;
    stack <Marchandise> testStack = Stack.initStackMarchandise(1);

    affichetest.AffichagePile(testStack);


}
