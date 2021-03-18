#include <iostream>
#include "De.h"
#include "Marchandise.h"
#include "affichageTest.h"
#include "Chateau.h"
#include "Bateau.h"
#include "Mine.h"

#include <time.h>
#include <stdlib.h>

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
    }

    //creation de marchandises pour montrer les attributs
    /*
    Marchandise tabMarchandise[6];
    for(int i=0;i<6;i++){
        tabMarchandise[i] = Marchandise(i+1);
        affichetest.AffichageMarch(tabMarchandise[i]);

    }
    */

    //creation d'une pile de marchandises de type 1
    /*
    Marchandise Stack;
    stack <Marchandise> testStack = Stack.initStackMarchandise(1);

    affichetest.AffichagePile(testStack);
    */

    //tableau regroupant les 6 stacks de marchandises
    stack <Marchandise> tabMarchandise[6];
    for(int i=0;i<6;i++){
        Marchandise Stack;
        stack <Marchandise> StackMarch = Stack.initStackMarchandise(i+1);
        tabMarchandise[i] = StackMarch;
        cout<<"tabMarchandise ("<<i<<"):"<<endl;
        affichetest.AffichagePileMarch(tabMarchandise[i]);

    }

    //pile de chateau
    Chateau StackChateau;
    stack <Chateau> StackCastle = StackChateau.initStackChateau();
    affichetest.AffichagePileChateau(StackCastle);

    //pile de bateau
    Bateau StackBateau;
    stack <Bateau> StackBoat = StackBateau.initStackBateau();
    affichetest.AffichagePileBateau(StackBoat);

    //pile de mines
    Mine StackMine;
    stack <Mine> StackMines = StackMine.initStackMine();
    affichetest.AffichagePileMine(StackMines);




//----------------------------------------------------------------------------------------

}
